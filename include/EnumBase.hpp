/* ux++ - ux implementation for C++ */

/* LICENSE - The MIT License (MIT)

Copyright (c) 2013 Tomona Nanase

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef ENUMBASE_HPP
#define	ENUMBASE_HPP

#include <unordered_map>
#include <string>
#include <algorithm>
#include <boost/lexical_cast.hpp>

namespace uxpp {

  class EnumBase {
  protected:

    // <editor-fold desc="-- Methods --">
    // <editor-fold desc="key_exists">

    template <typename X>
    static bool key_exists(
            const std::unordered_map<std::string, X> map,
            std::string key) {
      return key_exists(map, key, false);
    }

    template <typename X>
    static bool key_exists(
            const std::unordered_map<std::string, X> map,
            std::string key,
            bool ignoreCase) {
      if (ignoreCase)
        std::transform(key.begin(), key.end(), key.begin(), ::tolower);

      return map.count(key) != 0;
    }

    // <editor-fold desc="macro">
#define _key_exists_impl(T) \
    static bool key_exists(std::string key) { \
      return EnumBase::key_exists(T::map, key); \
    } \
\
    static bool key_exists(std::string key, bool ignoreCase) { \
      return EnumBase::key_exists(T::map, key, ignoreCase); \
    }
    // </editor-fold>
    // </editor-fold>

    // <editor-fold desc="value_exists">

    template <typename X>
    static bool value_exists(
            const std::unordered_map<std::string, X> map,
            int32_t value) {
      for (auto pair : map) {
        if ((int) pair.second == value)
          return true;
      }

      return false;
    }

    // <editor-fold desc="macro">
#define _value_exists_impl(T) \
    static bool value_exists(int32_t value) { \
      return EnumBase::value_exists(T::map, value); \
    } 
    // </editor-fold>
    // </editor-fold>

    // <editor-fold desc="toString">

    template <typename X>
    static std::string toString(
            const std::unordered_map<std::string, X> map,
            X value) {
      for (auto pair : map) {
        if (pair.second == value)
          return pair.first;
      }

      return "";
    }

    // <editor-fold desc="macro">
#define _toString_impl(T) \
    static std::string toString(T::values value) { \
      return EnumBase::toString(T::map, value); \
    } 
    // </editor-fold>
    // </editor-fold>

    // <editor-fold desc="tryParse">

    template <typename X>
    static bool tryParse(
            const std::unordered_map<std::string, X> map,
            std::string value,
            X* result) {
      return tryParse(map, value, result, false);
    }

    template <typename X>
    static bool tryParse(
            const std::unordered_map<std::string, X> map,
            std::string value,
            X* result,
            bool ignoreCase) {
      if (value[0] >= '0' && value[0] <= '9') {
        try {
          *result = (X) boost::lexical_cast<int>(value);
          return true;
        } catch (std::exception& e) {
        }
      }

      if (ignoreCase)
        std::transform(value.begin(), value.end(), value.begin(), ::tolower);

      auto s = map.find(value);

      if (s != map.end()) {
        *result = s->second;
        return true;
      }

      return false;
    }

    // <editor-fold desc="macro">
#define _tryParse_impl(T) \
    static bool tryParse(std::string value, T::values* result) { \
      return EnumBase::tryParse(T::map, value, result); \
    } \
\
    static bool tryParse(std::string value, T::values* result, bool ignoreCase) { \
      return EnumBase::tryParse(T::map, value, result, ignoreCase); \
    }

    // </editor-fold>

    // <editor-fold desc="toString">

    // </editor-fold>
    // </editor-fold>
    // </editor-fold>
  };
}

#endif	/* ENUMBASE_HPP */


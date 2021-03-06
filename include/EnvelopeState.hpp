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

#ifndef ENVELOPESTATE_H
#define	ENVELOPESTATE_H

#include <unordered_map>
#include <string>

#include "EnumBase.hpp"

namespace uxpp {

  /**
   * エンベロープの状態を表す列挙体です。
   */
  class EnvelopeState : public EnumBase {
  public:

    // <editor-fold desc="-- Enums --">

    enum values {
      /**
       * 無音状態。
       */
      silence,

      /**
       * アタック(立ち上がり)状態。
       */
      attack,

      /**
       * リリース(余韻)状態。
       */
      release,
    };

    // </editor-fold>

    // <editor-fold desc="-- Methods --">

    _key_exists_impl(EnvelopeState);
    _value_exists_impl(EnvelopeState);
    _toString_impl(EnvelopeState);
    _tryParse_impl(EnvelopeState);
    // </editor-fold>

  private:
    static const std::unordered_map<std::string, values> map;
  };
}

#endif	/* ENVELOPESTATE_H */

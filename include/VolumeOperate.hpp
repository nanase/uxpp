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

#ifndef VOLUMEOPERATE_HPP
#define	VOLUMEOPERATE_HPP

#include <unordered_map>
#include <string>
#include "EnumBase.hpp"

using namespace std;

namespace uxpp {

  /**
   * ボリュームに作用するオプションを表した列挙体です。
   */
  class VolumeOperate : public EnumBase {
  public:
    // <editor-fold desc="-- Enums --">

    enum values {
      /**
       * 変化を伴わない音量。ボリューム。
       */
      volume,

      /**
       * 変化を伴う音量。抑揚。
       */
      expression,

      /**
       * 発音の強さ。ベロシティ。
       */
      velocity,

      /**
       * 発音の増幅度。ゲイン。
       */
      gain,
    };

    // </editor-fold>

    // <editor-fold desc="-- Methods --">

    _key_exists_impl(VolumeOperate);
    _value_exists_impl(VolumeOperate);
    _toString_impl(VolumeOperate);
    _tryParse_impl(VolumeOperate);
    // </editor-fold>

  private:
    static const unordered_map<string, values> map;
  };

  const unordered_map<string, VolumeOperate::values>
          VolumeOperate::map = {
    {"volume", volume},
    {"expression", expression},
    {"velocity", velocity},
    {"gain", gain},
  };
}

#endif	/* VOLUMEOPERATE_HPP */


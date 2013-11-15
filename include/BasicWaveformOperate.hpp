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

#ifndef BASICWAVEFORMOPERATE_HPP
#define	BASICWAVEFORMOPERATE_HPP

#include <unordered_map>
#include <string>
#include "EnumBase.hpp"

using namespace std;

namespace uxpp {

  /**
   * 基本波形クラスに作用するオプションを表した列挙体です。
   */
  class BasicWaveformOperate : public EnumBase {
  public:

    // <editor-fold desc="-- Enums --">

    enum values {
      /**
       * デューティ比。
       */
      duty = 0x0100,

      /**
       * 波形タイプ。
       */
      type,
      // </editor-fold>

      // <editor-fold desc="-- Methods --">

      _key_exists_impl(BasicWaveformOperate);
      _value_exists_impl(BasicWaveformOperate);
      _toString_impl(BasicWaveformOperate);
      _tryParse_impl(BasicWaveformOperate);
      // </editor-fold>

      private:
      static const unordered_map<string, values> map;
    };

    const unordered_map<string, BasicWaveformOperate::values>
            BasicWaveformOperate::map = {
      {"duty", duty},
      {"type", type},
    };
  }

#endif	/* BASICWAVEFORMOPERATE_HPP */


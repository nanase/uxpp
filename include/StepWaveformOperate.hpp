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

#ifndef STEPWAVEFORMOPERATE_HPP
#define	STEPWAVEFORMOPERATE_HPP

#include <unordered_map>
#include <string>
#include "EnumBase.hpp"

namespace uxpp {

  /**
   * ステップ波形クラスに作用するオプションを表した列挙体です。
   */
  class StepWaveformOperate : public EnumBase {
  public:
    // <editor-fold desc="-- Enums --">

    enum values {
      /**
       * 周波数係数。指定された値が出力周波数に乗算されます。
       */
      freqFactor = 0x0000,

      /**
       * ユーザ波形の開始。このパラメータの実数値からユーザ波形として登録します。
       */
      begin,

      /**
       * ユーザ波形の終了。このパラメータの実数値までユーザ波形として登録します。
       */
      end,

      /**
       * ユーザ波形のキューイング。
       */
      queue,
    };

    // </editor-fold>

    // <editor-fold desc="-- Methods --">

    _key_exists_impl(StepWaveformOperate);
    _value_exists_impl(StepWaveformOperate);
    _toString_impl(StepWaveformOperate);
    _tryParse_impl(StepWaveformOperate);
    // </editor-fold>

  private:
    static const std::unordered_map<std::string, values> map;
  };

  const std::unordered_map<std::string, StepWaveformOperate::values>
          StepWaveformOperate::map = {
    {"freqFactor", freqFactor},
    {"begin", begin},
    {"end", end},
    {"queue", queue},
  };
}

#endif	/* STEPWAVEFORMOPERATE_HPP */


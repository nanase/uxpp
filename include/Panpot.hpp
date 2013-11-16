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

#ifndef PANPOT_H
#define	PANPOT_H

#include <cstdint>

namespace uxpp {

  /**
   * 音の定位 (左右チャネルのバランス) を表す実数値を格納する構造体です。
   */
  class Panpot {
  public:
    // <editor-fold desc="-- Construnctors --">
    /**
     * 左右チャネルのレベルを指定して
     * 新しい Panpot 構造体のインスタンスを初期化します。
     * @param lChannel 左チャネルのレベル。
     * @param rChannel 右チャネルのレベル。
     */
    Panpot(float lChannel, float rChannel);

    /**
     * 左右チャネルのレベルを制御するパンポット値を指定して
     * 新しい Panpot 構造体のインスタンスを初期化します。
     * @param value パンポット値。
     */
    Panpot(float value);
    // </editor-fold>  

  public:
    /**
     * 左チャネルのレベル。
     */
    const float l;
    
    /**
     * 右チャネルのレベルを取得または設定します。
     */
    const float r;
  };
}

#endif	/* PANPOT_H */


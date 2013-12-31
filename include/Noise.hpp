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

#ifndef NOISE_HPP
#define	NOISE_HPP

#include <vector>
#include "StepWaveform.hpp"

#define UXPP_LONGNOISE_SIZE 32767
#define UXPP_SHORTNOISE_SIZE 127

namespace uxpp {

  /**
   * 線形帰還シフトレジスタを用いた長周期擬似ノイズジェネレータです。
   */
  class LongNoise : public StepWaveform {
  public:
    // <editor-fold desc="-- Construnctors --">
    /**
     * 新しい LongNoise クラスのインスタンスを初期化します。
     */
    LongNoise();
    // </editor-fold>

    // <editor-fold desc="-- Methods --">
    /**
     * 波形のパラメータをリセットします。
     */
    virtual void reset();
    // </editor-fold>

  private:
    // <editor-fold desc="-- Static Fields --">

    static std::vector<float> data;

    static bool generated;
    // </editor-fold>

    // <editor-fold desc="-- Static Methods --">
    static void generate();
    // </editor-fold>
  };
  
  /**
   * 線形帰還シフトレジスタを用いた短周期擬似ノイズジェネレータです。
   */
  class ShortNoise : public StepWaveform {
  public:
    // <editor-fold desc="-- Construnctors --">
    /**
     * 新しい ShortNoise クラスのインスタンスを初期化します。
     */
    ShortNoise();
    // </editor-fold>

    // <editor-fold desc="-- Methods --">
    /**
     * 波形のパラメータをリセットします。
     */
    virtual void reset();
    // </editor-fold>

  private:
    // <editor-fold desc="-- Static Fields --">

    static std::vector<float> data;

    static bool generated;
    // </editor-fold>

    // <editor-fold desc="-- Static Methods --">
    static void generate();
    // </editor-fold>
  };
}

#endif	/* NOISE_HPP */


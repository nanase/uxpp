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

#ifndef BASICWAVEFORM_HPP
#define	BASICWAVEFORM_HPP

#include <utility>
#include <list>
#include "StepWaveform.hpp"

namespace uxpp {

  /**
   * 矩形波を生成する波形ジェネレータクラスです。
   */
  class Square : public StepWaveform {
  public:
    // <editor-fold desc="-- Construnctors --">
    /**
     * 新しい Square クラスのインスタンスを初期化します。
     */
    Square();
    // </editor-fold>

    // <editor-fold desc="-- Methods --">
    /**
     * パラメータを指定してこの波形の設定値を変更します。
     * @param data1 整数パラメータ。
     * @param data2 実数パラメータ。
     */
    virtual void setParameter(int32_t data1, float data2);

    /**
     * 波形のパラメータをリセットします。
     */
    virtual void reset();
    // </editor-fold>

  private:
    // <editor-fold desc="-- Static Fields --">
    static std::list<std::pair<int8_t, std::vector<float >> > cache;
    // </editor-fold>

    // <editor-fold desc="-- Methods --">
    void generateStep(const float duty);
    // </editor-fold>
  };

  /**
   * 擬似三角波を生成する波形ジェネレータクラスです。
   */
  class Triangle : public StepWaveform {
  public:
    // <editor-fold desc="-- Construnctors --">
    /**
     * 新しい Triangle クラスのインスタンスを初期化します。
     */
    Triangle();
    // </editor-fold>

    // <editor-fold desc="-- Methods --">
    /**
     * パラメータを指定してこの波形の設定値を変更します。
     * @param data1 整数パラメータ。
     * @param data2 実数パラメータ。
     */
    virtual void setParameter(int32_t data1, float data2);

    /**
     * 波形のパラメータをリセットします。
     */
    virtual void reset();
    // </editor-fold>

  private:
    // <editor-fold desc="-- Static Fields --">
    static std::list<std::pair<int8_t, std::vector<float >> > cache;
    // </editor-fold>

    // <editor-fold desc="-- Methods --">
    void generateStep(const int step);
    // </editor-fold>
  };
}

#endif	/* BASICWAVEFORM_HPP */


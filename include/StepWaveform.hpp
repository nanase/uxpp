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

#ifndef STEPWAVEFORM_HPP
#define	STEPWAVEFORM_HPP

#include <vector>
#include <stdint.h>
#include "IWaveform.hpp"

namespace uxpp {

  /**
   * ステップ (階段状) 波形を生成するジェネレータクラスです。
   */
  class StepWaveform : public IWaveform {
  public:
    // <editor-fold desc="-- Construnctors --">
    /**
     * 空の波形データを使って
     * 新しい StepWaveform クラスのインスタンスを初期化します。
     */
    StepWaveform();
    // </editor-fold>

    // <editor-fold desc="-- Methods --">
    /**
     * 与えられた周波数と位相からステップ波形を生成します。
     * @param data 生成された波形データが代入される配列。
     * @param frequency 生成に使用される周波数の配列。
     * @param phase 生成に使用される位相の配列。
     * @param sampleTime 波形が開始されるサンプル時間。
     * @param count 配列に代入されるデータの数。
     */
    virtual void getWaveforms(
            float data[],
            const double frequency[],
            const double phase[],
            int32_t sampleTime,
            int32_t count) override;

    /**
     * パラメータを指定してこの波形の設定値を変更します。
     * @param data1 整数パラメータ。
     * @param data2 実数パラメータ。
     */
    virtual void setParameter(int32_t data1, float data2) override;

    /**
     * 指定されたステップデータから波形生成用のデータを作成します。
     * @param data 波形生成のベースとなるステップデータ。
     * @param length データ配列の要素数。
     */
    virtual void setStep(const int8_t data[], const int8_t length);

    /**
     * エンベロープをアタック状態に遷移させます。
     */
    virtual void attack() override;

    /**
     * エンベロープをリリース状態に遷移させます。
     * @param time リリースされたサンプル時間。
     */
    virtual void release(int32_t time) override;

    /**
     * 波形のパラメータをリセットします。
     */
    virtual void reset() override;
    // </editor-fold>

  protected:
    /**
     * 波形生成に用いられる生データの配列です。
     */
    std::vector<float> value;

    /**
     * 波形生成に用いられるデータ長の長さです。
     */
    float length;

    /**
     * 波形生成に用いられる周波数補正係数です。
     */
    double freqFactor;

  private:
    std::vector<int8_t> queue;
  };
}

#endif	/* STEPWAVEFORM_HPP */


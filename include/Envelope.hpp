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

#ifndef ENVELOPE_H
#define	ENVELOPE_H

#include <cstdint>
#include "EnvelopeState.hpp"
#include "EnvelopeOperate.hpp"

namespace uxpp {

  /**
   * 時間によって変化するパラメータを実装するための
   * エンベロープ (包絡線) クラスです。
   */
  class Envelope {
  public:
    // <editor-fold desc="-- Construnctors --">
    /**
     * サンプリング周波数を指定して
     * 新しい Envelope クラスのインスタンスを初期化します。
     * @param samplingRate サンプリング周波数。
     */
    Envelope(float samplingRate);
    // </editor-fold>

    // <editor-fold desc="-- Methods --">
    /**
     * 現在のエンベロープの状態を表す列挙値を取得します。
     * @return 現在のエンベロープの状態を表す列挙値。
     */
    EnvelopeState::values getState() const;

    /**
     * このインスタンスにおけるすべてのパラメータを既定値に戻します。
     */
    void reset();

    /**
     * エンベロープの状態をアタック状態に変更します。
     */
    void attack();

    /**
     * エンベロープの状態をリリース状態に変更します。
     * @param time リリースが開始された時間値。
     */
    void relase(int32_t time);

    /**
     * エンベロープの状態をサイレンス状態に変更します。
     */
    void silence();

    /**
     * 現在のエンベロープの状態に基づき、エンベロープ値を出力します。
     * @param time エンベロープの開始時間値。
     * @param envelopes 出力が格納される実数の配列。
     * @param count 代入される実数値の数。
     */
    void generate(int32_t time, float envelopes[], int32_t count);

    /**
     * パラメータを用いてこのエンベロープの設定値を変更します。
     * @param data1 整数パラメータ。
     * @param data2 実数パラメータ。
     */
    void setParameter(int32_t data1, float data2);
    // </editor-fold>

    // <editor-fold desc="-- Static Methods --">
    /**
     * 値の変化しない、常に一定値を出力するエンベロープを作成します。
     * @param samplingRate サンプリング周波数
     * @return 一定出力値を持つエンベロープ。
     */
    static Envelope createConstant(float samplingRate);
    // </editor-fold>

  private:
    float samplingRate;
    int32_t releaseStartTime, t2, t3, t5;
    int32_t attackTime, peakTime, decayTime, releaseTime;
    float da, dd, dr, sustainLevel;
    EnvelopeState::values state;
  };
}

#endif	/* ENVELOPE_H */

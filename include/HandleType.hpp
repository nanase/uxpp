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

#ifndef HANDLETYPE_HPP
#define	HANDLETYPE_HPP

namespace uxpp {

  /**
   * 内部で扱われるハンドルのタイプを表す列挙体です。
   */
  enum class HandleType {
    /**
     * ゼロのゲートを持ち、発音されないノートを表します。
     */
    zeroGate = 0,

    /**
     * パートまたはマスターの各パラメータをリセットします。
     */
    reset = 1,

    /**
     * ノートのエンベロープをサイレンス状態に移行させ、無音状態にします。
     */
    silence = 2,

    /**
     * ノートのエンベロープをリリース状態に移行させます。
     */
    noteOff = 3,

    /**
     * ボリューム (音量) を変更します。
     */
    volume = 4,

    /**
     * パンポット (定位) を変更します。
     */
    panpot = 5,

    /**
     * ビブラートに関するパラメータを設定します。
     */
    vibrate = 6,

    /**
     * パートに波形を割り当てます。
     */
    waveform = 7,

    /**
     * 波形のパラメータを編集します。
     */
    editWaveform = 8,
    
    /**
     * パートの音量エンベロープを変更します。
     */
    envelope = 9,

    /**
     * パートのファインチューン値を変更します。
     */
    fineTune = 10,

    /**
     * パートの発音ノートキーをシフトします。
     */
    keyShift = 11,

    /**
     * ポルタメント効果に関するパラメータを設定します。
     */
    portament = 12,

    /**
     * パートを指定されたノートまたは周波数でアタック状態にします。
     */
    noteOn = 13,
  };
}

#endif	/* HANDLETYPE_HPP */


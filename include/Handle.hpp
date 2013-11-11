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

#ifndef HANDLE_HPP
#define	HANDLE_HPP

#include <cstdint>
#include "HandleType.hpp"

namespace uxpp {

  /**
   * シンセサイザに対する命令をサポートします。
   */
  class Handle {
  public:
    // <editor-fold desc="-- Construnctors --">
    /**
     * パラメータを指定せずに新しい Handle クラスのインスタンスを初期化します。
     * @param targetPart ハンドルが適用されるパート。
     * @param type ハンドルの種類。
     */
    Handle(int32_t targetPart, HandleType type);

    /**
     * パラメータを指定して新しい Handle クラスのインスタンスを初期化します。
     * @param targetPart ハンドルが適用されるパート。
     * @param type ハンドルの種類。
     * @param data1 パラメータに対する整数パラメータ。
     */
    Handle(int32_t targetPart, HandleType type, int32_t data1);

    /**
     * パラメータを指定して新しい Handle クラスのインスタンスを初期化します。
     * @param targetPart ハンドルが適用されるパート。
     * @param type ハンドルの種類。
     * @param data2 パラメータに対する実数パラメータ。
     */
    Handle(int32_t targetPart, HandleType type, float data2);

    /**
     * パラメータを指定して新しい Handle クラスのインスタンスを初期化します。
     * @param targetPart ハンドルが適用されるパート。
     * @param type ハンドルの種類。
     * @param data1 パラメータに対する整数パラメータ。
     * @param data2 パラメータに対する実数パラメータ。
     */
    Handle(int32_t targetPart, HandleType type, int32_t data1, float data2);

    /**
     * ベースとなる Handle オブジェクトと新しいパートを指定して
     * 新しい Handle クラスのインスタンスを初期化します。
     * @param handle ベースとなる Handle オブジェクト。
     * @param newTargetPart 新しいパート。
     */
    Handle(const Handle& handle, int32_t newTargetPart);
    // </editor-fold> 

    // <editor-fold desc="-- Methods --">
    /**
     * 対象となるパートを取得します。
     * @return 対象となるパート。
     */
    int32_t getTargetPart() const;

    /**
     * ハンドルのタイプを取得します。
     * @return ハンドルのタイプ。
     */
    HandleType getType() const;

    /**
     * ハンドルに対する整数パラメータを取得します。
     * @return ハンドルに対する整数パラメータ。
     */
    int32_t getData1() const;

    /**
     * ハンドルに対する整数パラメータ。
     * @return ハンドルに対する整数パラメータを取得します。
     */
    float getData2() const;
    // </editor-fold>  

  private:
    int32_t targetPart;
    HandleType type;
    int32_t data1;
    float data2;

  };
}
#endif	/* HANDLE_HPP */


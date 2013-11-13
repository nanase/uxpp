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

#ifndef FMOPERATE_HPP
#define	FMOPERATE_HPP

namespace uxpp {
  
  /**
   * FM音源クラスに作用するオプションを表した列挙体です。
   */
  enum class FMOperate {
    /**
     * オペレータ 0 に対する変調指数。
     */
    send0 = 0x0000,
    
    /**
     * オペレータ 1 に対する変調指数。
     */
    send1 = 0x0100,
    
    /**
     * オペレータ 2 に対する変調指数。
     */
    send2 = 0x0200,
    
    /**
     * オペレータ 3 に対する変調指数。
     */
    send3 = 0x0300,
    
    /**
     * 出力キャリア振幅。
     */
    output = 0x0400,
    
    /**
     * キャリア周波数。
     */
    frequency = 0x0500,
    
    /**
     * オペレータ 0。
     */
    operator0 = 0x0000,
    
    /**
     * オペレータ 1。
     */
    operator1 = 0x1000,
    
    /**
     * オペレータ 2。
     */
    operator2 = 0x2000,
    
    /**
     * オペレータ 3。
     */
    operator3 = 0x3000,
  };
  
  const std::unordered_map<std::string, FMOperate>
          FMOperateString = {
    {"send0", FMOperate::send0},
    {"send1", FMOperate::send1},
    {"send2", FMOperate::send2},
    {"send3", FMOperate::send3},
    {"output", FMOperate::output},
    {"out", FMOperate::output},
    {"frequency", FMOperate::frequency},
    {"freq", FMOperate::frequency},
    {"operator0", FMOperate::operator0},
    {"operator1", FMOperate::operator1},
    {"operator2", FMOperate::operator2},
    {"operator3", FMOperate::operator3},
    {"op0", FMOperate::operator0},
    {"op1", FMOperate::operator1},
    {"op2", FMOperate::operator2},
    {"op3", FMOperate::operator3},
  };
}

#endif	/* FMOPERATE_HPP */


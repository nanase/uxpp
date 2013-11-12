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

#include "Handle.hpp"

namespace uxpp {
  // <editor-fold desc="-- Construnctors --">

  Handle::Handle(int32_t targetPart, HandleType type) :
  targetPart(targetPart), type(type), data1(0), data2(0.0f) {
  }

  Handle::Handle(int32_t targetPart, HandleType type, int32_t data1) :
  targetPart(targetPart), type(type), data1(data1), data2(0.0f) {
  }

  Handle::Handle(int32_t targetPart, HandleType type, float data2) :
  targetPart(targetPart), type(type), data1(0), data2(data2) {
  }

  Handle::Handle(
          int32_t targetPart, HandleType type, int32_t data1, float data2) :
  targetPart(targetPart), type(type), data1(data1), data2(data2) {
  }

  Handle::Handle(const Handle& handle, int32_t newTargetPart) :
  targetPart(newTargetPart),
  type(handle.type),
  data1(handle.data1),
  data2(handle.data2) {
  }
  // </editor-fold> 

  // <editor-fold desc="-- Methods --">

  int32_t Handle::getTargetPart() const {
    return this->targetPart;
  }

  HandleType Handle::getType() const {
    return this->type;
  }

  int32_t Handle::getData1() const {
    return this->data1;
  }

  float Handle::getData2() const {
    return this->data2;
  }
  // </editor-fold>  
}

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

#include "common.hpp"
#include "Panpot.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

namespace uxpp {
  // <editor-fold desc="-- Construnctors --">

  Panpot::Panpot(float lChannel, float rChannel) :
  l(clamp(lChannel, 1.0f, 0.0f)),
  r(clamp(rChannel, 1.0f, 0.0f)) {
    assert(lChannel >= 0.0f && lChannel <= 1.0f);
    assert(rChannel >= 0.0f && rChannel <= 1.0f);
  }

  Panpot::Panpot(float value) :
  l(value >= 0.0f ? (float) sin(((double) value + 1.0) * M_PI / 2.0) : 1.0f),
  r(value <= 0.0f ? (float) sin((-(double) value + 1.0) * M_PI / 2.0) : 1.0f) {
    assert(value >= -1.0f && value <= 1.0f);
  }
  // </editor-fold>

  // <editor-fold desc="-- Methods --">

  float Panpot::getL() const {
    return this->l;
  }

  float Panpot::getR() const {
    return this->r;
  }
  // </editor-fold>
}
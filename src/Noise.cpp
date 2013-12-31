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

#include <algorithm>

#include "Noise.hpp"

using namespace std;

namespace uxpp {

  // <editor-fold desc="-- Static Fields --">

  vector<float> LongNoise::data(UXPP_LONGNOISE_SIZE);

  bool LongNoise::generated = false;
  // </editor-fold>

  // <editor-fold desc="-- Construnctors --">

  LongNoise::LongNoise() {
  }
  // </editor-fold>

  // <editor-fold desc="-- Methods --">

  void LongNoise::reset() {
    if (!LongNoise::generated)
      LongNoise::generate();

    this->freqFactor = 0.001;    
    this->value.resize(UXPP_LONGNOISE_SIZE);
    copy(LongNoise::data.begin(), LongNoise::data.end(), this->value.begin());
    this->length = UXPP_LONGNOISE_SIZE;    
  }
  // </editor-fold>

  // <editor-fold desc="-- Static Methods --">

  void LongNoise::generate() {
    uint16_t reg = 0xffff;
    uint16_t output = 1;
    
    for (int i = 0; i < UXPP_LONGNOISE_SIZE; i++) {
      reg += (uint16_t) (reg + (((reg >> 14) ^ (reg >> 13)) & 1));
      LongNoise::data[i] = (output ^= (uint16_t) (reg & 1)) * 2.0f - 1.0f;
    }

    LongNoise::generated = true;
  }
  // </editor-fold>
}

namespace uxpp {

  // <editor-fold desc="-- Static Fields --">

  vector<float> ShortNoise::data(UXPP_SHORTNOISE_SIZE);

  bool ShortNoise::generated = false;
  // </editor-fold>

  // <editor-fold desc="-- Construnctors --">

  ShortNoise::ShortNoise() {
  }
  // </editor-fold>

  // <editor-fold desc="-- Methods --">

  void ShortNoise::reset() {
    if (!ShortNoise::generated)
      ShortNoise::generate();

    this->freqFactor = 0.001;    
    this->value.resize(UXPP_SHORTNOISE_SIZE);
    copy(ShortNoise::data.begin(), ShortNoise::data.end(), this->value.begin());
    this->length = UXPP_SHORTNOISE_SIZE;    
  }
  // </editor-fold>

  // <editor-fold desc="-- Static Methods --">

  void ShortNoise::generate() {
    uint16_t reg = 0xffff;
    uint16_t output = 1;
    
    for (int i = 0; i < UXPP_SHORTNOISE_SIZE; i++) {
      reg += (uint16_t) (reg + (((reg >> 6) ^ (reg >> 5)) & 1));
      ShortNoise::data[i] = (output ^= (uint16_t) (reg & 1)) * 2.0f - 1.0f;
    }

    ShortNoise::generated = true;
  }
  // </editor-fold>
}
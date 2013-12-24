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

#include <cfloat>
#include <cassert>
#include "common.hpp"
#include "StepWaveform.hpp"
#include "StepWaveformOperate.hpp"

namespace uxpp {
  // <editor-fold desc="-- Construnctors --">

  StepWaveform::StepWaveform() {
    this->reset();
  }

  StepWaveform::StepWaveform(const StepWaveform& orig) {
    const int length = ARRAY_LENGTH(orig.value);
    this->value = new float[length];

    for (int i = 0; i < length; i++)
      this->value[i] = orig.value[i];
  }
  // </editor-fold>

  // <editor-fold desc="-- Destructors --">

  StepWaveform::~StepWaveform() {
    delete[] this->value;
  }
  // </editor-fold>

  // <editor-fold desc="-- Methods --">

  void StepWaveform::getWaveforms(
          float data[],
          const double frequency[],
          const double phase[],
          int32_t sampleTime,
          int32_t count) {
    const int value_length = ARRAY_LENGTH(this->value);

    for (int i = 0; i < count; i++) {
      float tmp = (float) (phase[i] * frequency[i] * this->freqFactor);

      if (tmp < 0.0f)
        data[i] = 0.0f;
      else
        data[i] = this->value[(int) (tmp * this->length) % value_length];
    }
  }

  void StepWaveform::setParameter(int32_t data1, float data2) {
    switch ((StepWaveformOperate::values)data1) {
      case StepWaveformOperate::freqFactor:
        this->freqFactor = clamp(data2, FLT_MAX, 0.0f) * 0.001;
        break;

      case StepWaveformOperate::begin:
        this->queue.clear();
        this->queue.push_back((int8_t) clamp(data2, 255.0f, 0.0f));
        break;

      case StepWaveformOperate::end:
        this->queue.push_back((int8_t) clamp(data2, 255.0f, 0.0f));

        if (this->queue.size() <= 32767)
          this->setStep(this->queue.data(), this->queue.size());

        this->queue.clear();
        break;

      case StepWaveformOperate::queue:
        this->queue.push_back((int8_t) clamp(data2, 255.0f, 0.0f));
        break;
    }
  }

  void StepWaveform::setStep(const int8_t data[], const int8_t length) {
    assert(data != nullptr);
    assert(length > 0);
    assert(length <= 32767);

    float max = data[0];
    float min = data[0];

    for (int i = 0; i < length; i++) {
      if (max < data[i])
        max = data[i];
      else if (min > data[i])
        min = data[i];
    }

    float a = 2.0f / (max - min);
    this->length = (float) length;

    delete[] this->value;
    this->value = new float[length];

    if (max == min)
      return;

    for (int i = 0; i < length; i++)
      this->value[i] = (data[i] - min) * a - 1.0f;
  }

  void StepWaveform::attack() {
  }

  void StepWaveform::release(int32_t time) {
  }

  void StepWaveform::reset() {
    int8_t zero[] = {0};
    this->setStep(zero, 1);
  }
  // </editor-fold>
}
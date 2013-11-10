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
#include "common.h"
#include "Envelope.h"

namespace uxpp {

  // <editor-fold desc="-- Construnctors --">

  Envelope::Envelope(float samplingRate) {
    assert(samplingRate > 0.0f);
    
    this->samplingRate = samplingRate;
    this->reset();
  }
  // </editor-fold>

  // <editor-fold desc="-- Methods --">

  EnvelopeState Envelope::getState() {
    return this->state;
  }

  void Envelope::reset() {
    this->attackTime = (int) (0.05f * this->samplingRate);
    this->peakTime = (int) (0.0f * this->samplingRate);
    this->decayTime = (int) (0.0f * this->samplingRate);
    this->sustainLevel = 1.0f;
    this->releaseTime = (int) (0.05f * this->samplingRate);
    this->state = EnvelopeState::silence;
  }

  void Envelope::attack() {
    this->state = EnvelopeState::attack;

    // precalc
    this->t2 = this->attackTime + this->peakTime;
    this->t3 = this->t2 + this->decayTime;
    this->da = 1.0f / this->attackTime;
    this->dd = (1.0f - this->sustainLevel) / this->decayTime;
  }

  void Envelope::relase(int32_t time) {
    assert(time >= 0);
    
    if (this->state == EnvelopeState::attack) {
      this->state = EnvelopeState::release;
      this->releaseStartTime = time;

      // precalc
      this->t5 = time + this->releaseTime;
      this->dr = this->sustainLevel / this->releaseTime;
    }
  }

  void Envelope::silence() {
    this->state = EnvelopeState::silence;
  }

  void Envelope::generate(int32_t time, float envelopes[], int32_t count) {
    assert(time >= 0);
    assert(count > 0);    
    assert(envelopes != nullptr);    
    
    float res;
    for (int i = 0; i < count; i++, time++) {
      if (this->state == EnvelopeState::attack) {
        res = (time < this->attackTime) ? time * this->da :
                (time < this->t2) ? 1.0f :
                (time < this->t3) ? 1.0f - (time - this->t2) * this->dd :
                this->sustainLevel;
      } else if (this->state == EnvelopeState::release) {
        if (time < this->t5)
          res = this->sustainLevel - (time - this->releaseStartTime) * this->dr;
        else {
          res = 0.0f;
          this->state = EnvelopeState::silence;
        }
      } else
        res = 0.0f;

      envelopes[i] = res;
    }
  }

  void Envelope::setParameter(int32_t data1, float data2) {
    switch ((EnvelopeOperate) data1) {
      case EnvelopeOperate::attack:
        assert(data2 >= 0.0f);
        this->attackTime =
                (int) (clamp(data2, FLT_MAX, 0.0f) * this->samplingRate);
        break;

      case EnvelopeOperate::peak:
        assert(data2 >= 0.0f);
        this->peakTime =
                (int) (clamp(data2, FLT_MAX, 0.0f) * this->samplingRate);
        break;

      case EnvelopeOperate::decay:
        assert(data2 >= 0.0f);
        this->decayTime =
                (int) (clamp(data2, FLT_MAX, 0.0f) * this->samplingRate);
        break;

      case EnvelopeOperate::sustain:
        assert(data2 >= 0.0f && data2 <= 1.0f);
        this->sustainLevel = clamp(data2, 1.0f, 0.0f);
        break;

      case EnvelopeOperate::release:
        assert(data2 >= 0.0f);
        this->releaseTime =
                (int) (clamp(data2, FLT_MAX, 0.0f) * this->samplingRate);
        break;

      default:
        break;
    }
  }
  // </editor-fold>
}
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

#include <climits>
#include "common.hpp"
#include "BasicWaveform.hpp"
#include "BasicWaveformOperate.hpp"

using namespace std;

namespace uxpp {

  // <editor-fold desc="-- Static Fields --">
  list<pair<int8_t, vector<float >> > Square::cache;
  // </editor-fold>

  // <editor-fold desc="-- Construnctors --">

  Square::Square() {
  }
  // </editor-fold>

  // <editor-fold desc="-- Methods --">

  void Square::setParameter(int32_t data1, float data2) {
    switch ((BasicWaveformOperate::values)data1) {
      case BasicWaveformOperate::duty:
        this->generateStep(clamp(data2, 1.0f, 0.0f));
        break;

      default:
        StepWaveform::setParameter(data1, data2);
        break;
    }
  }

  void Square::reset() {
    this->generateStep(0.5f);
  }

  void Square::generateStep(const float duty) {
    if (duty <= 0.0f || duty >= 1.0f)
      return;

    int8_t onTime = (int8_t) (1.0f / (duty <= 0.5f ? duty : (1.0f - duty))) - 1;

    if (onTime > 32767)
      return;

    pair<int8_t, vector<float >> nc;

    for (auto now = Square::cache.begin(); now != Square::cache.end(); now++) {
      if (now->first == onTime) {
        nc = *now;
        break;
      }
    }

    if (nc.second.empty()) {
      int8_t* l = new int8_t[onTime + 1];

      if (duty <= 0.5f) {
        // 10, 100, 1000, ...
        l[0] = (int8_t) 1;
      } else {
        // 10, 110, 1110, ...
        for (int i = 0; i < onTime; i++)
          l[i] = (int8_t) 1;
      }

      this->setStep(l, onTime + 1);

      pair<int8_t, vector<float >> new_cache(onTime, this->value);
      Square::cache.push_front(new_cache);

      if (Square::cache.size() > 32)
        Square::cache.pop_back();

      delete[] l;
    } else {
      this->value = nc.second;
      this->length = (float) nc.second.size();
    }
  }
  // </editor-fold>
}

namespace uxpp {

  // <editor-fold desc="-- Static Fields --">
  list<pair<int8_t, vector<float >> > Triangle::cache;
  // </editor-fold>

  // <editor-fold desc="-- Construnctors --">

  Triangle::Triangle() {
  }
  // </editor-fold>

  // <editor-fold desc="-- Methods --">

  void Triangle::setParameter(int32_t data1, float data2) {
    switch ((BasicWaveformOperate::values)data1) {
      case BasicWaveformOperate::type:
        this->generateStep((int) clamp(data2, (float)INT_MAX, 1.0f)); // HACK
        break;

      default:
        StepWaveform::setParameter(data1, data2);
        break;
    }
  }

  void Triangle::reset() {
    this->generateStep(16);
  }

  void Triangle::generateStep(const int step) {
    if (step <= 0 || step >= 256)
      return;

    pair<int8_t, vector<float >> nc;

    for (auto now = Triangle::cache.begin(); now != Triangle::cache.end(); now++) {
      if (now->first == step) {
        nc = *now;
        break;
      }
    }

    if (nc.second.empty()) {
      int8_t* l = new int8_t[step * 2];

      for (int i = 0; i < step; i++)
        l[i] = (int8_t) i;

      for (int i = step; i < step * 2; i++)
        l[i] = (int8_t) (step * 2 - i - 1);

      this->setStep(l, step * 2);

      pair<int8_t, vector<float >> new_cache(step, this->value);
      Triangle::cache.push_front(new_cache);

      if (Triangle::cache.size() > 32)
        Triangle::cache.pop_back();

      delete[] l;
    } else {
      this->value = nc.second;
      this->length = (float) nc.second.size();
    }
  }
  // </editor-fold>
}
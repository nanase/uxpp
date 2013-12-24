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

#include <unordered_map>
#include <string>
#include "StepWaveformOperate.hpp"
#include "VolumeOperate.hpp"
#include "RandomNoiseOperate.hpp"
#include "HandleType.hpp"
#include "FMOperate.hpp"
#include "EnvelopeState.hpp"
#include "EnvelopeOperate.hpp"
#include "BasicWaveformOperate.hpp"

namespace uxpp {
  const std::unordered_map<std::string, StepWaveformOperate::values>
          StepWaveformOperate::map = {
    {"freqFactor", freqFactor},
    {"begin", begin},
    {"end", end},
    {"queue", queue},
  };

  const std::unordered_map<std::string, VolumeOperate::values>
          VolumeOperate::map = {
    {"volume", volume},
    {"expression", expression},
    {"velocity", velocity},
    {"gain", gain},
  };

  const std::unordered_map<std::string, RandomNoiseOperate::values>
          RandomNoiseOperate::map = {
    {"seed", seed},
    {"length", length},
  };

  const std::unordered_map<std::string, HandleType::values>
          HandleType::map = {
    {"zeroGate", zeroGate},
    {"reset", reset},
    {"silence", silence},
    {"noteOff", noteOff},
    {"volume", volume},
    {"panpot", panpot},
    {"vibrate", vibrate},
    {"waveform", waveform},
    {"editWaveform", editWaveform},
    {"envelope", envelope},
    {"fineTune", fineTune},
    {"keyShift", keyShift},
    {"portament", portament},
    {"noteOn", noteOn},
  };

  const std::unordered_map<std::string, FMOperate::values>
          FMOperate::map = {
    {"send0", send0},
    {"send1", send1},
    {"send2", send2},
    {"send3", send3},
    {"output", output},
    {"out", output},
    {"frequency", frequency},
    {"freq", frequency},
    {"operator0", operator0},
    {"operator1", operator1},
    {"operator2", operator2},
    {"operator3", operator3},
    {"op0", operator0},
    {"op1", operator1},
    {"op2", operator2},
    {"op3", operator3},
  };

  const std::unordered_map<std::string, EnvelopeState::values>
          EnvelopeState::map = {
    {"silence", silence},
    {"attack", attack},
    {"release", release},
  };
  
  const std::unordered_map<std::string, EnvelopeOperate::values>
          EnvelopeOperate::map = {
    {"none", none},
    {"attack", attack},
    {"peak", peak},
    {"decay", decay},
    {"sustain", sustain},
    {"release", release},
    {"a", attack},
    {"p", peak},
    {"d", decay},
    {"s", sustain},
    {"r", release},
  };
  
    const std::unordered_map<std::string, BasicWaveformOperate::values>
            BasicWaveformOperate::map = {
      {"duty", duty},
      {"type", type},
    };
}
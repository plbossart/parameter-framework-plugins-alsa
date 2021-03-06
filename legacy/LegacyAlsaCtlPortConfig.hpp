/*
 * Copyright (c) 2011-2015, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once

#include "AlsaCtlPortConfig.hpp"
#include <stdint.h>
#include <string>

struct _snd_pcm;

class LegacyAlsaCtlPortConfig : public AlsaCtlPortConfig
{
public:
    /**
     * LegacyAlsaCtlPortConfig Class constructor
     *
     * @param[in] mappingValue instantiation mapping value
     * @param[in] instanceConfigurableElement pointer to configurable element instance
     * @param[in] context contains the context mappings
     */
    LegacyAlsaCtlPortConfig(const std::string &mappingValue,
                            CInstanceConfigurableElement *instanceConfigurableElement,
                            const CMappingContext &context,
                            core::log::Logger& logger);

protected:
    // Stream operations
    virtual bool doOpenStream(StreamDirection streamDirection, std::string &error);
    virtual void doCloseStream(StreamDirection streamDirection);

private:
    /** Default port configuration */
    static const PortConfig _defaultPortConfig;
    /** Latency */
    static const uint32_t _latencyMicroSeconds;
    /** Stream Name */
    std::string _streamName;

    /**
     * Stream handles.
     * Uses StreamDirection as index.
     */
    _snd_pcm *_streamHandle[_streamDirectionCount];
};

/*****************************************************************************
Copyright (c) 2011  David Guillen Fandos (david@davidgf.net)
All rights reserved.

Attention! Contains pieces of code from others such as Mesa and GRRLib

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. Neither the name of copyright holders nor the names of its
   contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#ifndef OGX_DEBUG_H
#define OGX_DEBUG_H

#include <errno.h>
#include <stdio.h>

typedef enum {
    OGX_LOG_WARNING = 1 << 0,
    OGX_LOG_CALL_LISTS = 1 << 1,
    OGX_LOG_LIGHTING = 1 << 2,
    OGX_LOG_TEXTURE = 1 << 3,
} OgxLogMask;

extern OgxLogMask _ogx_log_mask;

/* Warning are always emitted unless the mask is 0 */
#define warning(format, ...) \
    if (_ogx_log_mask) { \
        fprintf(stderr, format "\n", ##__VA_ARGS__); \
    }

#define debug(mask, format, ...) \
    if (_ogx_log_mask & mask) { \
        fprintf(stderr, format "\n", ##__VA_ARGS__); \
    }

void _ogx_log_init();

#endif /* OGX_DEBUG_H */

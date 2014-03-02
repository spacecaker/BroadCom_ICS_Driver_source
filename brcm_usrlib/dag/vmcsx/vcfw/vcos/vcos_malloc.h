/* ============================================================================
Copyright (c) 2009-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#include "vcfw/rtos/rtos.h"

#ifdef __CC_ARM
extern uint32_t rtos_get_free_mem(const uint32_t pool);
#include <stdlib.h>
#endif

#if defined(VCOS_INLINE_BODIES)

VCOS_INLINE_IMPL
void *vcos_malloc(VCOS_UNSIGNED size, const char *description) {
   return rtos_malloc_priority(size, RTOS_ALIGN_DEFAULT, RTOS_PRIORITY_UNIMPORTANT, description);
}


VCOS_INLINE_IMPL
void *vcos_calloc(VCOS_UNSIGNED num, VCOS_UNSIGNED size, const char *description) {
   return rtos_calloc_priority(num*size, RTOS_ALIGN_DEFAULT, RTOS_PRIORITY_UNIMPORTANT, description);
}

/** Free memory
  */
VCOS_INLINE_IMPL
void vcos_free(void *ptr) {
   rtos_priorityfree(ptr);
}

/** Allocate aligned memory
  */
VCOS_INLINE_IMPL
void * vcos_malloc_aligned( VCOS_UNSIGNED size, VCOS_UNSIGNED align, const char *description) {
   return rtos_malloc_priority(size, align, RTOS_PRIORITY_UNIMPORTANT, description);
}

VCOS_INLINE_IMPL
unsigned long vcos_get_free_mem(void) {
   return rtos_get_free_mem(0);
}

#endif /* VCOS_INLINE_BODIES */


/*=============================================================================
Copyright (c) 2009 Broadcom Europe Limited.
All rights reserved.

Project  :  vcfw
Module   :  chip driver
File     :  $RCSfile: $
Revision :  $Revision: $

FILE DESCRIPTION
VideoCore OS Abstraction Layer - thread local storage
=============================================================================*/

#ifndef VCOS_TLS_H
#define VCOS_TLS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "interface/vcos/vcos_types.h"
#include "vcos_platform.h"


/** Create a new thread local storage data key visible to all threads in
  * the current process.
  *
  * @param key    The key to create
  */
VCOS_INLINE_DECL
VCOS_STATUS_T vcos_tls_create(VCOS_TLS_KEY_T *key);

/** Delete an existing TLS data key.
  */
VCOS_INLINE_DECL
void vcos_tls_delete(VCOS_TLS_KEY_T tls);

/** Set the value seen by the current thread.
  *
  * @param key    The key to update
  * @param v      The value to set for the current thread.
  *
  * @return VCOS_SUCCESS, or VCOS_ENOMEM if memory for this slot
  * could not be allocated.
  *
  * If TLS is being emulated via VCOS then the memory required
  * can be preallocated at thread creation time
  */
VCOS_INLINE_DECL
VCOS_STATUS_T vcos_tls_set(VCOS_TLS_KEY_T tls, void *v);

/** Get the value for the current thread.
  *
  * @param key    The key to update
  *
  * @return The current value for this thread.
  */
VCOS_INLINE_DECL
void *vcos_tls_get(VCOS_TLS_KEY_T tls);

#ifdef __cplusplus
}
#endif

#endif


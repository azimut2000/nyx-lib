/* @@@LICENSE
*
*      Copyright (c) 2010-2012 Hewlett-Packard Development Company, L.P.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */

/**
 * @file nyx_utils.h
 *
 */


#ifndef _NYX_UTILS_H_
#define _NYX_UTILS_H_

#include <stdarg.h>
#include <string.h>

#include <nyx/common/nyx_macros.h>
#include <nyx/module/nyx_device_internal.h>
#include <nyx/module/nyx_log.h>

/* Utility functions to write and read an integer value to/from a file */
void nyx_utils_write_value (char* path, int32_t val);
int32_t nyx_utils_read_value (char* path);

nyx_error_t nyx_utils_async_callback (nyx_device_t* device_in_ptr,  nyx_device_callback callback,
		nyx_callback_status_t status,void* context);

#define return_if(condition, args...)                         \
  do {                                                        \
    if (UNLIKELY(condition)) {                                \
      return args;                                            \
    }                                                         \
  } while(0)

#define msg_return_if(cond, retval, msg_level, m, args...)    \
  do {                                                        \
    if (UNLIKELY(cond)) {                                     \
      nyx_msg((msg_level), (m), ##args);                          \
      return retval;                                          \
    }                                                         \
  } while (0)

#ifdef DEBUG_MEMORY
#define dbg_set(var, val) ((var) = (val))
#else
#define dbg_set(var, val) do {} while(0)
#endif

#define release_assert(cond)                                 \
  do {                                                       \
    if (UNLIKELY(!cond)) {                                   \
      nyx_msg(NYX_LOG_CRITICAL, "Condition %s broken", #cond);           \
      abort();                                               \
               }                                                        \
  } while(0)

#endif /* _NYX_UTILS_H_ */
/* ============================================================================
Copyright (c) 2007-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef RTOS_H_
#define RTOS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vcinclude/common.h"
#include "vcfw/drivers/driver.h"
#include "vcfw/module/module.h"

#include <stdlib.h>


/******************************************************************************
 Global funcs - implementation is specific to which RTOS you are including
 *****************************************************************************/

//Routine to initialise the RTOS
extern int32_t rtos_init( void );

//Routine to start the RTOS
extern int32_t rtos_start( int argc, char *argv[] );

/******************************************************************************
 Global data
 *****************************************************************************/

extern int rtos_argc;
extern char **rtos_argv;

/******************************************************************************
 RTOS Time functions
 *****************************************************************************/

//Routine to delay the execution cycle
extern int32_t rtos_delay( const uint32_t usecs, const uint32_t suspend );

//Routine used to put the current task (if there is one) to sleep
extern int32_t rtos_sleep( void );

/***********************************************************
 * Returns the current hardware microsecond counter value.
 *
 * @return       Microsecond counter value.
 *
 ***********************************************************/

extern unsigned rtos_getmicrosecs(void);

/******************************************************************************
 Driver + module loading / unloading code
 *****************************************************************************/

//Routine to load a driver
extern int32_t rtos_driver_load( const char *driver_name, DRIVER_T **driver );

//Routine to unload a driver
extern int32_t rtos_driver_unload( const DRIVER_T *driver );


//Routine to load some module
extern int32_t rtos_module_load( const char *module_name, MODULE_T **module );

//Routine to unload some module
extern int32_t rtos_module_unload( const MODULE_T *module );

/******************************************************************************
 ISR functionality
 *****************************************************************************/

//Definition of a LISR
typedef void (*RTOS_LISR_T)( const uint32_t vector_num );

//Definition of an ASM lisr
typedef void (*RTOS_LISR_ASM_T)( void );

//Routine to register a isr
extern int32_t rtos_register_lisr ( const uint32_t vector, RTOS_LISR_T new_lisr, RTOS_LISR_T *old_lisr );

//Routine to register an assembler based isr
extern int32_t rtos_register_asm_lisr ( const uint32_t vector, RTOS_LISR_ASM_T new_lisr, RTOS_LISR_ASM_T *old_lisr );

//Routine to disable interrupts
extern uint32_t rtos_disable_interrupts( void );

//Routine to re-enable interrupts
extern void rtos_restore_interrupts( const uint32_t previous_state );


//Routine to query if interrupts are enable or not
#ifdef __HIGHC__
static inline uint32_t rtos_interrupts_enabled( void )
{
   return !!(_vasm("mov %D,%sr") & (1<<30));
}
#endif // ifdef __HIGHC__


/******************************************************************************
 Secure functionality
 *****************************************************************************/

//Definition for a secure function handle
typedef uint32_t RTOS_SECURE_FUNC_HANDLE_T;

//Definition for a secure function
//NOTE! Whilst no params are shown for this function, the calling function can pass up to 5 registers to it
typedef void (*RTOS_SECURE_FUNC_T)();


//Function to register secure functions
//NOTE - these functions should be encrypted
extern int32_t rtos_secure_function_register( RTOS_SECURE_FUNC_T secure_func,
                                              RTOS_SECURE_FUNC_HANDLE_T *secure_func_handle );

//Routine to call a secure function
extern int32_t rtos_secure_function_call( const RTOS_SECURE_FUNC_HANDLE_T secure_func_handle,
                                          const uint32_t r0,
                                          const uint32_t r1,
                                          const uint32_t r2,
                                          const uint32_t r3,
                                          const uint32_t r4 );

/******************************************************************************
 Multithreading functionality
 *****************************************************************************/
// This constant is a thread id which should never be returned by
// rtos_get_thread_id
#define RTOS_INVALID_THREAD_ID      (~0)

// Routine to get the id of the current thread
extern uint32_t rtos_get_thread_id( void );

// Routine to migrate the current thread to the other cpu. Does nothing if
// already on the requested cpu.
// In rtos_none, fails if something is already running on the other cpu.
extern void rtos_cpu_migrate( const uint32_t cpu );

// Launch the given function asynchronously on the other cpu. Do not wait
// for it to return.
// In rtos_none, fails if the specified cpu is either the one you're calling
// from, or has something else running on it.
typedef void (*RTOS_LAUNCH_FUNC_T)( uint32_t argc, void *argv );
extern uint32_t rtos_cpu_launch( const uint32_t cpu, RTOS_LAUNCH_FUNC_T launch_func, const uint32_t argc, void *argv, const uint32_t stack_size );

// Wait for the specified thread to terminate. This should be called exactly
// once for each thread created. After it is called, thread_id may identify
// a new thread.
extern void rtos_thread_join( const uint32_t thread_id );

// Return the amount of free space on the stack (in bytes). Useful for making
// recursive algorithms safe.
extern uint32_t rtos_check_stack( void );

// Returns non-zero if the caller is within interrupt context, otherwise
// returns zero.
extern int rtos_in_interrupt( void );

/******************************************************************************
 Latch functionality
 *****************************************************************************/

//typedef of a latch
typedef struct opaque_rtos_latch_t* RTOS_LATCH_T;

// Latch values:
//    0 = unlocked
//    1 = locked without contention
//    Other = locked with contention (one or more threads waiting in rtos_latch_get)

#define rtos_latch_locked() ((RTOS_LATCH_T)1) // For use in initialisation only

#define rtos_latch_unlocked() ((RTOS_LATCH_T)0)

// N.B. a latch can also be a pointer to a queue of waiting threads, so
// comparison to rtos_latch_locked() is rarely wise; inequality to
// rtos_latch_unlocked() is a better test of lockedness.

// Don't call these functions, use the rtos_latch_get etc macros.
//Routine to get the latch. Will suspend / busy wait dependant on the rtos implementation
extern void rtos_latch_get_real( RTOS_LATCH_T *latch );
//Routine to put the latch.
extern void rtos_latch_put_real( RTOS_LATCH_T *latch );

// Routine to try and get a latch. Can be called from an interrupt
extern int32_t rtos_latch_try_real( RTOS_LATCH_T *latch );


// See vcfw/rtos/common/rtos_latch_logging.c for more about latch logging.
//#define LATCH_LOGGING_ENABLED

#ifdef NDEBUG
#undef LATCH_LOGGING_ENABLED
#endif

#ifdef LATCH_LOGGING_ENABLED

extern void rtos_latch_logging_latch_get( RTOS_LATCH_T *latch, const char * name );
extern void rtos_latch_logging_latch_put( RTOS_LATCH_T *latch, const char * name );
extern int32_t rtos_latch_logging_latch_try( RTOS_LATCH_T *latch, const char * name );


#ifndef STRINGISED
#define _STRINGISED(x) #x
#define  STRINGISED(x) _STRINGISED(x)
#endif

#define rtos_latch_get( latch ) rtos_latch_logging_latch_get( (latch) , "Loc:" __FILE__ " " STRINGISED(__LINE__) )
#define rtos_latch_put( latch ) rtos_latch_logging_latch_put( (latch) , "Loc:" __FILE__ " " STRINGISED(__LINE__) )
#define rtos_latch_try( latch ) rtos_latch_logging_latch_try( (latch) , "Loc:" __FILE__ " " STRINGISED(__LINE__) )

extern void rtos_latch_logging_init();

#else

#define rtos_latch_get( latch ) rtos_latch_get_real( (latch) )
#define rtos_latch_put( latch ) rtos_latch_put_real( (latch) )
#define rtos_latch_try( latch ) rtos_latch_try_real( (latch) )


#endif


/******************************************************************************
 CPU-related functions
 *****************************************************************************/

// Returns the number of CPUs controlled by the RTOS
extern uint32_t rtos_get_cpu_count( void );

// Returns the number of the current CPU (numbered from 0)
extern uint32_t rtos_get_cpu_number( void );

// This constant indicates that the current CPU should be used
#define RTOS_CPU_CURRENT               (~0)

// Returns a count of the usecs spent sleeping on the specified CPU
extern uint32_t rtos_get_sleep_time( const uint32_t cpu );

// Zero the sleep time on specified cpu.  Used to find out if
// CPU1 has a running thread system after being started:
// zeroing the recorded sleep time is otherwise undesirable.
extern void rtos_reset_sleep_time( const uint32_t cpu );


// Returns a count of the total usecs spent executing LISRs on the
// specified CPU
extern uint32_t rtos_get_lisr_time( const uint32_t cpu );

// This constant is used to specify an unlimited execution time
#define RTOS_MAX_TIME_UNLIMITED        (~0)

// Sets the upper limit on the number of usecs an LISR can take.
// Exceeding this limit will trigger a breakpoint on completion.
// Returns the previous limit.
extern uint32_t rtos_set_lisr_max_time( const uint32_t cpu, const uint32_t limit );

/******************************************************************************
 Common RTOS functions, stored in vcfw/rtos/common.
 Note! There is only 1 copy of these functions and they do not contain platform,
 rtos or chip specific functions
 *****************************************************************************/

/******************************************************************************
 Timer funcs
 *****************************************************************************/

// forward-declare struct RTOS_TIMER
struct RTOS_TIMER;

//Callback definition for when the timer has expired
typedef void (*RTOS_TIMER_DONE_OPERATION_T)( struct RTOS_TIMER *timer, void *priv );

//The time to delay before calling the callback
typedef uint32_t RTOS_TIMER_TIME_T; /* microseconds */

typedef uint32_t RTOS_TIMER_TICKS_T;

typedef struct RTOS_TIMER
{
   RTOS_TIMER_DONE_OPERATION_T done;
   void *priv;

   /* implementation */
   RTOS_TIMER_TICKS_T ticks;
   RTOS_TIMER_TICKS_T offset;
   struct RTOS_TIMER *next;

} RTOS_TIMER_T;

// Initialises TIMER with the given parameters. Returns zero on success
extern int32_t rtos_timer_init( RTOS_TIMER_T *timer, RTOS_TIMER_DONE_OPERATION_T done, void *priv);

// Returns non-zero if TIMER is in the queue
extern int32_t rtos_timer_is_running( const RTOS_TIMER_T *timer );

// Adds TIMER to the queue to run TIMER->done(TIMER->priv) after DELAY microseconds
extern int32_t rtos_timer_set( RTOS_TIMER_T *timer, const RTOS_TIMER_TIME_T delay);

// TIMER is cancelled and then set. Returns zero if successful
extern int32_t rtos_timer_reset( RTOS_TIMER_T *timer, const RTOS_TIMER_TIME_T delay);

// TIMER is cancelled if running and the callback is not called. Returns 0 if the timer was running
extern int32_t rtos_timer_cancel( RTOS_TIMER_T *timer );

/******************************************************************************
 Malloc / free funcs
 *****************************************************************************/

#define RTOS_ALIGN_DEFAULT             4
#define RTOS_ALIGN_128BIT              16
#define RTOS_ALIGN_256BIT              32
#define RTOS_ALIGN_AXI                 RTOS_ALIGN_128BIT
#define RTOS_ALIGN_512BIT              64
#define RTOS_ALIGN_4KBYTE              4096
#define RTOS_PRIORITY_INTERNAL         9999  // must be in internal memory
#define RTOS_PRIORITY_EXTERNAL         0 // must be in external memory
#define RTOS_PRIORITY_UNIMPORTANT      1

#ifdef __VIDEOCORE4__
#define RTOS_PRIORITY_SHIFT            30
#define RTOS_ALIAS_NORMAL(x)               ((void*)(((unsigned)(x)&~0xc0000000)|0x00000000)) // normal cached data (uses main 128K L2 cache)
#define RTOS_ALIAS_L1_NONALLOCATING(x)     ((void*)(((unsigned)(x)&~0xc0000000)|0x40000000)) // coherent with L1, allocating in L2
#if defined(__BCM2708A0__) || defined(__BCM2708B0__)
// HW-2827 workaround
#define RTOS_ALIAS_COHERENT(x)             RTOS_ALIAS_L1_NONALLOCATING(x)
#else
#define RTOS_ALIAS_COHERENT(x)             ((void*)(((unsigned)(x)&~0xc0000000)|0x80000000)) // cache coherent but non-allocating
#endif
#define RTOS_ALIAS_DIRECT(x)               ((void*)(((unsigned)(x)&~0xc0000000)|0xc0000000)) // uncached
#define RTOS_IS_ALIAS_NOT_L1(x)            (((((unsigned)(x)>>30)&0x3)==1) || (((unsigned)(x)>>29)>=3))
#define RTOS_IS_ALIAS_DIRECT(x)            ((((unsigned)(x)>>30)&0x3)==3)
#else
#define RTOS_PRIORITY_SHIFT            28
#define RTOS_ALIAS_NORMAL(x)               ((void*)(((unsigned)(x)&~0xf0000000)|0x00000000)) // normal cached data (uses main 128K L2 cache)
#define RTOS_ALIAS_L1_NONALLOCATING(x)     (x)                                               // coherent with L1, allocating in L2
#define RTOS_ALIAS_COHERENT(x)             ((void*)(((unsigned)(x)&~0xf0000000)|0x20000000)) // cache coherent but non-allocating
#define RTOS_ALIAS_DIRECT(x)               ((void*)(((unsigned)(x)&~0xf0000000)|0x30000000)) // uncached
#define RTOS_IS_ALIAS_NOT_L1(x)            (1)              // compatibility with vc4
#define RTOS_IS_ALIAS_DIRECT(x)            ((((unsigned)(x)>>28)&0xf)==3)
#endif
#ifdef __VIDEOCORE4__
// RTOS_PRIORITY_L1_NONALLOCATING will skip the L1 cache, but still allocate in L2
// this is needed if VPU is communicating with hardware via memory
#define RTOS_PRIORITY_L1_NONALLOCATING         (1 << RTOS_PRIORITY_SHIFT)
#else
#define RTOS_PRIORITY_L1_NONALLOCATING         (0 << RTOS_PRIORITY_SHIFT)
#endif
#define RTOS_PRIORITY_L1L2_NONALLOCATING       (2 << RTOS_PRIORITY_SHIFT)
#define RTOS_PRIORITY_COHERENT         RTOS_PRIORITY_L1L2_NONALLOCATING
#define RTOS_PRIORITY_DIRECT           (3 << RTOS_PRIORITY_SHIFT)

extern void * const __RTOS_HEAP_END, * const __RTOS_HEAP_START;

#ifdef _VIDEOCORE

typedef struct OPAQUE_RTOS_MEMPOOL_T *rtos_mempool_t;

// Allocates memory using a priority based scheme
extern void *rtos_malloc_priority( const uint32_t size, const uint32_t align, const uint32_t priority, const char *description);

// Allocates and clears memory using a priority based scheme
extern void *rtos_calloc_priority(const uint32_t size, const uint32_t align, const uint32_t priority, const char *description);

// Re-allocates some memory (and changes it size)
extern void *rtos_realloc_256bit(void *ret, const uint32_t size);

//Routine to query how much memory is left in the system and return information about the pool
extern char *rtos_get_free_mem_info (char *result, const rtos_mempool_t pool);

//Routine to query how much free memory is available in the pool
extern uint32_t rtos_get_free_mem(const rtos_mempool_t pool);

/* return a pointer to whatever called us, which can be used as a malloc name
 * (works best before first function call in a function).
 * This should normally be used only in malloc() wrappers to avoid the
 * situation where everything gets named "abstract_malloc" or the like.
 */
#define rtos_default_malloc_name() (char const *)_vasm("bitset %D, %lr, 31")

#else //ifdef _VIDEOCORE

#define rtos_malloc_priority(size, align, priority, description)   malloc(size)
#define rtos_calloc_priority(size, align, priority, description)   calloc(1,size)
#define rtos_realloc_256bit(ret, size)   realloc(ret,size)

#define rtos_default_malloc_name() (char const *)0

#endif // ifdef _VIDEOCORE

// Malloc aliases
#ifdef NDEBUG
   #define rtos_prioritymalloc( size, align, priority, description ) rtos_malloc_priority(size, align, priority, (char const *)0)
   #define rtos_prioritycalloc( size, align, priority, description ) rtos_calloc_priority(size, align, priority, (char const *)0)
#else
   #define rtos_prioritymalloc( size, align, priority, description ) rtos_malloc_priority(size, align, priority, description)
   #define rtos_prioritycalloc( size, align, priority, description ) rtos_calloc_priority(size, align, priority, description)
#endif

#define rtos_priorityfree( buffer ) free(buffer)
#define rtos_malloc_256bit( size )  rtos_prioritymalloc(size, RTOS_ALIGN_256BIT, 100, (char const *)0)
#define rtos_free_256bit( ret ) free(ret)
#define rtos_malloc_external( size )  rtos_prioritymalloc(size, RTOS_ALIGN_DEFAULT, 1, (char const *)0)
#define rtos_malloc_external_256bit( size ) rtos_prioritymalloc(size, RTOS_ALIGN_256BIT, 1, (char const *)0);

// manipulate priority level for mallocs
extern int rtos_setpriority(const uint32_t priority);
extern int rtos_getpriority(void);

// Perform basic safety checks on a memory range
extern int rtos_memory_is_valid(void const *base, int length);

// Scan the heap for evidence of memory corruption -- returns pointer to first corrupt block or NULL if OK
extern void const *rtos_find_heap_corruption(int flags);

#define rtos_calloc(a, b) calloc( a, b )
#define rtos_malloc(size) malloc( size )

/******************************************************************************
   Power / reset functions
******************************************************************************/

// Reset the processor
void rtos_reset( void );

//Routine to initialise the relocatable heap.
void rtos_relocatable_heap_init( void );

/******************************************************************************
   Testing functions
******************************************************************************/

#ifdef TEST_ALL_FAIL
#define TEST_ALLOC_FAIL
#define TEST_OPEN_FAIL
#define TEST_READWRITE_FAIL
#endif

#if defined(TEST_ALLOC_FAIL) || defined(TEST_OPEN_FAIL) || defined(TEST_READWRITE_FAIL)
#define RESOURCE_FAILURE_TESTING
#endif

#ifdef RESOURCE_FAILURE_TESTING

extern uint32_t should_check_fail();
extern void start_resource_failure_testing();

#endif

#ifdef __cplusplus
}
#endif

#endif // RTOS_H_

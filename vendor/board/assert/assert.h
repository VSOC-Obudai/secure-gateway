#ifndef ASSERT_H
#define ASSERT_H

#ifndef NDEBUG
#ifndef ASSERT_ENABLED
#define ASSERT_ENABLED 1
#endif
#ifndef PANIC_ENABLED
#define PANIC_ENABLED 1
#endif
#else
#ifndef ASSERT_ENABLED
#define ASSERT_ENABLED 0
#endif
#endif

#ifndef PANIC_ENABLED
#define PANIC_ENABLED 0
#endif

#ifndef FORCE_CRASH
#ifndef FORCE_CRASH_DEFINED
#define FORCE_CRASH_DEFINED 1
#define FORCE_CRASH() *(volatile int*)(0) = 0
#endif
#endif

#ifndef DEBUG_BREAK
#ifndef DEBUG_BREAK_DEFINED
#define DEBUG_BREAK_DEFINED 1
#if defined __TRICORE__
#include <machine/intrinsics.h>
#define DEBUG_BREAK() _debug()
#else
#define DEBUG_BREAK() FORCE_CRASH()
#endif
#endif
#endif

#ifdef ASSERT_ENABLED
#ifndef ASSERT
#ifndef ASSERT_DEFINED
#define ASSERT_DEFINED 1
#define ASSERT(cond)                                                                                                   \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf("\nAssert (%s) failure in %s(%d)\n", #cond, __FILE__, __LINE__);                                          \
      DEBUG_BREAK();                                                                                                   \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif
#endif
#ifndef ASSERT_MSG
#ifndef ASSERT_MSG_DEFINED
#define ASSERT_MSG_DEFINED 1
#define ASSERT_MSG(cond, msg)                                                                                          \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf("\nAssert (%s) failure in %s(%d): %s\n", #cond, __FILE__, __LINE__, msg);                                 \
      DEBUG_BREAK();                                                                                                   \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif
#endif
#ifndef ASSERT_FMT
#ifndef ASSERT_FMT_DEFINED
#define ASSERT_FMT_DEFINED 1
#define ASSERT_FMT(cond, fmt)                                                                                          \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf fmt;                                                                                                      \
      DEBUG_BREAK();                                                                                                   \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif
#endif
#ifndef ASSERT_FAIL
#ifndef ASSERT_FAIL_DEFINED
#define ASSERT_FAIL_DEFINED 1
#define ASSERT_FAIL()                                                                                                  \
  do                                                                                                                   \
  {                                                                                                                    \
    printf("\nAssert failure in %s(%d)\n", __FILE__, __LINE__);                                                        \
    DEBUG_BREAK();                                                                                                     \
  } while (0)
#endif
#endif
#ifndef ASSERT_FAIL_MSG
#ifndef ASSERT_FAIL_MSG_DEFINED
#define ASSERT_FAIL_MSG_DEFINED 1
#define ASSERT_FAIL_MSG(msg)                                                                                           \
  do                                                                                                                   \
  {                                                                                                                    \
    printf("\nAssert failure in %s(%d): %s\n", __FILE__, __LINE__, msg);                                               \
    DEBUG_BREAK();                                                                                                     \
  } while (0)
#endif
#endif
#ifndef ASSERT_FAIL_FMT
#ifndef ASSERT_FAIL_FMT_DEFINED
#define ASSERT_FAIL_FMT_DEFINED 1
#define ASSERT_FAIL_FMT(fmt)                                                                                           \
  do                                                                                                                   \
  {                                                                                                                    \
    printf fmt;                                                                                                        \
    DEBUG_BREAK();                                                                                                     \
  } while (0)
#endif
#endif
#else
#ifndef ASSERT
#ifndef ASSERT_DEFINED
#define ASSERT_DEFINED 1
#define ASSERT(cond) ((void)0)
#endif
#endif
#ifndef ASSERT_MSG
#ifndef ASSERT_MSG_DEFINED
#define ASSERT_MSG_DEFINED 1
#define ASSERT_MSG(cond, msg) ((void)0)
#endif
#endif
#ifndef ASSERT_FMT
#ifndef ASSERT_FMT_DEFINED
#define ASSERT_FMT_DEFINED 1
#define ASSERT_FMT(cond, fmt) ((void)0)
#endif
#endif
#ifndef ASSERT_FAIL
#ifndef ASSERT_FAIL_DEFINED
#define ASSERT_FAIL_DEFINED 1
#define ASSERT_FAIL() ((void)0)
#endif
#endif
#ifndef ASSERT_FAIL_MSG
#ifndef ASSERT_FAIL_MSG_DEFINED
#define ASSERT_FAIL_MSG_DEFINED 1
#define ASSERT_FAIL_MSG(msg) ((void)0)
#endif
#endif
#ifndef ASSERT_FAIL_FMT
#ifndef ASSERT_FAIL_FMT_DEFINED
#define ASSERT_FAIL_FMT_DEFINED 1
#define ASSERT_FAIL_FMT(fmt) ((void)0)
#endif
#endif
#endif

#ifdef PANIC_ENABLED
#ifndef PANIC
#ifndef PANIC_DEFINED
#define PANIC_DEFINED 1
#define PANIC(cond)                                                                                                    \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf("\nPanic(%s) failure in %s(%d)\n", #cond, __FILE__, __LINE__);                                            \
      FORCE_CRASH();                                                                                                   \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif
#endif
#ifndef PANIC_MSG
#ifndef PANIC_MSG_DEFINED
#define PANIC_MSG_DEFINED 1
#define PANIC_MSG(cond, msg)                                                                                           \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf("\nPanic(%s) failure in %s(%d): %s\n", #cond, __FILE__, __LINE__, msg);                                   \
      FORCE_CRASH();                                                                                                   \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif
#endif
#ifndef PANIC_FMT
#ifndef PANIC_FMT_DEFINED
#define PANIC_FMT_DEFINED 1
#define PANIC_FMT(cond, fmt)                                                                                           \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf fmt;                                                                                                      \
      FORCE_CRASH();                                                                                                   \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif
#endif
#else
#ifndef PANIC
#ifndef PANIC_DEFINED
#define PANIC_DEFINED 1
#define PANIC(cond) ((void)0)
#endif
#endif
#ifndef PANIC_MSG
#ifndef PANIC_MSG_DEFINED
#define PANIC_MSG_DEFINED 1
#define PANIC_MSG(cond, msg) ((void)0)
#endif
#endif
#ifndef PANIC_FMT
#ifndef PANIC_FMT_DEFINED
#define PANIC_FMT_DEFINED 1
#define PANIC_FMT(cond, fmt) ((void)0)
#endif
#endif
#endif

#endif  // ASSERT_H

#ifndef ASSERT_H
#define ASSERT_H

#include <stdio.h>

#ifndef M_DEBUG_BREAK
#if defined(__TRICORE__)
#define M_DEBUG_BREAK()                                                                                                \
  do                                                                                                                   \
  {                                                                                                                    \
    {                                                                                                                  \
      __asm volatile("debug");                                                                                         \
    }                                                                                                                  \
  } while (0)
#else
#define M_DEBUG_BREAK() *(int*)(0) = 0
#endif
#endif

#ifndef M_CRASH
#define M_CRASH() *(volatile int*)(0) = 0
#endif

#ifndef NDEBUG
#ifndef M_ASSERT_ENABLED
#define M_ASSERT_ENABLED (1)
#endif
#endif

#if defined(M_ASSERT_ENABLED) && (M_ASSERT_ENABLED == 1)
#ifndef M_ASSERT
#define M_ASSERT(expr)                                                                                                 \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(expr))                                                                                                       \
    {                                                                                                                  \
      printf("Assertion failure (%s) in %s(%d)!\n", #expr, __FILE__, __LINE__);                                        \
      M_DEBUG_BREAK();                                                                                                 \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)(0));                                                                                                     \
    }                                                                                                                  \
  } while (0)
#endif

#ifndef M_ASSERT_MSG
#define M_ASSERT_MSG(expr, msg)                                                                                        \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(expr))                                                                                                       \
    {                                                                                                                  \
      printf("Assertion failure (%s) in %s(%d): %s!\n", #expr, __FILE__, __LINE__, msg);                               \
      M_DEBUG_BREAK();                                                                                                 \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif

#ifndef M_ASSERT_FMT
#define M_ASSERT_FMT(expr, fmt)                                                                                        \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(expr))                                                                                                       \
    {                                                                                                                  \
      printf fmt;                                                                                                      \
      M_DEBUG_BREAK();                                                                                                 \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif

#ifndef M_FAIL
#define M_FAIL()                                                                                                       \
  do                                                                                                                   \
  {                                                                                                                    \
    printf("Assertion failure in %s(%d)!\n", __FILE__, __LINE__);                                                      \
    M_DEBUG_BREAK();                                                                                                   \
  } while (0)
#endif

#ifndef M_FAIL_MSG
#define M_FAIL_MSG(msg)                                                                                                \
  do                                                                                                                   \
  {                                                                                                                    \
    printf("Assertion failure in %s(%d): %s\n", __FILE__, __LINE__, msg);                                              \
    M_DEBUG_BREAK();                                                                                                   \
  } while (0)
#endif

#ifndef M_FAIL_FMT
#define M_FAIL_FMT(fmt)                                                                                                \
  do                                                                                                                   \
  {                                                                                                                    \
    printf fmt;                                                                                                        \
    M_DEBUG_BREAK();                                                                                                   \
  } while (0)
#endif

#else

#ifndef M_ASSERT
#define M_ASSERT(expr) ((void)0)
#endif

#ifndef M_ASSERT_MSG
#define M_ASSERT_MSG(expr, msg) ((void)0)
#endif

#ifndef M_ASSERT_FMT
#define M_ASSERT_FMT(expr, fmt) ((void)0)
#endif

#ifndef M_FAIL
#define M_FAIL() ((void)0)
#endif

#ifndef M_FAIL_MSG
#define M_FAIL_MSG(msg) ((void)0)
#endif

#ifndef M_FAIL_FMT
#define M_FAIL_FMT(fmt) ((void)0)
#endif
#endif

#ifndef M_PANIC_ENABLED
#define M_PANIC_ENABLED (1)
#endif

#if defined(M_PANIC_ENABLED) && (M_PANIC_ENABLED == 1)
#ifndef M_PANIC
#define M_PANIC(expr)                                                                                                  \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(expr))                                                                                                       \
    {                                                                                                                  \
      printf("Fatal runtime failure (%s) in %s(%d)!\n", #expr, __FILE__, __LINE__);                                    \
      M_CRASH();                                                                                                       \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)(0));                                                                                                     \
    }                                                                                                                  \
  } while (0)
#endif

#ifndef M_PANIC_MSG
#define M_PANIC_MSG(expr, msg)                                                                                         \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(expr))                                                                                                       \
    {                                                                                                                  \
      printf("Fatal runtime failure (%s) in %s(%d): %s!\n", #expr, __FILE__, __LINE__, msg);                           \
      M_CRASH();                                                                                                       \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif

#ifndef M_PANIC_FMT
#define M_PANIC_FMT(expr, fmt)                                                                                         \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(expr))                                                                                                       \
    {                                                                                                                  \
      printf fmt;                                                                                                      \
      M_CRASH();                                                                                                       \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif

#else

#ifndef M_PANIC
#define M_PANIC(expr) ((void)0)
#endif

#ifndef M_PANIC_MSG
#define M_PANIC_MSG(expr, msg) ((void)0)
#endif

#ifndef M_PANIC_FMT
#define M_PANIC_FMT(expr, fmt) ((void)0)
#endif
#endif

#endif /* ASSERT_H */

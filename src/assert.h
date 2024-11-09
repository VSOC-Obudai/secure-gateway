#ifndef ASSERT_H
#define ASSERT_H

#include <stdio.h>

#ifndef OE_DEBUG_BREAK
#if defined(__TRICORE__)
#define OE_DEBUG_BREAK()                                                                                               \
  do                                                                                                                   \
  {                                                                                                                    \
    {                                                                                                                  \
      __asm volatile("debug");                                                                                         \
    }                                                                                                                  \
  } while (0)
#else
#define OE_DEBUG_BREAK() *(int*)(0) = 0
#endif
#endif
#ifndef OE_FORCE_CRASH
#define OE_FORCE_CRASH() *(volatile int*)(0) = 0
#endif
#ifndef NDEBUG
#ifndef OE_ASSERT_ENABLED
#define OE_ASSERT_ENABLED (1)
#endif
#ifndef OE_PANIC_ENABLED
#define OE_PANIC_ENABLED (1)
#endif
#endif
#if defined(OE_ASSERT_ENABLED) && (OE_ASSERT_ENABLED == 1)
#ifndef OE_ASSERT
#define OE_ASSERT(cond)                                                                                                \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf("Assertion failure (%s) in %s(%d)!\n", #cond, __FILE__, __LINE__);                                        \
      OE_DEBUG_BREAK();                                                                                                \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)(0));                                                                                                     \
    }                                                                                                                  \
  } while (0)
#endif
#ifndef OE_ASSERT_MSG
#define OE_ASSERT_MSG(cond, msg)                                                                                       \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf("Assertion failure (%s) in %s(%d): %s!\n", #cond, __FILE__, __LINE__, msg);                               \
      OE_DEBUG_BREAK();                                                                                                \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif
#ifndef OE_ASSERT_FMT
#define OE_ASSERT_FMT(cond, fmt)                                                                                       \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf fmt;                                                                                                      \
      OE_DEBUG_BREAK();                                                                                                \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif
#ifndef OE_FAIL
#define OE_FAIL()                                                                                                      \
  do                                                                                                                   \
  {                                                                                                                    \
    printf("Assertion failure in %s(%d)!\n", __FILE__, __LINE__);                                                      \
    OE_DEBUG_BREAK();                                                                                                  \
  } while (0)
#endif
#ifndef OE_FAIL_MSG
#define OE_FAIL_MSG(msg)                                                                                               \
  do                                                                                                                   \
  {                                                                                                                    \
    printf("Assertion failure in %s(%d): %s\n", __FILE__, __LINE__, msg);                                              \
    OE_DEBUG_BREAK();                                                                                                  \
  } while (0)
#endif
#ifndef OE_FAIL_FMT
#define OE_FAIL_FMT(fmt)                                                                                               \
  do                                                                                                                   \
  {                                                                                                                    \
    printf fmt;                                                                                                        \
    OE_DEBUG_BREAK();                                                                                                  \
  } while (0)
#endif
#else
#ifndef OE_ASSERT
#define OE_ASSERT(cond) ((void)0)
#endif
#ifndef OE_ASSERT_MSG
#define OE_ASSERT_MSG(cond, msg) ((void)0)
#endif
#ifndef OE_ASSERT_FMT
#define OE_ASSERT_FMT(cond, fmt) ((void)0)
#endif
#ifndef OE_FAIL
#define OE_FAIL() ((void)0)
#endif
#ifndef OE_FAIL_MSG
#define OE_FAIL_MSG(msg) ((void)0)
#endif
#ifndef OE_FAIL_FMT
#define OE_FAIL_FMT(fmt) ((void)0)
#endif
#endif
#if defined(OE_PANIC_ENABLED) && (OE_PANIC_ENABLED == 1)
#ifndef OE_PANIC
#define OE_PANIC(cond)                                                                                                 \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf("Fatal runtime failure (%s) in %s(%d)!\n", #cond, __FILE__, __LINE__);                                    \
      OE_FORCE_CRASH();                                                                                                \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)(0));                                                                                                     \
    }                                                                                                                  \
  } while (0)
#endif
#ifndef OE_PANIC_MSG
#define OE_PANIC_MSG(cond, msg)                                                                                        \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf("Fatal runtime failure (%s) in %s(%d): %s!\n", #cond, __FILE__, __LINE__, msg);                           \
      OE_FORCE_CRASH();                                                                                                \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif
#ifndef OE_PANIC_FMT
#define OE_PANIC_FMT(cond, fmt)                                                                                        \
  do                                                                                                                   \
  {                                                                                                                    \
    if (!(cond))                                                                                                       \
    {                                                                                                                  \
      printf fmt;                                                                                                      \
      OE_FORCE_CRASH();                                                                                                \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      ((void)0);                                                                                                       \
    }                                                                                                                  \
  } while (0)
#endif
#else
#ifndef OE_PANIC
#define OE_PANIC(cond) ((void)0)
#endif
#ifndef OE_PANIC_MSG
#define OE_PANIC_MSG(cond, msg) ((void)0)
#endif
#ifndef OE_PANIC_FMT
#define OE_PANIC_FMT(cond, fmt) ((void)0)
#endif
#endif

#ifndef OE_ASSERT_TRUE
#define OE_ASSERT_TRUE(cond) OE_ASSERT(cond)
#endif

#ifndef OE_ASSERT_FALSE
#define OE_ASSERT_FALSE(cond) OE_ASSERT(!(cond))
#endif

#endif /* ASSERT_H */

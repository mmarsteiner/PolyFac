/**
 * @file Assertions.h
 * Defines assertion macros for use in test code.
 * @author Matt Marsteiner
 */

#ifndef ASSERTIONS_H
#define ASSERTIONS_H

#define ASSERT_TRUE(expr) \
do {\
if (!(expr)) {\
FAIL(ASSERT_TRUE: expr); \
}\
} while (0)

#define ASSERT_FALSE(expr) ASSERT_TRUE(!(expr))

#define FAIL(message) \
    printf("Failed assertion in file %s on line %d:\n    Message: %s\n", __FILE__, __LINE__, #message); \
    return false;

#endif //ASSERTIONS_H

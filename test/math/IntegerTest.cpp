/**
 * @file IntegerTest.cpp
 * Implementation file for testing the Integer class.
 * @author Matt Marsteiner
 */

#include "IntegerTest.h"

#include <cstdio>

#include "../Assertions.h"
#include "../../src/math/Integer.h"


/**
 * Tests the Integer class.
 * @return true if successful, or false otherwise.
 */
bool testInteger() {
    im::Integer i;
    ASSERT_TRUE(i.equals(0));
    i = 5;
    ASSERT_TRUE(i.equals(5));
    i = i;
    ASSERT_TRUE(i.equals(5));

    ++i;
    ASSERT_TRUE(i.equals(6));
    ASSERT_TRUE(i++.equals(6));
    ASSERT_TRUE(i.equals(7));

    i += 5;
    ASSERT_TRUE(i.equals(12));
    ASSERT_TRUE((i + 5).equals(17));
    ASSERT_TRUE(i.equals(12));

    i -= 4;
    ASSERT_TRUE(i.equals(8));
    ASSERT_TRUE((i - 3).equals(5));
    ASSERT_TRUE(i.equals(8));

    --i;
    ASSERT_TRUE(i.equals(7));
    ASSERT_TRUE(i--.equals(7));
    ASSERT_TRUE(i.equals(6));

    i = 5;
    im::Integer j = 12;
    ASSERT_TRUE((i * 3).equals(15));
    ASSERT_TRUE(i.equals(5));
    ASSERT_TRUE((i * j).equals(60));
    ASSERT_TRUE(i.equals(5));
    i *= 10;
    ASSERT_TRUE(i.equals(50));

    i = 7;
    ASSERT_TRUE((i / 2).equals(3));
    i = 10;
    ASSERT_TRUE((i / 2).equals(5));
    j = i / 2;
    ASSERT_TRUE(j.equals(5));

    i = 6;
    ASSERT_TRUE((i % 5).equals(1));
    ASSERT_TRUE((i % 6).equals(0));
    im::Integer k = i % 4;
    ASSERT_TRUE(k.equals(2));

    im::Integer l = -k;
    ASSERT_TRUE(l.equals(-2));

    return true;
}


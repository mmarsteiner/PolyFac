/**
 * @file IntegerTest.cpp
 * Implementation file for testing the Integer class.
 * @author Matt Marsteiner
 */

#include "IntegerTest.h"
#include "../../src/math/Integer.h"

/**
 * Tests the Integer class.
 * @return true if successful, or false otherwise.
 */
bool testInteger() {
    im::Integer i;
    if (!i.equals(0)) return false;
    i = 5;
    if (!i.equals(5)) return false;
    i = i;
    if (!i.equals(5)) return false;
    return true;
}


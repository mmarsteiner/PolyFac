/**
 * @file RationalTest.cpp
 * Implementation file for testing the Rational class.
 * @author Matt Marsteiner
 */

#include "RationalTest.h"

#include <cstdio>

#include "../Assertions.h"
#include "../../src/math/Rational.h"

bool testRational() {
    im::Rational q = 5;
    ASSERT_TRUE(q.equals(5));
    ASSERT_TRUE(q.isInteger());

    im::Rational p = 6;
    ASSERT_FALSE(q.equals(p));
    ASSERT_TRUE(p.isInteger());

    im::Rational r(5, 4);
    ASSERT_FALSE(r.equals(q));
    ASSERT_FALSE(r.isInteger());

    q += {1, 2};
    ASSERT_TRUE(q.equals({11, 2}));

    ASSERT_TRUE((q + im::Rational(1, 2)).equals(6));
    ASSERT_TRUE(q.equals({11, 2}));

    ++q;
    ASSERT_TRUE(q.equals({13, 2}));
    ASSERT_TRUE(q++.equals({13, 2}));
    ASSERT_TRUE(q.equals({15, 2}));

    q = {1, 3};
    q -= {1, 4};
    ASSERT_TRUE(q.equals({1, 12}));
    p = {1, 12};
    ASSERT_TRUE((q - p).equals(0));

    q = 5;
    q *= {5, 3};
    ASSERT_TRUE(q.equals({25, 3}));

    q = 10;
    p = 4;
    r = q / p;
    ASSERT_TRUE(r.equals({5, 2}));

    im::Rational rInv = r.inverse();
    ASSERT_TRUE(rInv.equals({2, 5}));
    ASSERT_TRUE((-p).equals(-4));

    return true;
}


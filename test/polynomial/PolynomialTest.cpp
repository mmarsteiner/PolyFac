/**
 * @file PolynomialTest.cpp
 * Implementation file for testing the Polynomial class.
 * @author Matt Marsteiner
 */

#include <cstdio>

#include "../Assertions.h"
#include "../../src/math/Integer.h"
#include "../../src/polynomial/Polynomial.h"

bool testPolynomial() {
    pf::Polynomial<im::Integer> p;
    ASSERT_TRUE(p.getNumTerms() == 0);
    ASSERT_TRUE(p.getLeadingCoefficient().equals(0));

    // p = 3X^2
    p.addTerm(pf::Term<im::Integer>(3, 2));
    ASSERT_TRUE(p.getNumTerms() == 1);
    im::Integer i = p.getLeadingCoefficient();
    ASSERT_TRUE(i.equals(3));
    ASSERT_TRUE(p.getDegree() == 2);
    ++i;
    ASSERT_TRUE(p.getLeadingCoefficient().equals(3));

    // p = 3X^2 + 1
    p.addTerm(pf::Term<im::Integer>(1, 0));
    ASSERT_TRUE(p.getLeadingCoefficient().equals(3));
    ASSERT_TRUE(p.getDegree() == 2);
    ASSERT_TRUE(p.getNumTerms() == 2);

    // p = 4X^2 + 1
    p.addTerm(pf::Term<im::Integer>(1, 2));
    ASSERT_TRUE(p.getLeadingCoefficient().equals(4));
    ASSERT_TRUE(p.getDegree() == 2);
    ASSERT_TRUE(p.getNumTerms() == 2);

    // p = 4X^2 + 2
    p.addTerm(pf::Term<im::Integer>(1, 0));
    ASSERT_TRUE(p.getLeadingCoefficient().equals(4));
    ASSERT_TRUE(p.getDegree() == 2);
    ASSERT_TRUE(p.getNumTerms() == 2);

    pf::Polynomial<im::Integer> q = 5;
    ASSERT_TRUE(q.getDegree() == 0);
    ASSERT_TRUE(q.getNumTerms() == 1);
    ASSERT_TRUE(q.getLeadingCoefficient().equals(5));

    ASSERT_FALSE(p.equals(q));
    ASSERT_FALSE(p.equals(2));
    ASSERT_TRUE(q.equals(5));

    q = p;
    ASSERT_TRUE(q.getLeadingCoefficient().equals(4));
    ASSERT_TRUE(q.getDegree() == 2);
    ASSERT_TRUE(q.getNumTerms() == 2);
    ASSERT_TRUE(q.equals(p));

    // p = X + 1
    p = pf::Polynomial<im::Integer>(pf::Term<im::Integer>(1, 1)) + 1;
    // q = X + 2
    q = p + 1;
    // r = X^2 + 3X + 2
    pf::Polynomial<im::Integer> r = pf::Polynomial(pf::Term<im::Integer>(1, 2)) + pf::Term<im::Integer>(3, 1) + 2;

    ASSERT_TRUE(r.equals(p * q));

    // q = X
    q -= 2;
    ASSERT_TRUE(q.getNumTerms() == 1);
    ASSERT_TRUE(q.getDegree() == 1);
    ASSERT_TRUE(q.equals(pf::Term<im::Integer>(1, 1)));

    return true;
}

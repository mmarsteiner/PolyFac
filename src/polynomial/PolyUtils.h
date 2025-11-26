/**
 * @file PolyUtils.h
 * Defines certain utility methods for operations on polynomials.
 * @author Matt Marsteiner
 */

#ifndef POLYUTILS_H
#define POLYUTILS_H

#include "Polynomial.h"

namespace pf {
    class PolyUtils {
    public:
        /**
         * Performs Polynomial division. The coefficients must come from a field
         * so that division can be performed.
         * @tparam C Type of coefficient used in the polynomial.
         * @param lhs Numerator of the division.
         * @param rhs Denominator of the division.
         * @param remOut Output location for the remainder. nullptr can be
         *                  given for this argument if the remainder may be
         *                  discarded.
         * @return Quotient of the division operation.
         */
        template <typename C>
        static Polynomial<C> divide(const Polynomial<C>& lhs, const Polynomial<C>& rhs, Polynomial<C> *remOut);

        /**
         * Performs the Extended Euclidean Algorithm to find g = GCD(a,b)
         * as well as polynomials s and t such that g = sa + tb. If the output
         * location for either s or t is nullptr, the function will still
         * succeed, and that polynomial will simply not be written out.
         * @tparam C Type of coefficients used in the polynomial.
         * @param a First polynomial argument of GCD
         * @param b Second polynomial argument of GCD
         * @param sOut Output location for the polynomial s.
         * @param tOut Output location for the polynomial t.
         * @return The polynomial GCD(a,b).
         */
        template <typename C>
        static Polynomial<C> extEuclid(const Polynomial<C>& a, const Polynomial<C>& b,
            Polynomial<C> *sOut, Polynomial<C> *tOut);

    };
}

#include "PolyUtils.tpp"

#endif //POLYUTILS_H

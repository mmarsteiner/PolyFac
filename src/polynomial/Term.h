/**
 * @file Term.h
 * Defines a single term in a polynomial.
 * @author Matt Marsteiner
 */

#ifndef TERM_H
#define TERM_H
#include <assert.h>

#include "../math/CoefficientField.h"

namespace pf {
    template<typename C>
    class Term {
        static_assert(std::is_base_of_v<CoefficientDomain<C>, C>);
        static_assert(std::is_constructible_v<C, int>);
        C coefficient;
        unsigned int exponent;
    public:
        Term (int val) : Term(C(val), 0) {}

        Term(const C& coeff, unsigned int const exp) : coefficient(coeff), exponent(exp) {
        }

        Term(const Term& src) {
            coefficient = src.getCoefficient();
            exponent = src.getExponent();
        }

        Term& operator+=(const Term& rhs) {
            assert(exponent == rhs.getExponent());
            coefficient += rhs.getCoefficient();
            return *this;
        }

        friend Term operator+(const Term& lhs, const Term& rhs) {
            Term ret(lhs);
            ret += rhs;
            return ret;
        }

        C getCoefficient() const {
            return coefficient;
        }

        unsigned int getExponent() const {
            return exponent;
        }

        bool equals(const Term& other) const {
            return exponent == other.exponent && coefficient.equals(other.coefficient);
        }

        Term operator-() const {
            Term tmp(*this);
            tmp.coefficient *= -1;
            return tmp;
        }

        Term& operator*=(const Term& rhs) {
            coefficient *= rhs.coefficient;
            exponent += rhs.exponent;
            return *this;
        }

        friend Term operator*(const Term& lhs, const Term& rhs) {
            Term tmp(lhs);
            tmp *= rhs;
            return tmp;
        }

        Term& operator/=(const Term& rhs) {
            assert(!rhs.coefficient.equals(0));
            coefficient /= rhs.coefficient;
            exponent -= rhs.exponent;
            return *this;
        }

        friend Term operator/(const Term& lhs, const Term& rhs) {
            static_assert(std::is_base_of_v<CoefficientField<C>, C>);
            Term tmp(lhs);
            return tmp /= rhs;
        }
    };
} // pf

#endif //TERM_H

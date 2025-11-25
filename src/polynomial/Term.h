/**
 * @file Term.h
 * Defines a single term in a polynomial.
 * @author Matt Marsteiner
 */

#ifndef TERM_H
#define TERM_H
#include <assert.h>

namespace pf {
    template<typename C>
    class Term {
        C coefficient;
        unsigned int exponent;
    public:
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
    };
} // pf

#endif //TERM_H

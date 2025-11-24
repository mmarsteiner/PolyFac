/**
 * @file Integer.h
 * Defines a C++ wrapper for the mp_int C type defined by the imath library
 * @author Matt Marsteiner
 */

#ifndef INTEGER_H
#define INTEGER_H

extern "C" {
#include "../../lib/imath/imath.h"
}

namespace im {
    class Integer {
        mp_int value;

    public:
        /**
         * Constructs a new Integer with a value of zero.
         */
        Integer();

        /**
         * Constructs a new integer with a given value.
         * @param value Value to initialize the integer with.
         */
        Integer(int value);

        /**
         * Constructs a new Integer to be a copy of another integer.
         * @param src Old Integer to copy.
         */
        Integer(const Integer &src);

        /**
         * Copy assignment operator
         * @param other Integer on the RHS of the assignment expression.
         * @return Reference to the Integer being assigned into.
         */
        Integer &operator=(const Integer &other);

        /**
         * Determines if this Integer is equal to another Integer, based on their values.
         * @param other Other Integer to compare to.
         * @return true if the Integers are equal, or false otherwise.
         */
        bool equals(const Integer &other) const;

        /** Addition operations */

        Integer& operator+=(const Integer& rhs);
        friend Integer operator+(const Integer& lhs, const Integer& rhs);
        Integer& operator++();
        Integer operator++(int);

        /** Subtraction operations */

        Integer& operator-=(const Integer& rhs);
        friend Integer operator-(const Integer& lhs, const Integer& rhs);
        Integer& operator--();
        Integer operator--(int);

        /** Multiplication operations */

        Integer& operator*=(const Integer& rhs);
        friend Integer operator*(const Integer& lhs, const Integer& rhs);

        /** Division and Modulo operations */
        Integer& operator/=(const Integer& rhs);
        friend Integer operator/(const Integer& lhs, const Integer& rhs);
        Integer& operator%=(const Integer& rhs);
        friend Integer operator%(const Integer& lhs, const Integer& rhs);

        /**
         * Frees the Integer.
         */
        ~Integer();
    };
} // imath

#endif //INTEGER_H

/**
 * @file Rational.h
 * Header file for the Rational class, which is a wrapper for the mp_rat type in the imath library.
 * @author Matt Marsteiner
 */

#ifndef RATIONAL_H
#define RATIONAL_H

#include "CoefficientField.h"
#include "../../lib/imath/imrat.h"

namespace im {
    class Rational : public pf::CoefficientField<Rational> {
        mp_rat value;

    public:
        /**
         * Constructs a new Rational with a value of zero.
         */
        Rational();

        /**
         * Constructs a new Rational with an integer value.
         * @param value Integer value for the rational.
         */
        Rational(int value);

        /**
         * Constructs a new Rational with a numerator and denominator.
         * @param numerator Numerator for the new Rational.
         * @param denominator Denominator for the new Rational.
         */
        Rational(int numerator, int denominator);

        /**
         * Constructs a new Rational to be a copy of another.
         * @param src Rational number to copy.
         */
        Rational(const Rational& src);

        /**
         * Copy assignment operator.
         * @param other Rational on the RHS of the assignment expression.
         * @return Reference to the Rational being assigned into.
         */
        Rational &operator=(const Rational& other);

        /**
         * Determines if this Rational is equal to another one based on value.
         * @param other Other Rational to compare to.
         * @return true if they are equal, or false otherwise.
         */
        bool equals(const Rational& other) const override;

        /**
         * Determines if this Rational is an integer.
         * @return true if this Rational is an integer, or false otherwise.
         */
        bool isInteger() const;

        /** Addition operators */

        Rational &operator+=(const Rational& rhs) override;
        Rational &operator++() override;
        Rational operator++(int) override;

        /** Subtraction operators */

        Rational &operator-=(const Rational& rhs) override;
        Rational &operator--() override;
        Rational operator--(int) override;

        /** Multiplication operators */

        Rational &operator*=(const Rational& rhs) override;
        friend Rational operator*(const Rational& lhs, const Rational& rhs);

        /** Division operators */

        Rational &operator/=(const Rational& rhs) override;
        Rational inverse() const override;

        /** Unary negation */

        Rational operator-() const override;
        ~Rational() override;
    };
} // im

#endif //RATIONAL_H

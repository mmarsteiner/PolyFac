/**
 * @file FiniteField.h
 * Header file for the finite field class, which represents coefficients
 * in a finite field.
 */

#ifndef FINITEFIELD_H
#define FINITEFIELD_H
#include "CoefficientField.h"
#include "Integer.h"

namespace pf {
    /**
     * Implements a finite field that is the integers modulo some prime p
     */
    class FFElement : public im::Integer, public CoefficientField<FFElement> {
        Integer modulus;
        void reduceValue();
    public:
        /**
         * Constructs a new finite field element with a given modulus and value
         * @param modulus Modulus of the field
         * @param val value for the field element.
         */
        FFElement(int modulus, int val);

        /**
         * Constructs a new finite field element to be a copy of another.
         * @param other Other finite field element to copy.
         */
        FFElement(const FFElement& other);

        /**
         * Copy assignment operator
         * @param other Other finite field element to copy fomr
         * @return
         */
        FFElement& operator=(const FFElement& other) override;

        /**
         * Determines whether two finite field elements are equal
         * @param other Other element to compare to
         * @return true if they are equal or false otherwise
         */
        bool equals(const FFElement& other) const override;

        /* Arithmetic operators */

        FFElement& operator+=(const FFElement& other) override;
        FFElement& operator++() override;
        FFElement& operator-=(const FFElement& other) override;
        FFElement& operator--() override;
        FFElement& operator*=(const FFElement& other) override;
        FFElement& operator/=(const FFElement& other) override;

        /**
         * Gets the multiplicative inverse of the field element
         * @return multiplicative inverse of the field element
         */
        FFElement inverse() const override;
    };

} // pf

#endif //FINITEFIELD_H

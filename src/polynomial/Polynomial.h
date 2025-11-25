/**
 * @file Polynomial.h
 * This is the header file for the Polynomial component, which defines the Poylnomial class and basic methods for working with such.
 * @author Matt Marsteiner
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "Term.h"
#include <type_traits>

#include "../math/CoefficientDomain.h"

namespace pf {
    /**
     * Represents a Polynomial object.
     * @tparam C Coefficient domain
     */
    template <typename C>
    class Polynomial {
        // The coefficient domain must inherit from CoefficientDomain
        static_assert(std::is_base_of_v<CoefficientDomain<C>, C>);
        // The coefficients must be constructible from an int
        static_assert(std::is_constructible_v<C, int>);
        // The coefficients must be copyable
        static_assert(std::is_copy_constructible_v<C>);

        /** Forward declaration of the nested PolynomialNode class */
        struct PolynomialNode;
        /** Pointer to the first node in the Polynomial */
        PolynomialNode *head;
        /** Number of terms in the Polynomial */
        int numTerms;

        /** Helper function to free the terms of the polynomial */
        void freeTerms();
        /** Helper function to multiply this polynomial by a term */
        void mulTerm(const Term<C>& t);
        /** Helper function that removes any terms that are zero */
        void removeZeroTerms();
    public:
        /**
         * Gets the number of terms in the polynomial.
         * @return Number of terms in the polynomial.
         */
        int getNumTerms() const;

        /**
         * Adds a term to the polynomial.
         * @param t Term to add to the polynomial.
         */
        void addTerm(const Term<C>& t);

        /**
         * Gets the leading coefficient of the polynomial.
         * @return Leading coefficient of the polynomial.
         */
        C getLeadingCoefficient() const;

        /**
         * Gets the degree of the polynomial.
         * @return Degree of the polynomial.
         */
        unsigned int getDegree() const;

        /**
         * Determines if two Polynomials are equal to one another.
         * @return true if the Polynomials are equal, or false otherwise.
         */
        bool equals(const Polynomial& other) const;

        /**
         * Gets the leading term of the polynomial.
         * @return the leading term of the polynomial.
         */
        Term<C> getLeadingTerm() const;

        /**
         * Creates a new Polynomial which defaults to a value of zero.
         */
        Polynomial();

        /**
         * Creates a constant polynomial with a given value
         * @param val Value of the constant term.
         */
        Polynomial(int val);

        /**
         * Creates a constant polynomial with a given value
         * @param c Value of the coefficient of the zero degree term.
         */
        Polynomial(const C& c);

        /**
         * Creates a new Polynomial with a single term.
         * @param t Term to create the polynomial with.
         */
        Polynomial(const Term<C>& t);

        /**
         * Creates a new Polynomial as a copy of another.
         * @param src Other polynomial to copy.
         */
        Polynomial(const Polynomial& src);

        /**
         * Copy assignment operator.
         * @param rhs Right hand side of the assignment statement.
         * @return Reference to this Polynomial.
         */
        Polynomial& operator=(const Polynomial& rhs);

        /** Arithmetic operators */

        Polynomial& operator+=(const Polynomial& rhs);
        friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
            Polynomial lhs1(lhs);
            return lhs1 += rhs;
        }

        Polynomial& operator-=(const Polynomial& rhs);
        friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs) {
            Polynomial lhs1(lhs);
            return lhs1 -= rhs;
        }

        Polynomial& operator*=(const Polynomial& rhs);
        friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs) {
            Polynomial res;
            for (PolynomialNode *curr = lhs.head; curr != nullptr; curr = curr->next) {
                Polynomial tmp(rhs);
                tmp.mulTerm(curr->t);
                res += tmp;
            }
            return res;
        }

        /**
         * Performs Polynomial division. The coefficients must come from a field
         * so that division can be performed.
         * @param lhs Numerator of the division.
         * @param rhs Denominator of the division.
         * @param remOut Output location for the remainder. nullptr can be
         *                  given for this argument if the remainder may be
         *                  discarded.
         * @return Quotient of the division operation.
         */
        static Polynomial divide(const Polynomial& lhs, const Polynomial& rhs, Polynomial *remOut);

        /**
         * Frees the Polynomial's resources.
         */
        ~Polynomial();
    private:
        struct PolynomialNode {
            Term<C> t;
            PolynomialNode *next;
            PolynomialNode(const C& coeff, unsigned int exp, PolynomialNode *next);
            PolynomialNode(const Term<C>& t, PolynomialNode *next);
        };
    };
}

#include "Polynomial.tpp"

#endif //POLYNOMIAL_H

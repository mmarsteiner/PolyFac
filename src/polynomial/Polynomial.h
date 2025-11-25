/**
 * @file Polynomial.h
 * This is the header file for the Polynomial component, which defines the Poylnomial class and basic methods for working with such.
 * @author Matt Marsteiner
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "Term.h"

namespace pf {
    template <typename C>
    class Polynomial {
        struct PolynomialNode;
        PolynomialNode *head;
        int numTerms;

        void addTerm(Term<C> t);
    public:
        Polynomial(): head(nullptr), numTerms{0} {
        }
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

/**
 * @file Polynomial.tpp
 * Implementation file for the Polynomial component.
 * @author Matt Marsteiner
 */

#pragma once

#include "Polynomial.h"

namespace pf {

    template<typename C>
    void Polynomial<C>::addTerm(Term<C> t) {
        PolynomialNode **curr = &head;
        while (*curr->t.getExponent() > t.getExponent()) {
            curr = &(*curr->next);
        }
        if (*curr->t.getExponent == t.getExponent()) {
            *curr->t += t;
        } else {
            PolynomialNode *newNode = new PolynomialNode(t, *curr);
            *curr = newNode;
        }
    }

    template<typename C>
    Polynomial<C>::PolynomialNode::PolynomialNode(const C& coeff,
        unsigned int exp, PolynomialNode *next): t(coeff, exp), next(next) {
    }

    template<typename C>
    Polynomial<C>::PolynomialNode::PolynomialNode(const Term<C>& t,
        PolynomialNode *next): t(t), next(next) {
    }
}

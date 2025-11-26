/**
 * @file Polynomial.tpp
 * Implementation file for the Polynomial component.
 * @author Matt Marsteiner
 */

#pragma once

#include "Polynomial.h"

#include <type_traits>

namespace pf {
    template<typename C>
    void Polynomial<C>::freeTerms() {
        PolynomialNode *curr = head;
        while (curr != nullptr) {
            auto *tmp = curr->next;
            delete curr;
            curr = tmp;
        }
    }

    template<typename C>
    void Polynomial<C>::mulTerm(const Term<C>& t) {
        for (PolynomialNode *curr = head; curr != nullptr; curr = curr->next) {
            curr->t *= t;
        }
    }

    template<typename C>
    void Polynomial<C>::removeZeroTerms() {
        if (numTerms == 0)
            return;
        if (head->t.equals(0)) {
            PolynomialNode *tmp = head;
            head = head->next;
            delete tmp;
            --numTerms;
        }
        PolynomialNode *curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->t.equals(0)) {
                PolynomialNode *tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
                --numTerms;
            }
            curr = curr->next;
        }
    }

    template<typename C>
    int Polynomial<C>::getNumTerms() const {
        return numTerms;
    }

    template<typename C>
    void Polynomial<C>::addTerm(const Term<C>& t) {
        if (t.getCoefficient().equals(0)) {
            return; // adding zero should do nothing
        }
        PolynomialNode **curr = &head;
        // Insert new term in descending sorted order (highest degree at head)
        while (*curr != NULL && (*curr)->t.getExponent() > t.getExponent()) {
            curr = &(*curr)->next;
        }
        if (*curr != NULL && (*curr)->t.getExponent() == t.getExponent()) {
            (*curr)->t += t;
            removeZeroTerms();
        } else {
            PolynomialNode *newNode = new PolynomialNode(t, *curr);
            *curr = newNode;
            ++numTerms;
        }
    }

    template<typename C>
    C Polynomial<C>::getLeadingCoefficient() const {
        if (numTerms == 0) {
            return C(0);
        }
        return head->t.getCoefficient();
    }

    template<typename C>
    unsigned int Polynomial<C>::getDegree() const {
        if (numTerms == 0) {
            return 0;
            // Should be -inf or something like that, but it doesn't matter here
        }
        return head->t.getExponent();
    }

    template<typename C>
    bool Polynomial<C>::equals(const Polynomial& other) const {
        if (getNumTerms() != other.getNumTerms())
            return false;
        if (getDegree() != other.getDegree())
            return false;
        PolynomialNode *thisPtr = head;
        PolynomialNode *otherPtr = other.head;
        while (thisPtr != nullptr && otherPtr != nullptr) {
            if (!thisPtr->t.equals(otherPtr->t)) {
                return false;
            }
            thisPtr = thisPtr->next;
            otherPtr = otherPtr->next;
        }
        return thisPtr == otherPtr; // both would be nullptr if equal
    }

    template<typename C>
    Term<C> Polynomial<C>::getLeadingTerm() const {
        if (numTerms == 0)
            return 0;
        return head->t;
    }

    template<typename C>
    Polynomial<C>::Polynomial() : Polynomial(0) {
    }

    template<typename C>
    Polynomial<C>::Polynomial(int val) : Polynomial(C(val)) {
    }

    template<typename C>
    Polynomial<C>::Polynomial(const C& c) : Polynomial(Term(c, 0)){
    }

    template<typename C>
    Polynomial<C>::Polynomial(const Term<C>& t) {
        head = nullptr;
        numTerms = 0;
        addTerm(t);
    }

    template<typename C>
    Polynomial<C>::Polynomial(const Polynomial& src) {
        head = nullptr;
        numTerms = 0;
        for (PolynomialNode *curr = src.head; curr != nullptr;
             curr = curr->next) {
            addTerm(curr->t);
        }
    }

    template<typename C>
    Polynomial<C> &Polynomial<C>::operator=(const Polynomial& rhs) {
        if (this == &rhs) {
            return *this;
        }
        freeTerms();
        numTerms = 0;
        head = nullptr;
        for (PolynomialNode *curr = rhs.head; curr != nullptr;
             curr = curr->next) {
            addTerm(curr->t);
        }
        return *this;
    }

    template<typename C>
    Polynomial<C> &Polynomial<C>::operator+=(const Polynomial& rhs) {
        for (PolynomialNode *curr = rhs.head; curr != nullptr;
             curr = curr->next) {
            addTerm(curr->t);
        }
        removeZeroTerms();
        return *this;
    }

    template<typename C>
    Polynomial<C> &Polynomial<C>::operator-=(const Polynomial& rhs) {
        for (PolynomialNode *curr = rhs.head; curr != nullptr;
             curr = curr->next) {
            addTerm(-curr->t);
        }
        removeZeroTerms();
        return *this;
    }

    template<typename C>
    Polynomial<C> &Polynomial<C>::operator*=(const Polynomial& rhs) {
        Polynomial res = *this * rhs;
        return *this = res;
    }

    template<typename C>
    Polynomial<C> Polynomial<C>::divide(const Polynomial& lhs,
                                        const Polynomial& rhs, Polynomial *remOut) {

        static_assert(std::is_base_of_v<CoefficientField<C>, C>);
        assert(!rhs.equals(0));
        Polynomial quotient = 0;
        Polynomial remainder = lhs;
        while (!remainder.equals(0) && remainder.getDegree() >= rhs.getDegree()) {
            Polynomial tmp = remainder.getLeadingTerm() / rhs.getLeadingTerm();
            quotient += tmp;
            remainder -= tmp * rhs;
        }
        if (remOut != nullptr)
            *remOut = remainder;
        return quotient;
    }

    template<typename C>
    Polynomial<C>::~Polynomial() {
        freeTerms();
        numTerms = 0;
        head = nullptr;
    }

    template<typename C>
    Polynomial<C>::PolynomialNode::PolynomialNode(const C& coeff,
                                                  unsigned int exp,
                                                  PolynomialNode *
                                                  next): t(coeff, exp),
        next(next) {
    }

    template<typename C>
    Polynomial<C>::PolynomialNode::PolynomialNode(const Term<C>& t,
                                                  PolynomialNode *
                                                  next): t(t), next(next) {
    }
}

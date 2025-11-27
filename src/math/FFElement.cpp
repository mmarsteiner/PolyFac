/**
 * @file FFElement.cpp
 * Implementation of the finite field element class
 * @author Matt Marsteiner
 */

#include "FFElement.h"

#include <cassert>

namespace pf {
    void FFElement::reduceValue() {
        *this %= modulus;
    }

    FFElement::FFElement(int modulus, int val) : Integer(val), modulus(modulus) {
        reduceValue();
    }

    FFElement::FFElement(const FFElement& other) : Integer(other), modulus(other.modulus) {
    }

    FFElement& FFElement::operator=(const FFElement& other) {
        if (this == &other)
            return *this;
        Integer::operator=(other);
        modulus = other.modulus;
        return *this;
    }

    bool FFElement::equals(const FFElement& other) const {
        return modulus.equals(other.modulus) && Integer::equals(other);
    }

    FFElement& FFElement::operator+=(const FFElement& other) {
        assert(modulus.equals(other.modulus));
        Integer::operator+=(other);
        reduceValue();
        return *this;
    }

    FFElement& FFElement::operator++() {
        Integer::operator++();
        reduceValue();
        return *this;
    }

    FFElement& FFElement::operator-=(const FFElement& other) {
        assert(modulus.equals(other.modulus));
        Integer::operator-=(other);
        reduceValue();
        return *this;
    }

    FFElement& FFElement::operator--() {
        Integer::operator--();
        reduceValue();
        return *this;
    }

    FFElement& FFElement::operator*=(const FFElement& other) {
        assert(modulus.equals(other.modulus));
        Integer::operator*=(other);
        reduceValue();
        return *this;
    }

    FFElement& FFElement::operator/=(const FFElement& other) {
        assert(modulus.equals(other.modulus));
        Integer::operator*=(other.inverse());
        reduceValue();
        return *this;
    }

    FFElement FFElement::inverse() const {
        FFElement s(*this);
        extGCD(*this, modulus, &s, nullptr);
        s.reduceValue();
        return s;
    }
} // pf
/**
 * @file Rational.cpp
 * Implementation file for the Rational wrapper class.
 * @author Matt Marsteiner
 */

#include "Rational.h"

namespace im {
    Rational::Rational() : Rational(0, 1) {
    }

    Rational::Rational(int value) : Rational(value, 1) {
    }

    Rational::Rational(int numerator, int denominator) {
        value = mp_rat_alloc();
        mp_rat_init(value);
        mp_rat_set_value(value, numerator, denominator);
    }

    Rational::Rational(const Rational& src) {
        value = mp_rat_alloc();
        mp_rat_init_copy(value, src.value);
    }

    Rational& Rational::operator=(const Rational& other) {
        if (this == &other)
            return *this;
        mp_rat_copy(other.value, value);
        return *this;
    }

    bool Rational::equals(const Rational& other) const {
        return mp_rat_compare(value, other.value) == 0;
    }

    bool Rational::isInteger() const {
        return mp_rat_is_integer(value);
    }

    Rational& Rational::operator+=(const Rational& rhs) {
        mp_rat_add(value, rhs.value, value);
        return *this;
    }

    Rational& Rational::operator++() {
        return *this += 1;
    }

    Rational Rational::operator++(int) {
        Rational tmp = *this;
        operator++();
        return tmp;
    }

    Rational& Rational::operator-=(const Rational& rhs) {
        mp_rat_sub(value, rhs.value, value);
        return *this;
    }

    Rational& Rational::operator--() {
        return *this -= 1;
    }

    Rational Rational::operator--(int) {
        Rational tmp = *this;
        operator--();
        return tmp;
    }

    Rational& Rational::operator*=(const Rational& rhs) {
        mp_rat_mul(value, rhs.value, value);
        return *this;
    }

    Rational& Rational::operator/=(const Rational& rhs) {
        mp_rat_div(value, rhs.value, value);
        return *this;
    }

    Rational Rational::inverse() const {
        return 1 / *this;
    }

    Rational Rational::operator-() const {
        Rational neg = *this;
        mp_rat_neg(neg.value, neg.value);
        return neg;
    }

    Rational::~Rational() {
        mp_rat_free(value);
    }

    Rational operator+(const Rational& lhs, const Rational& rhs) {
        Rational lhs1(lhs);
        return lhs1 += rhs;
    }

    Rational operator-(const Rational& lhs, const Rational& rhs) {
        Rational lhs1(lhs);
        return lhs1 -= rhs;
    }

    Rational operator*(const Rational& lhs, const Rational& rhs) {
        Rational lhs1(lhs);
        return lhs1 *= rhs;
    }

    Rational operator/(const Rational& lhs, const Rational& rhs) {
        Rational lhs1(lhs);
        return lhs1 /= rhs;
    }
} // im

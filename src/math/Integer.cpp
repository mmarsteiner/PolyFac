/**
 * @file Integer.cpp
 * Implementation for the Integer wrapper around the mp_int type.
 * @author Matt Marsteiner
 */

#include "Integer.h"

namespace im {
    Integer::Integer() : Integer(0) {}

    Integer::Integer(int value) {
        this->value = mp_int_alloc();
        mp_int_init_value(this->value, value);
    }

    Integer::Integer(const Integer &src) {
        // Self assignment check
        if (this == &src)
            return;
        value = mp_int_alloc();
        mp_int_init_copy(value, src.value);
    }

    Integer& Integer::operator=(const Integer &other) {
        if (this == &other)
            return *this;
        mp_int_copy(other.value, value);
        return *this;
    }

    bool Integer::equals(const Integer &other) const {
        return mp_int_compare(value, other.value) == 0;
    }

    Integer& Integer::operator+=(const Integer &rhs) {
        mp_int_add(value, rhs.value, value);
        return *this;
    }

    Integer& Integer::operator++() {
        mp_int_add_value(value, 1, value);
        return *this;
    }

    Integer Integer::operator++(int) {
        Integer tmp(*this);
        operator++();
        return tmp;
    }

    Integer& Integer::operator-=(const Integer &rhs) {
        mp_int_sub(value, rhs.value, value);
        return *this;
    }

    Integer& Integer::operator--() {
        mp_int_sub_value(value, 1, value);
        return *this;
    }

    Integer Integer::operator--(int) {
        Integer tmp(*this);
        operator--();
        return tmp;
    }

    Integer& Integer::operator*=(const Integer &rhs) {
        mp_int_mul(value, rhs.value, value);
        return *this;
    }

    Integer& Integer::operator/=(const Integer &rhs) {
        mpz_t tmpRemainder;
        mp_int_init(&tmpRemainder);
        mp_int_div(value, rhs.value, value, &tmpRemainder);
        return *this;
    }

    Integer& Integer::operator%=(const Integer &rhs) {
        mp_int_mod(value, rhs.value, value);
        return *this;
    }

    Integer operator*(const Integer &lhs, const Integer &rhs) {
        Integer lhs1(lhs);
        return lhs1 *= rhs;
    }

    Integer operator%(const Integer &lhs, const Integer &rhs) {
        Integer lhs1(lhs);
        return lhs1 %= rhs;
    }

    Integer Integer::operator-() const {
        Integer tmp(*this);
        mp_int_neg(tmp.value, tmp.value);
        return tmp;
    }

    Integer::~Integer() {
        mp_int_free(value);
    }

} // imath
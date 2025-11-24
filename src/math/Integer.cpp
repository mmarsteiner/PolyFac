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

    Integer::~Integer() {
        mp_int_free(value);
    }

} // imath
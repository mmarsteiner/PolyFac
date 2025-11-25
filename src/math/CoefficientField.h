//
// Created by mmars on 11/24/2025.
//

#ifndef COEFFICIENTFIELD_H
#define COEFFICIENTFIELD_H

#include "CoefficientDomain.h"

namespace pf {
    template <typename C>
    class CoefficientField : public CoefficientDomain<C> {
    public:
        virtual ~CoefficientField() override = default;
        virtual C inverse() const = 0;
    };
} // pf

#endif //COEFFICIENTFIELD_H

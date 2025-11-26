//
// Created by mmars on 11/26/2025.
//

#include "PolyUtils.h"

namespace pf {

    template<typename C>
    Polynomial<C> PolyUtils::divide(const Polynomial<C>& lhs,
        const Polynomial<C>& rhs, Polynomial<C> *remOut) {
        // Coefficients must come from a field so that F[x] is a Euclidean domain
        static_assert(std::is_base_of_v<CoefficientField<C>, C>);
        static_assert(std::is_constructible_v<C, int>);

        assert(!rhs.equals(0));
        Polynomial<C> quotient = 0;
        Polynomial<C> remainder = lhs;
        while (!remainder.equals(0) && remainder.getDegree() >= rhs.getDegree()) {
            Polynomial<C> tmp = remainder.getLeadingTerm() / rhs.getLeadingTerm();
            quotient += tmp;
            remainder -= tmp * rhs;
        }
        if (remOut != nullptr)
            *remOut = remainder;
        return quotient;
    }

    // Algorithm pseudocode comes from "Algorithms for Computer Algebra" by
    // Geddes, Czapor, and Labahn (1992)
    template<typename C>
    Polynomial<C> PolyUtils::extEuclid(const Polynomial<C>& a,
        const Polynomial<C>& b, Polynomial<C> *sOut, Polynomial<C> *tOut) {
        // Coefficients must be from a field, otherwise the primitive Euclidean
        // algorithm is necessary
        Polynomial<C> c = a.normalPart();
        Polynomial<C> d = b.normalPart();
        Polynomial<C> c1 = 1;
        Polynomial<C> d1 = 0;
        Polynomial<C> c2 = 0;
        Polynomial<C> d2 = 1;
        while (!d.equals(0)) {
            Polynomial<C> r;
            Polynomial<C> q = divide(c, d, &r);
            Polynomial<C> r1 = c1 - q * d1;
            Polynomial<C> r2 = c2 - q * d2;
            c = d;
            c1 = d1;
            c2 = d2;
            d = r;
            d1 = r1;
            d2 = r2;
        }
        if (sOut != nullptr)
            *sOut = c1 / (a.unitPart() * c.unitPart());
        if (tOut != nullptr)
            *tOut = c2 / (b.unitPart() * c.unitPart());
        return c.normalPart();
    }
}


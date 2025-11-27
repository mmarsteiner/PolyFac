#ifndef COEFFICIENTRING_H
#define COEFFICIENTRING_H

#include <type_traits>

namespace pf {
    template <typename C>
    class CoefficientDomain {
    public:
        virtual ~CoefficientDomain() = default;
        virtual C &operator=(const C& other) = 0;
        virtual bool equals(const C& other) const = 0;
        virtual C &operator+=(const C& rhs) = 0;
        friend C operator+(const C& lhs, const C& rhs) {
            C tmp(lhs);
            return tmp += rhs;
        }
        virtual C &operator++() = 0;
        virtual C &operator-=(const C& rhs) = 0;
        friend C operator-(const C& lhs, const C& rhs) {
            C tmp(lhs);
            return tmp -= rhs;
        }
        virtual C &operator--() = 0;
        virtual C& operator*=(const C& rhs) = 0;
        friend C operator*(const C& lhs, const C& rhs) {
            C tmp(lhs);
            return tmp *= rhs;
        }
        virtual C& operator/=(const C& rhs) = 0;
        friend C operator/(const C& lhs, const C& rhs) {
            C tmp(lhs);
            return tmp /= rhs;
        }
    };
} // pf

#endif //COEFFICIENTRING_H

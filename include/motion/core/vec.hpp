#pragma once

#include <cmath>

namespace motion {

struct Vec3 {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    constexpr Vec3 operator+(const Vec3& other) const {
        return {x + other.x, y + other.y, z + other.z};
    }
    constexpr Vec3 operator-(const Vec3& other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    constexpr Vec3 operator*(double scalar) const { return {x * scalar, y * scalar, z * scalar}; }

    constexpr Vec3 operator/(double scalar) const { return {x / scalar, y / scalar, z / scalar}; }
    constexpr bool operator==(const Vec3&) const = default;
};

constexpr Vec3 operator*(double scalar, const Vec3& vec) {
    return {scalar * vec.x, scalar * vec.y, scalar * vec.z};
}
constexpr double dot(const Vec3& a, const Vec3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

inline double norm(const Vec3& vec) { return std::hypot(std::hypot(vec.x, vec.y), vec.z); }

};  // namespace motion
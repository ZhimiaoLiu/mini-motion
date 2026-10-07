#include "motion/core/vec.hpp"

#include <gtest/gtest.h>

using motion::Vec3;

TEST(Vec3Test, AddsComponentwise) {
    const Vec3 a{1.0, 2.0, 3.0};
    const Vec3 b{4.0, 5.0, 6.0};
    EXPECT_EQ(a + b, (Vec3{5.0, 7.0, 9.0}));
}

TEST(Vec3Test, SubtractsComponentwise) {
    const Vec3 a{1.0, 2.0, 3.0};
    const Vec3 b{4.0, 5.0, 6.0};
    EXPECT_EQ(a - b, (Vec3{-3.0, -3.0, -3.0}));
}

TEST(Vec3Test, MultipliesByScalarOnEitherSide) {
    const Vec3 a{1.0, 2.0, 3.0};
    EXPECT_EQ(a * 2.0, (Vec3{2.0, 4.0, 6.0}));
    EXPECT_EQ(2.0 * a, a * 2.0);
}

TEST(Vec3Test, OperatorDividesComponentwise) {
    const Vec3 a{1.0, 2.0, 3.0};
    EXPECT_EQ(a / 2.0, (Vec3{0.5, 1.0, 1.5}));
}

TEST(Vec3Test, OperatorEqualsReturnsTrueForEqualVectors) {
    const Vec3 a{1.0, 2.0, 3.0};
    const Vec3 b{1.0, 2.0, 3.0};
    EXPECT_TRUE(a == b);
}

TEST(Vec3Test, OperatorEqualsReturnsFalseForUnequalVectors) {
    const Vec3 a{1.0, 2.0, 3.0};
    const Vec3 b{4.0, 5.0, 6.0};
    EXPECT_FALSE(a == b);
}

TEST(Vec3Test, DotProductReturnsCorrectValue) {
    const Vec3 a{1.0, 2.0, 3.0};
    const Vec3 b{4.0, 5.0, 6.0};
    EXPECT_DOUBLE_EQ(motion::dot(a, b), 32.0);
}

TEST(Vec3Test, ZeroVector) {
    const Vec3 a{0.0, 0.0, 0.0};
    EXPECT_DOUBLE_EQ(motion::norm(a), 0.0);
}

TEST(Vec3Test, ExactCompareFailsAfterRounding) {
    const Vec3 a{0.1, 0.1, 0.1};
    const Vec3 b{0.2, 0.2, 0.2};
    EXPECT_NE(a + b, (Vec3{0.3, 0.3, 0.3}));
}

TEST(Vec3Test, ApproximateCompareByDistance) {
    const Vec3 sum = Vec3{0.1, 0.1, 0.1} + Vec3{0.2, 0.2, 0.2};
    EXPECT_NEAR(motion::norm(sum - Vec3{0.3, 0.3, 0.3}), 0.0, 1e-12);
}

TEST(Vec3Test, NormOf345TriangleIsFive) {
    EXPECT_DOUBLE_EQ(motion::norm(Vec3{3.0, 4.0, 0.0}), 5.0);
}

static_assert(Vec3{1.0, 2.0, 3.0} + Vec3{1.0, 1.0, 1.0} == Vec3{2.0, 3.0, 4.0});
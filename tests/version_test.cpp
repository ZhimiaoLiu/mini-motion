#include "motion/version.hpp"

#include <gtest/gtest.h>

TEST(Version, MatchesCMakeProjectVersion) { EXPECT_EQ(motion::version(), MOTION_EXPECTED_VERSION); }

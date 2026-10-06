#pragma once

#include <string_view>

namespace motion {

/// Library version in "MAJOR.MINOR.PATCH" form, taken from the CMake project version.
[[nodiscard]] std::string_view version() noexcept;

}  // namespace motion

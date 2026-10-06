# mini-motion

[![CI](https://github.com/ZhimiaoLiu/mini-motion/actions/workflows/ci.yml/badge.svg)](https://github.com/ZhimiaoLiu/mini-motion/actions/workflows/ci.yml)

A small multi-axis motion controller simulator written in modern C++ (C++23).

It reads a subset of G-code, plans acceleration-limited trajectories, and runs them in a
fixed-period control loop, so the resulting position and velocity profiles can be inspected
and plotted.

> **Status:** early development (v0.1 in progress). See the roadmap below.

## Roadmap

- [ ] **v0.1**: G-code parser (G0/G1), trapezoidal velocity profile, CSV output
- [ ] **v0.2**: Circular interpolation (G2/G3), S-curve profile, look-ahead velocity planning
- [ ] **v0.3**: 1 ms fixed-period control loop, motor model + PID (with anti-windup), visualization
- [ ] **v1.0**: Run on real hardware (Raspberry Pi Pico / STM32 + stepper motors)

## Build

Requirements: CMake 3.25+, Ninja, and a C++23 compiler (GCC 13+, Clang 19+, Apple Clang from
Xcode 16+, or MSVC 2022).

**Linux / macOS** (on macOS, use `macos-debug` instead of `linux-debug`)

```sh
cmake --preset linux-debug
cmake --build --preset linux-debug
ctest --preset linux-debug
```

On macOS, install the tools with `brew install cmake ninja`. In VS Code, the CMake Tools
extension picks up the presets automatically.

**Windows (Visual Studio 2022)**: open the folder (*File → Open → Folder*), choose the
**Windows Debug (MSVC)** preset, then *Build → Build All* and run the tests from *Test Explorer*.

Other presets: `*-release`, and `*-asan` (AddressSanitizer; plus UBSan on Linux and macOS).

## Project layout

```
include/motion/   public headers
src/              library implementation (motion_core)
apps/simulate/    command-line simulator
tests/            unit tests (GoogleTest)
cmake/            shared CMake settings (warnings, sanitizers)
```

## License

[MIT](LICENSE)

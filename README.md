# cmake_template

`cmake_template` is a modern C++ CMake project template. It is intentionally small at
the application layer and more complete at the build-system layer, so it can be
used as a starting point for a real executable project.

## What is included

- CMake presets for MSVC and clang-cl on Windows, and GCC/Clang on Unix-like systems.
- CPM-based third-party dependency setup.
- Interface targets for project warnings and project options.
- Optional hardening, sanitizers, IPO/LTO, unity builds, precompiled headers, ccache,
  clang-tidy, cppcheck, coverage, and fuzz testing.
- A small CLI executable using CLI11, fmt, and spdlog.
- Catch2 unit tests and CTest smoke tests for `--help` and `--version`.
- Optional WebAssembly support for Emscripten builds.

## Requirements

- CMake 3.29 or newer.
- Ninja, or another CMake generator if you customize the presets.
- A C++ compiler with C++23 support.

## Configure and build

List the available presets:

```sh
cmake --list-presets
```

Configure and build on Windows with MSVC:

```sh
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug
```

Configure and build on Windows with clang-cl:

```sh
cmake --preset windows-clang-debug
cmake --build --preset windows-clang-debug
```

On Linux or macOS, use one of the Unix-like presets:

```sh
cmake --preset unixlike-clang-debug
cmake --build --preset unixlike-clang-debug
```

## Test

```sh
ctest --preset test-windows-msvc-debug
```

or run CTest directly from a build directory:

```sh
ctest --test-dir out/build/windows-msvc-debug --output-on-failure
```

## Project layout

- `src/` contains the executable target.
- `include/` contains public example headers.
- `test/` contains Catch2 tests.
- `fuzz_test/` contains a libFuzzer target.
- `configured_files/` contains generated build metadata headers.
- `cmake/` contains reusable CMake helper modules.

## Renaming the template

For a new project, update these identifiers first:

- The `project(...)` name in `CMakeLists.txt`.
- The include namespace/path under `include/`.
- The `myproject_*` CMake option prefix if you want project-specific cache options.
- `.github/constants.env` if you keep the template cleanup workflow.

The executable target is derived from `${PROJECT_NAME}`, so renaming the CMake
project also renames the built application and CLI smoke tests.

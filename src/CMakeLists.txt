add_executable(main main.cpp
)

target_link_libraries(
  main
  PRIVATE myproject::myproject_options
          myproject::myproject_warnings
          CLI11::CLI11
          fmt::fmt
          spdlog::spdlog)


myproject_configure_linker(main)

target_include_directories(main PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include"
                                    "${CMAKE_SOURCE_DIR}/src" )

# Apply WASM-specific configuration
if(EMSCRIPTEN)
  myproject_configure_wasm_target(main
    TITLE "main Framework"
    DESCRIPTION "main Framework"
  )
endif()

#include <CLI/CLI.hpp>
#include <fmt/format.h>
#include <internal_use_only/config.hpp>
#include <spdlog/spdlog.h>

int main(int argc, char **argv)
{
  CLI::App app{fmt::format("{} command line application", myproject::cmake::project_name)};
  app.set_version_flag("--version", std::string{myproject::cmake::project_version});

  bool verbose = false;
  app.add_flag("-v,--verbose", verbose, "Enable verbose logging");

  CLI11_PARSE(app, argc, argv);

  if(verbose) { spdlog::set_level(spdlog::level::debug); }

  spdlog::debug("Git SHA: {}", myproject::cmake::git_sha);
  fmt::println("Hello from {} {}", myproject::cmake::project_name, myproject::cmake::project_version);
  return 0;
}

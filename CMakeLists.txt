project(Glovebox)
cmake_minimum_required(VERSION 2.4.0)

set(PLUGIN_DIR
  ${CMAKE_INSTALL_PREFIX}/share/Glovebox/plugins
)

message("Plugins will be installed to ${PLUGIN_DIR}")

add_subdirectory(Launchpad)

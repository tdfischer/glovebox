project(Glovebox)
cmake_minimum_required(VERSION 2.4.0)

set(LAUNCHPAD_PLUGIN_DIR
  ${CMAKE_INSTALL_PREFIX}/share/Launchpad/plugins
)

message("Plugins will be installed to ${LAUNCHPAD_PLUGIN_DIR}")

set(LAUNCHPAD_INCLUDES
  ${CMAKE_CURRENT_SOURCE_DIR}/Launchpad/src
)

include_directories(${LAUNCHPAD_INCLUDES})

add_subdirectory(Launchpad)
add_subdirectory(GpsService)

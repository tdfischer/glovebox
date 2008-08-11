project(Glovebox)
cmake_minimum_required(VERSION 2.4.0)

set(GLOVEBOX_DATA_DIR
  ${CMAKE_INSTALL_PREFIX}/share
)

set(LAUNCHPAD_PLUGIN_DIR
  ${CMAKE_INSTALL_PREFIX}/lib/Launchpad/plugins
)

message("Plugins will be installed to ${LAUNCHPAD_PLUGIN_DIR}")

set(LAUNCHPAD_INCLUDES
  ${CMAKE_CURRENT_SOURCE_DIR}/Launchpad/src
)

set(GLOVEUI_INCLUDES
  ${CMAKE_CURRENT_SOURCE_DIR}/gloveui
)

include_directories(${LAUNCHPAD_INCLUDES})
include_directories(${GLOVEUI_INCLUDES})

add_subdirectory(gloveui)
add_subdirectory(Launchpad)
add_subdirectory(GpsService)
add_subdirectory(MapPage)
add_subdirectory(MediaPlayer)
add_subdirectory(NetworkStatus)

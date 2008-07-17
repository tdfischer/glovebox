find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})


set(Launchpad_SRCS
  Launchpad.cpp
  LaunchpadService.cpp
  main.cpp
  PluginManager.cpp
  ServiceManager.cpp
  Splash.cpp
)

set(Launchpad_HEADERS
  Launchpad.h
  PluginManager.h
  ServiceManager.h
  Splash.h
  LaunchpadService.h
  LaunchpadPlugin.h
)

qt4_automoc(${Launchpad_SRCS})

qt4_add_resources(Launchpad_SRCS splash.qrc)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h
${CMAKE_CURRENT_BINARY_DIR}/config.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${QT_INCLUDES} ${QT_INCLUDE_DIR}/phonon)

add_definitions(${QT_DEFINITIONS})

add_subdirectory(HomePage)

add_executable(Launchpad ${Launchpad_SRCS})
target_link_libraries(Launchpad ${QT_LIBRARIES} ${QT_LIBRARY_DIR}/libphonon.so
HomePage)

install(TARGETS Launchpad DESTINATION bin)

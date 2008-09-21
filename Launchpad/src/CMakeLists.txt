find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})


set(Launchpad_SRCS
  LaunchpadApp.cpp
  main.cpp
  Launcher.cpp
  Page.cpp
  Service.cpp
  PluginManager.cpp
  ServiceManager.cpp
  Splash.cpp
  PageListModel.cpp
  PageListDelegate.cpp
  PageManager.cpp
)

set(Launchpad_HEADERS
  LaunchpadApp.h
  PluginManager.h
  ServiceManager.h
  Launcher.h
  Splash.h
  Service.h
  Page.h
  PageListModel.h
  PageListDelegate.h
  InvalidService.h
  PageManager.h
)

qt4_automoc(${Launchpad_SRCS})

qt4_add_resources(Launchpad_SRCS splash.qrc)

configure_file(config.h.cmake
${CMAKE_CURRENT_BINARY_DIR}/config.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${QT_INCLUDES} ${GLOVEUI_INCLUDES})

add_definitions(${QT_DEFINITIONS})

add_subdirectory(BasicPlugins)

add_executable(Launchpad ${Launchpad_SRCS})
target_link_libraries(Launchpad ${QT_LIBRARIES} BasicPlugins gloveui)

install(TARGETS Launchpad DESTINATION bin)
install(FILES ${Launchpad_HEADERS} DESTINATION include/Launchpad)

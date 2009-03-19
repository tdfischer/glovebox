set(Launchpad_SRCS
  LaunchpadApp.cpp
  main.cpp
  Launcher.cpp
  PageModel.cpp
  modeltest.cpp
)

set(Launchpad_HEADERS
  LaunchpadApp.h
  Launcher.h
  PageModel.h
)

configure_file(config.h.cmake
${CMAKE_CURRENT_BINARY_DIR}/config.h)

include_directories(${GLOVEUI_INCLUDES})


kde4_add_executable(Launchpad ${Launchpad_SRCS})
target_link_libraries(Launchpad ${QT_LIBRARIES} ${KDE4_KDEUI_LIBS}
liblaunchpad gloveui)

install(TARGETS Launchpad DESTINATION bin)
install(FILES ${Launchpad_HEADERS} DESTINATION include/Launchpad)

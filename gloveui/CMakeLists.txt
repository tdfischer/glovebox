project(gloveui)

find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})


set(gloveui_SRCS
  GIcon.cpp
  GStandardDirs.cpp
  GIconLoader.cpp
)

set(gloveui_HEADERS
  GIcon.h
  GStandardDirs.h
  Glovebox.h
  GIconLoader.h
)

configure_file(config.h.cmake
${CMAKE_CURRENT_BINARY_DIR}/config.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${QT_INCLUDES})

add_definitions(${QT_DEFINITIONS})

add_library(gloveui SHARED ${gloveui_SRCS})
target_link_libraries(gloveui ${QT_LIBRARIES})

install(TARGETS gloveui DESTINATION lib)
install(FILES ${gloveui_HEADERS} DESTINATION include)

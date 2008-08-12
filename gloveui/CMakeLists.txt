project(gloveui)

find_package(Qt4 REQUIRED)
find_package(Phonon REQUIRED)

include(${QT_USE_FILE})


set(gloveui_SRCS
  GIcon.cpp
  GStandardDirs.cpp
  GIconLoader.cpp
  GSoundLoader.cpp
  GNotify.cpp
)

# List of headers to be installed
set(gloveui_HEADERS
  GIcon.h
  GStandardDirs.h
  Glovebox.h
  GIconLoader.h
  GSoundLoader.h
  GNotify.h
)

qt4_automoc(${gloveui_SRCS})

configure_file(config.h.cmake
${CMAKE_CURRENT_BINARY_DIR}/config.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${QT_INCLUDES} ${PHONON_INCLUDES})

add_definitions(${QT_DEFINITIONS})

add_library(gloveui SHARED ${gloveui_SRCS})
target_link_libraries(gloveui ${QT_LIBRARIES} ${PHONON_LIBS})

install(TARGETS gloveui DESTINATION lib)
install(FILES ${gloveui_HEADERS} DESTINATION include)

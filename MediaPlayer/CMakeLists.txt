project(MediaService)
find_package(Qt4 REQUIRED)
find_package(Phonon REQUIRED)

include(${QT_USE_FILE})

set(MediaService_SRCS
	MediaService.cpp
)

qt4_automoc(${MediaService_SRCS})

add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${LAUNCHPAD_INCLUDES} ${PHONON_INCLUDES} ${QTCORE_INCLUDES})

add_library(MediaService MODULE ${MediaService_SRCS})
target_link_libraries(MediaService ${QT_LIBRARIES} ${PHONON_LIBS})

install(TARGETS MediaService DESTINATION ${LAUNCHPAD_PLUGIN_DIR})

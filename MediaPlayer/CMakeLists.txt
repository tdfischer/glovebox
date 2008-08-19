project(MediaService)
find_package(Qt4 REQUIRED)
find_package(Phonon REQUIRED)

include(${QT_USE_FILE})

set(MediaService_SRCS
	MediaService.cpp
)

set(MediaPage_SRCS
  MediaPage.cpp
)

qt4_automoc(${MediaService_SRCS} ${MediaPage_SRCS})

add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${LAUNCHPAD_INCLUDES} ${PHONON_INCLUDES} ${QTCORE_INCLUDES})

add_library(MediaService MODULE ${MediaService_SRCS})
add_library(MediaPage MODULE ${MediaPage_SRCS})
target_link_libraries(MediaService ${QT_LIBRARIES} ${PHONON_LIBS})
target_link_libraries(MediaPage ${QT_LIBRARIES})

install(TARGETS MediaService MediaPage DESTINATION ${LAUNCHPAD_PLUGIN_DIR})

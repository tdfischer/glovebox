project(NetworkService)
find_package(Qt4 REQUIRED)
find_package(Phonon REQUIRED)

set(QT_USE_QTDBUS true)
set(QT_USE_QTNETWORK true)

include(${QT_USE_FILE})

set(NetworkService_SRCS
	NetworkService.cpp
)

qt4_automoc(${NetworkService_SRCS})

add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${LAUNCHPAD_INCLUDES} ${PHONON_INCLUDES} ${QTCORE_INCLUDES})

add_library(NetworkService MODULE ${NetworkService_SRCS})
target_link_libraries(NetworkService ${QT_LIBRARIES} ${PHONON_LIBRARIES})

install(TARGETS NetworkService DESTINATION ${LAUNCHPAD_PLUGIN_DIR})

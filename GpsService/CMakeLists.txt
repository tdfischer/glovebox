project(GpsService)
find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})

find_package(PkgConfig REQUIRED)

pkg_check_modules(libgps libgps REQUIRED)

set(GpsService_SRCS
	GpsService.cpp
  GpsListener.cpp
)

qt4_automoc(${GpsService_SRCS})

add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${LAUNCHPAD_INCLUDES} ${libgps_INCLUDE_DIRS} ${QT_INCLUDES})

add_library(GpsService MODULE ${GpsService_SRCS})
target_link_libraries(GpsService ${QT_LIBRARIES} ${libgps_LDFLAGS})

install(TARGETS GpsService DESTINATION ${LAUNCHPAD_PLUGIN_DIR})


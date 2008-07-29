project(MapPage)
find_package(Qt4 REQUIRED)
find_package(Marble REQUIRED)

include(${QT_USE_FILE})

set(GpsPage_SRCS
  GpsPage.cpp
)

qt4_automoc(${GpsPage_SRCS})

add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${LAUNCHPAD_INCLUDES} ${QT_INCLUDES})

include_directories(${MARBLE_INCLUDES})

add_library(GpsPage MODULE ${GpsPage_SRCS})
target_link_libraries(GpsPage ${QT_LIBRARIES} ${MARBLE_LIBRARIES})

install(TARGETS GpsPage DESTINATION ${LAUNCHPAD_PLUGIN_DIR})

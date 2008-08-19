project(MapPage)
find_package(Qt4 REQUIRED)
find_package(Marble REQUIRED)

include(${QT_USE_FILE})

set(MapPage_SRCS
  MapPage.cpp
  CompassWidget.cpp
  SignalWidget.cpp
)

qt4_automoc(${MapPage_SRCS})

add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${LAUNCHPAD_INCLUDES} ${QT_INCLUDES})

include_directories(${MARBLE_INCLUDES})

add_library(MapPage MODULE ${MapPage_SRCS})
target_link_libraries(MapPage ${QT_LIBRARIES} ${MARBLE_LIBRARIES})

install(TARGETS MapPage DESTINATION ${LAUNCHPAD_PLUGIN_DIR})

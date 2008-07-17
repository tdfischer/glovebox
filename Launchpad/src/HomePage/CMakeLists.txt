set(Homepage_SRCS
  HomePage.cpp
)

set(Homepage_HEADERS
  HomePage.h
)

qt4_automoc(${Homepage_SRCS})

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${QT_INCLUDES})

add_library(HomePage STATIC ${Homepage_SRCS})

add_definitions(${QT_DEFINITIONS} -DQT_STATICPLUGIN)

target_link_libraries(HomePage ${QT_LIBRARIES})

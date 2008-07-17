set(BasicPlugins_SRCS
  HomePage.cpp
  SettingsPage.cpp
)

qt4_automoc(${BasicPlugins_SRCS})

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${QT_INCLUDES})

add_library(BasicPlugins STATIC ${BasicPlugins_SRCS})

add_definitions(${QT_DEFINITIONS} -DQT_STATICPLUGIN)

target_link_libraries(BasicPlugins ${QT_LIBRARIES})

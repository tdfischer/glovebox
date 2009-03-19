project(liblaunchpad)

set(liblaunchpad_SRCS
  Page.cpp
)

kde4_add_library(liblaunchpad SHARED ${liblaunchpad_SRCS})
target_link_libraries(liblaunchpad ${QT_LIBRARIES} ${KDE4_KDEUI_LIBS})
install(TARGETS liblaunchpad DESTINATION lib)

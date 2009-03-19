project(cluster)
set(cluster_SRCS
  cluster.cpp
)

kde4_add_plugin(launchpad_page_cluster ${cluster_SRCS})
target_link_libraries(launchpad_page_cluster liblaunchpad ${QT_LIBRARIES}
${KDE4_KDEUI_LIBS} ${KDE4_PLASMA_LIBS} ${KDE4_KPARTS_LIBS} )
install(TARGETS launchpad_page_cluster DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES launchpad-page-cluster.desktop DESTINATION ${SERVICES_INSTALL_DIR})

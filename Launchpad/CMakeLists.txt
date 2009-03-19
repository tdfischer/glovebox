find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

find_package(KDE4 REQUIRED)
include(KDE4Defaults)

include_directories(lib/launchpad)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(pages)

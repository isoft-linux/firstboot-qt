# utils

cmake_minimum_required(VERSION 2.8.11)
set(TARGET utils)

set_source_files_properties(
                   utils_h PROPERTIES EXTERNAL_OBJECT TRUE GENERATED TRUE)

find_package(PkgConfig REQUIRED)
#pkg_check_modules(GNOME_DESKTOP REQUIRED gnome-desktop-3.0)
pkg_check_modules(FONT_CONFIG REQUIRED fontconfig)

set(LIB_SRC utils.c)

include_directories(${GTK3_INCLUDE_DIRS})
include_directories(${GNOME_DESKTOP_INCLUDE_DIRS})
include_directories(${FONT_CONFIG_INCLUDE_DIRS})

add_library(${TARGET} ${LIB_SRC})
target_link_libraries(${TARGET} ${GTK3_LIBRARIES} ${GNOME_DESKTOP_LIBRARIES} ${FONT_CONFIG_LIBRARIES})



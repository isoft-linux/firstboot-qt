cmake_minimum_required(VERSION 2.8.11)
set(TARGET firstboot-qt)
set(DATA_PATH ${CMAKE_INSTALL_PREFIX}/share/apps/firstboot/)
set(FACE_PATH ${CMAKE_INSTALL_PREFIX}/share/icons/)

project({TARGET})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(PkgConfig REQUIRED)
add_definitions(-DTRANSLATION_DOMAIN=\"firstboot-qt\")
add_definitions(-Werror -DQT_NO_KEYWORDS)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GLIB REQUIRED glib-2.0)
##pkg_check_modules(GNOME_DESKTOP REQUIRED gnome-desktop-3.0)
pkg_check_modules(FONT_CONFIG REQUIRED fontconfig)

add_definitions(${Qt5Widgets_DEFINITIONS})

find_package(Qt5Widgets)
find_package(Qt5LinguistTools)
find_package(KF5I18n NO_MODULE)

include_directories(
    ${QT_INCLUDES}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${GNOME_DESKTOP_INCLUDE_DIRS}
    ${GLIB_INCLUDE_DIRS}
    ${GTK3_INCLUDE_DIRS}
    ${FONT_CONFIG_INCLUDE_DIRS}
)

add_subdirectory(liblang)
add_subdirectory(libtimezone)
add_subdirectory(po)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable(firstboot-qt main.cpp lang.cpp configdialog.cpp timezone.cpp userinfo.cpp welcome.cpp)

target_link_libraries(
    firstboot-qt 
    utils
    timezone
    Qt5::Widgets
    KF5::I18n
    ${GLIB_LIBRARIES}
    ${GTK3_LIBRARIES}
    ${GNOME_DESKTOP_LIBRARIES}
)


configure_file(${PROJECT_SOURCE_DIR}/config.h.in ${PROJECT_SOURCE_DIR}/config.h @ONLY)

install(TARGETS ${TARGET} RUNTIME DESTINATION bin PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE SETUID GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/data/license DESTINATION ${DATA_PATH}/data)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/data/timezone DESTINATION ${DATA_PATH}/data)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/data/images DESTINATION ${DATA_PATH}/data)
#install(DIRECTORY ${PROJECT_SOURCE_DIR}/data/account/faces DESTINATION ${FACE_PATH}/users)
install(FILES ${PROJECT_SOURCE_DIR}/data/firstboot.service DESTINATION /usr/lib/systemd/system)
install(FILES ${PROJECT_SOURCE_DIR}/data/run-firstboot DESTINATION /usr/bin
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ
        GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)



cmake_minimum_required (VERSION 2.6)

#ROOT cmakelist

project (my_browser)

set(QT_USE_QTOPENGL TRUE)
FIND_PACKAGE(Qt4 COMPONENTS QtCore QtGui QtSql QtOpenGL REQUIRED)

# The version number.
set (my_browser_VERSION_MAJOR 0)
set (my_browser_VERSION_MINOR 1)

#Compilation en Release ou Debug
set(CMAKE_BUILD_TYPE Debug)

## Option de profiling
set (CMAKE_CXX_FLAGS_DEBUG "-W -Wall -Wuninitialized -O0 -g3 -D_DEBUG")
set (CMAKE_CXX_FLAGS_RELEASE "-W -Wall -Wuninitialized -O3 -shared")

SET(CMAKE_CXX_SOURCE_FILE_EXTENSIONS
   ${CMAKE_CXX_SOURCE_FILE_EXTENSIONS}
   ui
   qrc
)

#Rajout des include QT
include(${QT_USE_FILE})

INCLUDE (CheckIncludeFile)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h

include_directories("${PROJECT_BINARY_DIR}"
  ${PROJECT_BINARY_DIR}/gui
  gui/inc
  ${QT_QTOPENGL_INCLUDE_DIR}
)
set (qtc "QtCore")

set (EXTRA_LIBS ${EXTRA_LIBS}
  "gui"
  ${QT_QTCORE_LIBRARY}
)

# Compilation des fichiers de langue et des ressources
file(GLOB_RECURSE RESS *.qrc)

QT4_ADD_RESOURCES(RES ${RESS})

add_subdirectory (gui)

# Declaration de l'exe et des fichiers sources le constituant
add_executable(my_browser
  main.cpp
  ${RES})

#linkage des librairies au projet SACA
target_link_libraries (my_browser ${EXTRA_LIBS} )

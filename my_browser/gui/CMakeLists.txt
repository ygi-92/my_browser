
FIND_PACKAGE(Qt4 COMPONENTS QtCore QtGui REQUIRED)

include(${QT_USE_FILE})

set(source_files
  ./src/mainwindow.cpp
)

set(inc_files
  ./inc/mainwindow.hpp
)

set(ui
  ./ui/mainwindow.ui
)

set (ress

)

QT4_WRAP_UI(qt_ui
  ${ui}
)

QT4_WRAP_CPP(qt_moc
  ${inc_files}
)

QT4_ADD_RESOURCES(ressource
  ${ress}
)


# Don't forget to include output directory, otherwise
# the UI file won't be wrapped!
include_directories(${CMAKE_CURRENT_BINARY_DIR} inc)
message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
#Now add these generated files to the ADD_EXECUTABLE step
# If this is NOT done, then the ui_*.h files will not be generated
#add_executable(qtproject ${source_files} ${qt_ui} )

# link the "qtproject" target against the Qt libraries. which libraries exactly, is defined by the "include(${QT_USE_FILE})" line above, which sets up this variable.

add_library(gui
  ${qt_moc}
  ${source_files}
  ${qt_ui}
  ${ressource})

target_link_libraries (gui ${QT_LIBRARIES})

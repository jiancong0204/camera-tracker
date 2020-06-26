cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(CameraTracker)

#OpenCV
set(OpenCV_DIR "/opt/opencv-4.1.2/build")
find_package(OpenCV REQUIRED)

# QT
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
qt5_wrap_ui(UI_FILES src/TrackerGUI.ui)

# Pylon5
## Translate from Makefile of the sample
set(PYLON_ROOT "/opt/pylon5")

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PYLON_ROOT}/include")

EXEC_PROGRAM("${PYLON_ROOT}/bin/pylon-config" ARGS --cflags OUTPUT_VARIABLE CPPFLAGS)
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CPPFLAGS}" CACHE STRING "CPPFLAGS")
SET(CPPFLAGS "${CPPFLAGS}" CACHE STRING "CPPFLAGS")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CPPFLAGS}")

EXEC_PROGRAM("${PYLON_ROOT}/bin/pylon-config" ARGS --libs-rpath OUTPUT_VARIABLE LDFLAGS)
#SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LDFLAGS}" CACHE STRING "LDFLAGS")
SET(LDFLAGS "${LDFLAGS}" CACHE STRING "LDFLAGS")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LDFLAGS}")

EXEC_PROGRAM("${PYLON_ROOT}/bin/pylon-config" ARGS --libs OUTPUT_VARIABLE PYLON_LIBS)
SET(PYLON_LIBS "${PYLON_LIBS}" CACHE STRING "PYLON_LIBS")

# Zbar
SET(ZBAR_LINK_DIRS
    /usr/lib/aarch64-linux-gnu
)

link_directories(
    ${ZBAR_LINK_DIRS}
)

# Include directories
include_directories( 
    include
    ${OpenCV_INCLUDE_DIRS}
    )

# Source files
SET(BASLER_CAMERA
    src/BaslerGigECamera.cpp
    src/GenericCamera.cpp
    src/TimedFrame.cpp
)

SET(source_codes
    main.cpp
    src/Scanner.cpp
    src/Chessboard.cpp
    src/ChessboardDetector.cpp
    ${BASLER_CAMERA}
    src/Conex.cpp
    src/RotationStage.cpp
    src/JsonUtilization.cpp
    src/PoseEstimation.cpp
    src/Tracker.cpp
    src/TrackerGUI.cpp
)

add_executable(camera_tracker 
    ${source_codes} 
    ${UI_FILES}
    include/TrackerGUI.h
    include/Tracker.h
)

target_link_libraries(camera_tracker 
    ${OpenCV_LIBS} 
    ${PYLON_LIBS}
    zbar
    Qt5::Widgets
)

qt5_use_modules(camera_tracker Widgets)

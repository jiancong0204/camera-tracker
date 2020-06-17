cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(CameraTracker)

#OpenCV
find_package(OpenCV REQUIRED)

# QT
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)


# Set environment for Pylon
## Translate from Makefile of the samples
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

EXEC_PROGRAM("${PYLON_ROOT}/bin/pylon-config" ARGS --libs OUTPUT_VARIABLE LDLIBS)
SET(LDLIBS "${LDLIBS}" CACHE STRING "LDLIBS")

# zbar
SET(ZBAR_LINK_DIRS
    /usr/lib/aarch64-linux-gnu
)

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
    src/GUI.cpp
)


link_directories(
    ${ZBAR_LINK_DIRS}
)

add_executable(camera_tracker ${source_codes})

target_link_libraries(camera_tracker 
    ${OpenCV_LIBS} 
    ${LDLIBS}
    zbar
    Qt5::Widgets
)

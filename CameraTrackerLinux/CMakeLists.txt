cmake_minimum_required(VERSION 2.8)
project(CameraTracker)
find_package(OpenCV REQUIRED)

# Set environment for Pylon
SET(PYLON_INCLUDE_DIRS
    /opt/pylon5/include
)

SET(PYLON_LINK_DIRS
    /opt/pylon5/lib64
)   

# zbar
SET(ZBAR_LINK_DIRS
    /usr/lib/aarch64-linux-gnu
)

include_directories( 
    include
    ${OpenCV_INCLUDE_DIRS}
    ${PYLON_INCLUDE_DIRS}
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
)


link_directories(
    ${PYLON_LINK_DIRS}
    ${ZBAR_LINK_DIRS}
)

add_executable(camera_tracker ${source_codes})

target_link_libraries(camera_tracker 
    ${OpenCV_LIBS} 
    pylonutility 
    pylonbase 
    GenApi_gcc_v3_1_Basler_pylon
    GCBase_gcc_v3_1_Basler_pylon
    GCBase_gcc_v3_1_Basler_pylon
    zbar
)

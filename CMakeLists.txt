cmake_minimum_required (VERSION 2.6)
project (BarcodeLabel)
MESSAGE( STATUS "PROJECT_NAME: " ${PROJECT_NAME} )

# Check platforms
if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif(CMAKE_HOST_APPLE)
    set(MACOS 1)
elseif(CMAKE_HOST_UNIX)
    set(LINUX 1)
endif()

# Set RPATH
if(WINDOWS)
else()
    SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
    MESSAGE( STATUS "CMAKE_INSTALL_RPATH: " "${CMAKE_INSTALL_PREFIX}/lib" )
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()


# Add search path for include and lib files
if(WINDOWS)
    link_directories("${PROJECT_SOURCE_DIR}/platforms/win/lib/") 
elseif(LINUX)
    link_directories("${PROJECT_SOURCE_DIR}/platforms/linux/") 
elseif(MACOS)
    link_directories("${PROJECT_SOURCE_DIR}/platforms/macos/") 
endif()
include_directories("${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include/")

# Add the executable
find_package(OpenCV REQUIRED)
add_executable(BarcodeLabel BarcodeLabel.cpp)
if(WINDOWS)
    target_link_libraries (BarcodeLabel "DynamsoftLabelRecognitionx64" ${OpenCV_LIBS} "DBRx64")
else()
    target_link_libraries (BarcodeLabel "DynamsoftLabelRecognition" ${OpenCV_LIBS} "DynamsoftBarcodeReader" pthread)
endif()


if(WINDOWS)
    add_custom_command(TARGET BarcodeLabel POST_BUILD 
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/platforms/win/bin/"      
        $<TARGET_FILE_DIR:BarcodeLabel>)
endif()


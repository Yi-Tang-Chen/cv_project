# CMake 最上層的 CMake 專案檔
cmake_minimum_required(VERSION 3.8)
project(SampleCode)

set (USE_OPENCV 0)
#WIN 
find_library(WSOCK32_LIBRARY wsock32)
find_library(WS2_32_LIBRARY ws2_32)
add_compile_definitions(_WINSOCKAPI_)

# 設定 OpenCV 路徑和庫
if(USE_OPENCV)
    set(OPENCV_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv-4.10.0/)
    include_directories(${OPENCV_DIR}/include)
    link_directories(${OPENCV_DIR}/x64/vc17/lib)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(OPENCV_LIBRARIES opencv_world4100d)
    else()
        set(OPENCV_LIBRARIES opencv_world4100)
    endif()
endif()

# 設定 Qt
set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.14.2/5.14.2/msvc2017_64/")
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui Network)
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})

# 啟用 Qt 的自動生成
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 獲取所有源文件
file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.h)
file(GLOB QT_UI_FILES src/ui/*.ui)

# 包含 Qt UI 文件
qt5_wrap_ui(QT_FORMS_HEADERS ${QT_UI_FILES})

# 新增可執行檔
add_executable(${PROJECT_NAME} ${SRC_FILES} ${QT_FORMS_HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "/Zc:wchar_t")
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Network)
target_link_libraries(${PROJECT_NAME} ${OPENCV_LIBRARIES} ${SPINNAKER_LIBS} delayimp wsock32 ws2_32 )
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14) 
target_compile_definitions(${PROJECT_NAME} PUBLIC CMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/")
qt5_use_modules(${PROJECT_NAME} Widgets Core Gui) 


# 複製 DLL 到目標目錄
if (USE_OPENCV)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${OPENCV_DIR}/x64/vc17/bin/${OPENCV_LIBRARIES}.dll
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
endif()

# 顯示當前源目錄以便調試
message(STATUS "Current source directory: ${CMAKE_CURRENT_SOURCE_DIR}")

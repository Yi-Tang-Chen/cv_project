cmake_minimum_required(VERSION 3.8)
project(SampleCode CXX)

# 使用 C++14
set(CMAKE_CXX_STANDARD        14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 尋找系統上已安裝的 OpenCV
find_package(OpenCV REQUIRED)
message(STATUS "Found OpenCV ${OpenCV_VERSION}")

# 包含我們自己寫的 header 路徑
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${OpenCV_INCLUDE_DIRS}
)

# 將 src 底下所有 .cpp 檔案都納入編譯
file(GLOB SRC_FILES
  ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# 產生執行檔
add_executable(${PROJECT_NAME} ${SRC_FILES})

# 連結 OpenCV 函式庫
target_link_libraries(${PROJECT_NAME}
  ${OpenCV_LIBS}
)

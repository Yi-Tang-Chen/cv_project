// 檔案: src/opencv.cpp
#include "opencv.hpp"
#include <iostream>

// 建構函式：指定使用 GStreamer 後端
Camera::Camera(int deviceIndex) {
    cap_.open(deviceIndex, cv::CAP_GSTREAMER);
    if (!cap_.isOpened()) {
        std::cerr << "Error: 無法開啟相機 #" << deviceIndex << std::endl;
    } else {
        std::cout << "Camera #" << deviceIndex << " 已開啟" << std::endl;
    }
}

// 解構函式：釋放相機資源 (只有一個！)
Camera::~Camera() {
    if (cap_.isOpened()) {
        cap_.release();
        std::cout << "Camera 已釋放" << std::endl;
    }
}

// 檢查相機是否開啟
bool Camera::isOpened() const {
    return cap_.isOpened();
}

// 讀取一幀畫面
cv::Mat Camera::getFrame() {
    cv::Mat frame;
    if (cap_.isOpened()) {
        cap_.read(frame);
    }
    return frame;
}
#include "opencv.hpp"
#include <iostream>

Camera::Camera(int deviceIndex) {
    // 使用 cv::CAP_GSTREAMER 來匹配 cheese 的行為
    cap_.open(deviceIndex, cv::CAP_GSTREAMER);

    if (!cap_.isOpened()) {
        std::cerr << "Error: 無法開啟相機 #" << deviceIndex << std::endl;
    } else {
        std::cout << "Camera #" << deviceIndex << " 已開啟" << std::endl;
    }
}

Camera::~Camera() {
    if (cap_.isOpened()) {
        cap_.release();
        std::cout << "Camera 已釋放" << std::endl;
    }
}

bool Camera::isOpened() const {
    return cap_.isOpened();
}

cv::Mat Camera::getFrame() {
    cv::Mat frame;
    if (cap_.isOpened()) {
        cap_.read(frame); // 使用 .read()
    }
    // 不在這裡印警告，讓主程式去判斷
    return frame;
}

Camera::~Camera() {
    if (cap_.isOpened()) {
        cap_.release();
        std::cout << "Camera 已釋放" << std::endl;
    }
}
#include "opencv.hpp"
#include <iostream>

Camera::Camera(int deviceIndex) {
    cap_.open(deviceIndex);
    if (!cap_.isOpened()) {
        std::cerr << "Error" << deviceIndex << std::endl;
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
        cap_ >> frame;  // 用 >> 擷取最新影格
        if (frame.empty()) {
            std::cerr << "Warning: 擷取到空影格" << std::endl;
        }
    }
    return frame;
}

#include "opencv.hpp"
#include <iostream>

// 修正 2: 在建構函式中，強制使用 V4L2 後端
Camera::Camera(int deviceIndex) {
    // 在 Linux 上，明確指定 CAP_V4L2 通常比預設的 GStreamer 更穩定
    cap_.open(deviceIndex, cv::CAP_V4L2);
    
    if (!cap_.isOpened()) {
        // 美化錯誤訊息
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
        // .read() 比 >> 更能明確表示成功與否
        if (!cap_.read(frame) || frame.empty()) {
            std::cerr << "Warning: 擷取到空影格 (請確認相機權限或硬體是否正常)" << std::endl;
        }
    }
    return frame;
}
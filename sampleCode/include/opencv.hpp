#ifndef OPENCV_HPP
#define OPENCV_HPP

#include <opencv2/opencv.hpp>

/**
 * @brief Camera 類別：封裝 USB 相機開／關與擷取影格
 */
class Camera {
public:
    /**
     * @param deviceIndex : USB 相機編號 (通常是 0、1 ...)
     */
    explicit Camera(int deviceIndex);
    ~Camera();

    /**
     * @brief 檢查相機是否成功開啟
     */
    bool isOpened() const;

    /**
     * @brief 擷取一張影格
     * @return 成功回傳非空 cv::Mat；失敗（或相機沒開）回傳空 Mat
     */
    cv::Mat getFrame();

private:
    cv::VideoCapture cap_;
};

#endif // OPENCV_HPP

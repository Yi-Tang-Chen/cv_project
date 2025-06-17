#include "OpenCV.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>

int main() {
    Camera cam(0);
    if (!cam.isOpened()) {
        std::cerr << "Error: 無法開啟相機\n";
        return -1;
    }

    const std::string winName = "USB Camera";
    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);

    std::cout << "在視窗裡按任意鍵或點 × 可關閉程式\n";

    while (true) {
        cv::Mat frame = cam.getFrame();
        if (!frame.empty()) {
            cv::imshow(winName, frame);
        }
        // 等待 30ms，看是否有按鍵
        if (cv::waitKey(30) >= 0) {
            break;
        }
        // 如果你非要靠視窗關閉來結束，也可保留下面這行（選擇其一即可）
        if (cv::getWindowProperty(winName, cv::WND_PROP_VISIBLE) < 1) break;
    }

    cv::destroyAllWindows();
    return 0;
}

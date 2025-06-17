#include "opencv.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>

int main() {
    // 1. 開啟 USB 相機 0
    Camera cam(0);
    if (!cam.isOpened()) {
        std::cerr << "Error: 無法開啟相機\n";
        return -1;
    }

    const std::string winName = "USB Camera";
    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);

    std::cout << "按下視窗右上角 × 即可關閉並結束程式\n";

    // 2. 持續擷取並顯示，直到視窗被關閉
    while (true) {
        cv::Mat frame = cam.getFrame();
        if (!frame.empty()) {
            cv::imshow(winName, frame);
        }
        // 若視窗被關閉（不可見），就跳出
        if (cv::getWindowProperty(winName, cv::WND_PROP_VISIBLE) < 1) {
            break;
        }
        // 等 30ms，若你在這段時間按任意鍵（回傳值 ≥ 0）也結束
        if (cv::waitKey(30) >= 0) {
            break;
        }
    }

    // 3. 清理
    cv::destroyAllWindows();
    // Camera 物件在離開作用域時會自動呼叫釋放
    return 0;
}

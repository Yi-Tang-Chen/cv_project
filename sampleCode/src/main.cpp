#include "opencv.hpp"
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
    bool window_created = false; // 用一個旗標來判斷視窗是否已建立

    std::cout << "在視窗裡按任意鍵或點 × 可關閉程式\n";

    while (true) {
        cv::Mat frame = cam.getFrame();

        // 只要影格不是空的，就顯示畫面
        if (!frame.empty()) {
            cv::imshow(winName, frame);
            window_created = true; // 標記視窗已成功建立
        }

        // 等待 30ms，看是否有按鍵
        int key = cv::waitKey(30);
        if (key >= 0) { // 任何按鍵都會結束
            break;
        }
        
        // 只有在視窗成功建立後，才檢查它是否被關閉
        if (window_created && cv::getWindowProperty(winName, cv::WND_PROP_VISIBLE) < 1) {
            break;
        }
    }

    cv::destroyAllWindows();
    return 0;
}
// 檔案: src/main.cpp
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

    std::cout << "在視窗裡按任意鍵或點 × 可關閉程式\n";

    cv::Mat frame;
    bool window_created = false; // 用來追蹤視窗是否已被建立

    while (true) {
        frame = cam.getFrame();

        // 如果影格是空的，不要退出！
        // 而是跳過這次迴圈，繼續嘗試抓下一張。
        if (frame.empty()) {
            std::cout << "讀取到空影格，繼續嘗試..." << std::endl;
            // 即使是空影格，也要有 waitKey 來處理事件和提供退出的機會
            if (cv::waitKey(1) >= 0) break;
            continue; // 跳到下一次 while 迴圈
        }

        // 程式能執行到這裡，代表 frame 是有效的
        cv::imshow(winName, frame);
        window_created = true; // 標記視窗已成功建立

        // 等待 30ms
        int key = cv::waitKey(30);
        if (key >= 0) { // 任何按鍵都會結束
            break;
        }

        // 只有在視窗存在的情況下，才檢查它是否被手動關閉
        if (window_created && cv::getWindowProperty(winName, cv::WND_PROP_VISIBLE) < 1) {
            break;
        }
    }

    cv::destroyAllWindows();
    return 0;
}
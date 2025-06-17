#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0, cv::CAP_GSTREAMER);

    if (!cap.isOpened()) {
        std::cerr << "致命錯誤：相機無法開啟！" << std::endl;
        return -1;
    }

    // --- 效能優化：設定較低的解析度 ---
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    // ------------------------------------

    double width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    double height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::cout << "相機成功開啟，實際解析度: " << width << "x" << height << std::endl;
    std::cout << "進入主迴圈。按 'q' 鍵退出。" << std::endl;


    cv::Mat frame;
    while (true) {
        cap.read(frame);

        if (frame.empty()) {
            std::cerr << "偵測到空影格，正在重試..." << std::endl;
            if (cv::waitKey(10) >= 0) break;
            continue;
        }

        cv::imshow("優化後測試 (640x480)", frame);

        // 將 waitKey 的延遲增加到 10ms，稍微降低 CPU 負擔
        if (cv::waitKey(10) == 'q') {
            std::cout << "偵測到 'q' 鍵，正在退出。" << std::endl;
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    std::cout << "程式結束。" << std::endl;
    
    return 0;
}
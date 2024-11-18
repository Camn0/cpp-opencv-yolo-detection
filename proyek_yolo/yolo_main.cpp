#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace cv::dnn;
using namespace std;

int main() {
    string modelConfiguration = "/home/kinarast/proyek_yolo/yolov3.cfg"; 
    string modelWeights = "/home/kinarast/proyek_yolo/yolov3.weights";   
    ifstream classFile("/home/kinarast/proyek_yolo/coco.names");         

    // Check if class file exists
    if (!classFile) {
        cerr << "Could not open the class file." << endl;
        return -1;
    }

    vector<string> classNames;
    string className;
    while (getline(classFile, className)) {
        classNames.push_back(className);
    }

    // Load the network
    Net net = readNetFromDarknet(modelConfiguration, modelWeights);
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);

    VideoCapture cap(0); // Open webcam

    if (!cap.isOpened()) {
        cerr << "Error: Couldn't open video capture" << endl;
        return -1;
    }

    while (true) {
        Mat frame;
        cap >> frame;

        if (frame.empty()) {
            break;
        }

        Mat blob;
        blobFromImage(frame, blob, 1 / 255.0, Size(416, 416), Scalar(), true, false);
        net.setInput(blob);

        vector<Mat> outs;
        net.forward(outs, net.getUnconnectedOutLayersNames());

        // Process YOLO outputs
        for (size_t i = 0; i < outs.size(); i++) {
            float* data = (float*)outs[i].data;
            for (int j = 0; j < outs[i].rows; j++, data += outs[i].cols) {
                float confidence = data[4];
                if (confidence > 0.5) {
                    int classId = max_element(data + 5, data + outs[i].cols) - (data + 5);
                    if (classNames[classId] == "bowl") {
                        int centerX = (int)(data[0] * frame.cols);
                        int centerY = (int)(data[1] * frame.rows);
                        int width = (int)(data[2] * frame.cols);
                        int height = (int)(data[3] * frame.rows);
                        int left = centerX - width / 2;
                        int top = centerY - height / 2;

                        rectangle(frame, Point(left, top), Point(left + width, top + height), Scalar(0, 255, 0), 2);
                        putText(frame, "Bowl", Point(left, top - 10), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
                    }
                }
            }
        }

        imshow("YOLO Bowl Detection", frame);
        if (waitKey(30) == 'q') {
            break;
        }
    }

    cap.release();
    destroyAllWindows();

    return 0;
}

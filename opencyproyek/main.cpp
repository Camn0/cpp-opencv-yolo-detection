#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    VideoCapture cap("file:///opencyproyek/object_video.mp4");
    
    if (!cap.isOpened()) {
        cout << "Error opening video file." << endl;
        return -1;
    }

    // Get frame width, height, and frames per second from the video capture
    int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));
    int fps = static_cast<int>(cap.get(CAP_PROP_FPS));

    // Define the codec and create VideoWriter object
    VideoWriter writer("output_video.avi", VideoWriter::fourcc('M','J','P','G'), fps, Size(frame_width, frame_height));

    while (true) {
        Mat frame;
        cap >> frame;

        if (frame.empty()) {
            cout << "No more frames available." << endl;
            break;
        }

        Mat hsv_frame;
        cvtColor(frame, hsv_frame, COLOR_BGR2HSV);
        
        // Define HSV range (adjust these values as needed)
        Scalar lower_bound(30, 100, 100); // Example for green
        Scalar upper_bound(90, 255, 255);
        
        Mat mask;
        inRange(hsv_frame, lower_bound, upper_bound, mask);

        vector<vector<Point>> contours;
        findContours(mask, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
        
        cout << "Number of contours found: " << contours.size() << endl; // Debugging

        for (size_t i = 0; i < contours.size(); i++) {
            double area = contourArea(contours[i]);
            if (area > 200) {  // Adjust this threshold
                Rect bounding_rect = boundingRect(contours[i]);
                rectangle(frame, bounding_rect, Scalar(0, 255, 0), 2); // Draw bounding box
            }
        }

        // Write the modified frame to the video
        writer.write(frame);

        imshow("Detected Objects", frame);

        if (waitKey(30) == 'q') {
            break;
        }
    }

    // Release resources
    cap.release();
    writer.release();
    destroyAllWindows();

    return 0;
}

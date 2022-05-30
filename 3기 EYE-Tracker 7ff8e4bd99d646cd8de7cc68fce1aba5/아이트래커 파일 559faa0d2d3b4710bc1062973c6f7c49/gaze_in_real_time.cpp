#include "stdafx.h"
#include<opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <iostream>
#include <string>
#include <WinSock2.h>

using namespace cv;
using namespace std;

#pragma comment(lib,"ws2_32")

#define PORT1 1
#define PORT2 2
#define PORT3 9
#define PACKET_SIZE 1024
#define SERVER_IP "210.123.37.182"



Point2d get_gpData(string* gp_data) {
    index1 = gp_data.find("[");
    index2 = gp_data.find("]");
    gp_data = gp_data[index1 + 1:index2];
    index_temp = gp_data.find(",");

    gPoint_x = gp_data.substr(0, index_temp);
    gPoint_y = gp_data.substr(index_temp + 1);
    Point2d gPoint(gPoint_x, gPoint_y);


    gp_data = gp_data.replace(",", "");
    gp_data = gp_data.replace("\n", "");
    f.write(gp_data)
        f.write("\n")
        return gPoint;
}


int main() {

    WSADATA wsaData :
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET gp_x;
    SOCKET gp_y;
    SOCKET gm;
    gp_x = socket(PF_INET, SOCK_STREAM, IPPORT0_TCP);
    gp_y = socket(PF_INET, SOCK_STREAM, IPPORT0_TCP);
    gm = socket(PF_INET, SOCK_STREAM, IPPORT0_TCP);

    SOCKADDR_IN gaze_x = {};
    gaze_x.sin_faily = AF_INET;
    gaze_x.sin_port = htons(PORT1);
    gaze_x.sin_addr.s_addr = inet_addr(SERVER_IP);

    SOCKADDR_IN gaze_y = {};
    gaze_y.sin_faily = AF_INET;
    gaze_y.sin_port = htons(PORT2);
    gaze_y.sin_addr.s_addr = inet_addr(SERVER_IP);

    SOCKADDR_IN gMonitor = {};
    gMonitor.sin_faily = AF_INET;
    gMonitor.sin_port = htons(PORT3);
    gMonitor.sin_addr.s_addr = inet_addr(SERVER_IP);

    connect(gp_x, (SOCKADDR*)&gaze_x, sizeof(gaze_x));
    connect(gp_y, (SOCKADDR*)&gaze_y, sizeof(gaze_y));
    connect(gm, (SOCKADDR*)&gMonitor, sizeof(gMonitor));

    f = open("C:\Users\LG\Desktop\gaze_point.txt", "w");
    const std::string videoStreamAddress = "rtsp://192.168.71.50:8554/live/eyes";
    cv::VideoCapture capture(videoStreamAddress);
    if (!capture.open(videoStreamAddress)) {
        //Error
    }
    cv::namedWindow("eyes", CV_WINDOW_AUTOSIZE);


    Point2d gPoint(0.0, 0.0);
    Mat frame;
    vector<int> ids;
    vector<std::vector<cv::Point2f> > corners;
    Ptr<aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(aruco::DICT_6X6_250);

    while (true) {
        if (!capture.read(frame)) {
            //Error
        }
        else {
            gp_data = str(tobiiglasses.get_data()["gp"]);
            if (a.find("-1")) pass;
            else {
                aruco::detectMarkers(frame, dictionary, corners, ids);
                gPoint = get_gpData(gp_data);

                int monitor[3] = { 0, };
                Point2d top_left[3], top_right[3], bot_left[3], bot_right[3];
                int left_mirror, right_mirror = 0;
                for (int i = 0; i < ids.size(); i++) {
                    if (ids[i] == 19) { cv::Point2d temp(corners[i][0].x, corners[i][0].y); top_left[0] = temp; monitor[0]++; left_mirror++; }
                    else if (ids[i] == 20) { cv::Point2d temp(corners[i][1].x, corners[i][1].y); top_right[0] = temp; monitor[0] ++; left_mirror++; }
                    else if (ids[i] == 21) { cv::Point2d temp(corners[i][3].x, corners[i][3].y); bot_left[0] = temp; monitor[0] ++; left_mirror++; }
                    else if (ids[i] == 22) { cv::Point2d temp(corners[i][2].x, corners[i][2].y); bot_right[0] = temp; monitor[0] ++; left_mirror++; }

                    else if (ids[i] == 23) { cv::Point2d temp(corners[i][2].x, corners[i][2].y); top_left[1] = temp; monitor[1]++; }
                    else if (ids[i] == 24) { cv::Point2d temp(corners[i][1].x, corners[i][1].y); top_right[1] = temp; monitor[1]++; }
                    else if (ids[i] == 25) { cv::Point2d temp(corners[i][3].x, corners[i][3].y); bot_left[1] = temp; monitor[1]++; }
                    else if (ids[i] == 26) { cv::Point2d temp(corners[i][2].x, corners[i][2].y); bot_right[1] = temp; monitor[1]++; }

                    else if (ids[i] == 27) { cv::Point2d temp(corners[i][0].x, corners[i][0].y); top_left[2] = temp; monitor[2]++;; right_mirror++; }
                    else if (ids[i] == 28) { cv::Point2d temp(corners[i][1].x, corners[i][1].y); top_right[2] = temp; monitor[2]++;; right_mirror++; }
                    else if (ids[i] == 29) { cv::Point2d temp(corners[i][2].x, corners[i][2].y); bot_left[2] = temp; monitor[2]++; ; right_mirror++; }
                    else if (ids[i] == 30) { cv::Point2d temp(corners[i][2].x, corners[i][2].y); bot_right[2] = temp; monitor[2]++; right_mirror++; }
                }

                int gMonitor = -1;
                for (int j = 0; j < 3; j++) { if (monitor[j] == 4) gMonitor = j; }
                if (gMonitor == -1) { std::cout << "(Can't find a Monitor) : " << "monitor1(" << monitor[0] << ") monitor2(" << monitor[1] << ") monitor3(" << monitor[2] << ")" << endl; }
                else { std::cout << endl << "Monitor_Number(" << gMonitor << ") / Points : " << top_left[gMonitor] << top_right[gMonitor] << bot_right[gMonitor] << bot_left[gMonitor] << endl; }


                if (gMonitor != -1) {
                    cv::line(*show_img, Point(int(top_left[gMonitor].x), int(top_left[gMonitor].y)), Point(int(top_right[gMonitor].x), int(top_right[gMonitor].y)), Scalar(100, 200, 200), 5);
                    cv::line(*show_img, Point(int(top_right[gMonitor].x), int(top_right[gMonitor].y)), Point(int(bot_right[gMonitor].x), int(bot_right[gMonitor].y)), Scalar(100, 200, 200), 5);
                    cv::line(*show_img, Point(int(bot_right[gMonitor].x), int(bot_right[gMonitor].y)), Point(int(bot_left[gMonitor].x), int(bot_left[gMonitor].y)), Scalar(100, 200, 200), 5);
                    cv::line(*show_img, Point(int(top_left[gMonitor].x), int(top_left[gMonitor].y)), Point(int(bot_left[gMonitor].x), int(bot_left[gMonitor].y)), Scalar(100, 200, 200), 5);
                }

                //circle(*show_img, Point2d(myint1, myint2), circle_radius, Scalar(0, 0, 255), 5);

                // perspective transform
                Point2f inputQuad[4];
                Point2f outputQuad[4];
                Mat input, output;
                input = *show_img;
                Mat lambda = Mat::zeros(input.rows, input.cols, input.type());

                inputQuad[0] = top_left[gMonitor];
                inputQuad[1] = top_right[gMonitor];
                inputQuad[2] = bot_right[gMonitor];
                inputQuad[3] = bot_left[gMonitor];
                outputQuad[0] = Point2f(0, 0);
                outputQuad[1] = Point2f(input.cols - 1, 0);
                outputQuad[2] = Point2f(input.cols - 1, input.rows - 1);
                outputQuad[3] = Point2f(0, input.rows - 1);

                lambda = getPerspectiveTransform(inputQuad, outputQuad);
                Point2d tf_gaze;
                tf_gaze.x = lambda.at<double>(0, 0) * gPoint.x + lambda.at<double>(0, 1) * gPoint.y + lambda.at<double>(0, 2);
                tf_gaze.y = lambda.at<double>(1, 0) * gPoint.x + lambda.at<double>(1, 1) * gPoint.y + lambda.at<double>(1, 2);

                // correcting gazePoint
                if (gMonitor == 2) tf_gaze.y = tf_gaze.y * 695 / 1080 + 385;
                else if (gMonitor == 0) tf_gaze.y = tf_gaze.y * 282 / 1080 + 357;

                if (tf_gaze.x < 0 && (gMonitor == 1 || gMonitor == 2)) {
                    gMonitor -= 1;
                    tf_gaze.x = 1920 + tf_gaze.x;
                }
                if (tf_gaze.x > 1920 && (gMonitor == 0 || gMonitor == 1)) {
                    gMonitor += 1;
                    tf_gaze.x = tf_gaze.x - 1920;
                }
            }
            cv::waitKey(30);
        }
        //send tf_gaze.x  (port 1)
        char c_gaze_x[] = tf_gaze.x;
        send(gp_x, c_gaze_x, strlen(c_gaze_x), 0);


        //send tf_gaze.y  (port 2)
        char[] = tf_gaze.y;
        send(gp_y, c_gaze_y, strlen(c_gaze_y), 0);


        //send gMonitor  (port 3)
        char c_gm[] = gMonitor;
        send(gm, c_gm, strlen(c_gm), 0);



    }

    closesocket(hSocket);
    WSACleanup();

}
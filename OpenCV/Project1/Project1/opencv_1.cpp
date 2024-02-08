#define  _CRT_SECURE_NO_WARNINGS
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
	//Mat src = imread("D:/EdgeDownload/figure/zeeker_001.jpg");//彩色图像
	Mat src = imread("D:/EdgeDownload/figure/zeeker_001.jpg",IMREAD_GRAYSCALE);//灰度图像
	namedWindow("输入窗口", WINDOW_AUTOSIZE);

	imshow("输入窗口", src);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
#define  _CRT_SECURE_NO_WARNINGS
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
	//Mat src = imread("D:/EdgeDownload/figure/zeeker_001.jpg");//��ɫͼ��
	Mat src = imread("D:/EdgeDownload/figure/zeeker_001.jpg",IMREAD_GRAYSCALE);//�Ҷ�ͼ��
	namedWindow("���봰��", WINDOW_AUTOSIZE);

	imshow("���봰��", src);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
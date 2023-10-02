#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("lena.png", 0);	// 원본 이미지파일 흑백으로 열기
	Mat img_trans = image.clone();		// deep copy
	Mat result_img = img_trans.clone(); // deep copy

	for (int j = 0; j < image.rows; j++)
		for (int i = 0; i < image.cols; i++)
		{
			uchar pixel_value = image.at<uchar>(j, i); // 픽셀값 계산
			if (pixel_value < 127)
			{
				img_trans.at<uchar>(j, i) = 255 - pixel_value; // negative transformation
			}
			else
			{
				img_trans.at<uchar>(j, i) = pow((float)(pixel_value / 255.0), 10) * 255; // gamma transformation (gamma = 10)
			}
		}

	// make rotated image
	for (int j = 0; j < img_trans.rows; j++)
		for (int i = 0; i < img_trans.cols; i++)
			result_img.at<uchar>(i, img_trans.rows - 1 - j) = img_trans.at<uchar>(j, i);

	imshow("gray image", image);
	// imshow("negative_img", negative_img);
	imshow("result", result_img);
	waitKey(0);
	return 0;
}
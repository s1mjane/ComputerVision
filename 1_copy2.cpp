#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat image = imread("lena.png", 0);

	Mat mask = Mat::zeros(image.size(), image.type());
	Mat copied;

	// Rect rect = Rect(10, 10, 100, 100);
	// rectangle(mask, rect, Scalar(255, 0, 0), -1, 8, 0); // 부분 카피
	rectangle(mask, Rect(10, 10, 100, 100), Scalar(255, 0, 0), -1, 8, 0); // 부분 카피

	image.copyTo(copied, mask); // copyTo 함수

	imshow("original", image);
	imshow("copied", copied);
	waitKey();
	return 0;
}
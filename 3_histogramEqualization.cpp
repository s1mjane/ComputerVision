#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image;
	Mat hist_equalized_image;

	image = imread("lena.png", 0); // OpenCV의 equalizeHist 함수는 그레이스케일 이미지에 대해서만 동작하므로, 입력 이미지를 그레이스케일로
	if (!image.data)
		exit(1);

	equalizeHist(image, hist_equalized_image);

	imshow("Input image", image);
	imshow("Hist Equalized Image", hist_equalized_image);

	waitKey(0);
	return 0;
}
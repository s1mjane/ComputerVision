#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// ------ Sobel edge detector
// int main()
// {
// 	Mat image, blur, grad_x, grad_y, abs_grad_x, abs_grad_y, result;
// 	image = imread("lena.png", 0);
// 	GaussianBlur(image, blur, Size(5, 5), 5, 5, BORDER_DEFAULT);

// 	Sobel(blur, grad_x, CV_16S, 1, 0, 3);
// 	convertScaleAbs(grad_x, abs_grad_x);

// 	Sobel(blur, grad_y, CV_16S, 0, 1, 3);
// 	convertScaleAbs(grad_y, abs_grad_y);

// 	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, result);

// 	imshow("input", image);
// 	imshow("gaussian blur", blur);
// 	imshow("X", abs_grad_x);
// 	imshow("Y", abs_grad_y);
// 	imshow("sobel edge detector", result);

// 	waitKey(0);
// }

// Canny edge operartor
int main()
{
	Mat image, canny;
	image = imread("lena.png", 0);

	Canny(image, canny, 190, 200, 5);

	imshow("input", image);
	imshow("canny", canny);

	waitKey(0);
}
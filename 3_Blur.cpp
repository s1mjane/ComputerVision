#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// ------ Averaging filter
// int main()
// {
// 	Mat image, AvgImg, GaussianImg;
// 	image = imread("lena.png");

// 	blur(image, AvgImg, Size(5, 5));

// 	GaussianBlur(image, GaussianImg, Size(5, 5), 1.5);

// 	imshow("input", image);
// 	imshow("average image", AvgImg);
// 	imshow("gaussian blur", GaussianImg);

// 	waitKey(0);
// 	return 0;
// }

// ------- Sharpening using econd derivative
// int main()
// {
// 	Mat image, laplacian, abs_laplacian, sharpening;
// 	image = imread("Moon.png", 0);

// 	GaussianBlur(image, image, Size(3, 3), 0, 0, BORDER_DEFAULT);

// 	Laplacian(image, laplacian, CV_16S, 1, 1, 0);

// 	convertScaleAbs(laplacian, abs_laplacian);

// 	sharpening = abs_laplacian + image;

// 	imshow("input", image);
// 	imshow("laplacian", laplacian);
// 	imshow("abs_laplacian", abs_laplacian);
// 	imshow("sharpening", sharpening);

// 	waitKey(0);
// }

// ------ median filter
int main()
{
	Mat image = imread("saltnpepper.png", 0);
	imshow("input", image);
	Mat mf1, mf2;

	medianBlur(image, mf1, 3);
	imshow("median1", mf1);

	medianBlur(image, mf2, 9);
	imshow("median2", mf2);

	waitKey(0);
	return 0;
}
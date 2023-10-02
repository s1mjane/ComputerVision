#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// Negative transformation
// int main()
// {
// 	Mat image = imread("lena.png", 0);
// 	Mat negative_img = image.clone();

// 	for (int j = 0; j < image.rows; j++)
// 		for (int i = 0; i < image.cols; i++)
// 			negative_img.at<uchar>(j, i) = 255 - image.at<uchar>(j, i);

// 	imshow("input image", image);
// 	imshow("negative image", negative_img);

// 	waitKey(0);
// }

// Log transformation
// int main()
// {
// 	Mat image = imread("lena.png", 0);
// 	Mat f_img, log_img;
// 	double c = 1.5f; // scale constant
// 	image.convertTo(f_img, CV_32F);
// 	f_img = abs(f_img) + 1;
// 	log(f_img, f_img);
// 	normalize(f_img, f_img, 0, 255, NORM_MINMAX);
// 	convertScaleAbs(f_img, log_img, c);
// 	imshow("input", image);
// 	imshow("log transformation", log_img);
// 	waitKey(0);
// }

// Gamma transformation
int main()
{
	Mat image = imread("lena.png", 0);
	Mat gamma_img;
	MatIterator_<uchar> it, end;
	float gamma = 0.5;
	unsigned char pix[256];

	for (int i = 0; i < 256; i++)
	{
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
	}
	gamma_img = image.clone();

	for (int j = 0; j < image.rows; j++)
		for (int i = 0; i < image.cols; i++)
			gamma_img.at<uchar>(j, i) = pix[gamma_img.at<uchar>(j, i)];

	imshow("Input image", image);
	imshow("Gamma transformation", gamma_img);
	waitKey(0);
}
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// --------- using 'at' operator
// int main()
// {
// 	Mat image;
// 	Mat image_gray;

// 	int value, value_B, value_R, value_G, channels;

// 	image = imread("lena.png");
// 	image_gray = imread("lena.png", 0);

// 	value = image_gray.at<uchar>(50, 100);
// 	cout << value << endl;

// 	value_B = image.at<Vec3b>(50, 100)[0];
// 	value_G = image.at<Vec3b>(50, 100)[1];
// 	value_R = image.at<Vec3b>(50, 100)[2];
// 	cout << "value at (100, 50): " << value_B << " " << value_G << " " << value_R << endl;

// 	waitKey(0);
// }

// --------- using pointer
// ---------------- faster than at operator
// int main()
// {
// 	Mat image = imread("lena.png");
// 	int value, value_B, value_G, value_R, channels;
// 	channels = image.channels();

// 	// pointer
// 	uchar *p;
// 	p = image.ptr<uchar>(50);
// 	value_B = p[100 * channels + 0];
// 	value_G = p[100 * channels + 1];
// 	value_R = p[100 * channels + 2];

// 	cout << "value at (100, 50): " << value_B << " " << value_G << " " << value_R << endl;

// 	waitKey(0);
// }

// --------- using data member function
// ---------------- fast
int main()
{
	Mat image;
	int value, value_B, value_G, value_R, channels;

	image = imread("lena.png");
	channels = image.channels();

	// data member function
	uchar *data = (uchar *)image.data;
	value_B = data[(50 * image.cols + 100) * channels + 0];
	value_G = data[(50 * image.cols + 100) * channels + 1];
	value_R = data[(50 * image.cols + 100) * channels + 2];
	cout << "value at (100, 50): " << value_B << " " << value_G << " " << value_R << endl;

	waitKey(0);
}
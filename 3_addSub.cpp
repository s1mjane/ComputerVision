#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat img1 = imread("lena.png");
	Mat img2 = imread("lena.png");
	Mat dst;
	add(img1, img2, dst);
	imshow("dst", dst);
	waitKey(0);
}
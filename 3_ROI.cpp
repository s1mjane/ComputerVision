#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("lena.png");
	Rect rect(100, 30, 250, 300);
	Mat rect_roi = image(rect);
	imshow("rectROI", rect_roi);
	waitKey(0);
}
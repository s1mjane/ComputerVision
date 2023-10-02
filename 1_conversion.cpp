#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("lena.png");
	Mat after_convertTo, after_convertScaleAbs;

	imshow("original", image);

	image.convertTo(after_convertTo, CV_16SC1);
	imshow("convertTo", after_convertTo);

	convertScaleAbs(image, after_convertScaleAbs, 2, 3);
	imshow("convertScaleAbs", after_convertScaleAbs);

	image.setTo(Scalar(255));
	imshow("after setTo", image);

	waitKey();
}
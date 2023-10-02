#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat saltnpepper = imread("saltnpepper.png", 0);

	Mat left_half = saltnpepper(Rect(0, 0, saltnpepper.cols / 2, saltnpepper.rows));
	Mat left_half_filtered;
	medianBlur(left_half, left_half_filtered, 9);

	Mat saltnpepper_filtered = saltnpepper.clone(); // deep copy
	left_half_filtered.copyTo(saltnpepper_filtered(Rect(0, 0, saltnpepper.cols / 2, saltnpepper.rows)));

	imshow("saltnpepper", saltnpepper);
	imshow("saltnpepper_filtered", saltnpepper_filtered);

	Mat moon = imread("Moon.png", 0);

	Mat left_half = moon(Rect(0, 0, moon.cols / 2, moon.rows));
	Mat right_half = moon(Rect(moon.cols / 2, 0, moon.cols / 2, moon.rows));

	Mat blurred_right_half, sharp_right_half;
	GaussianBlur(right_half, blurred_right_half, Size(0, 0), 3);
	sharp_right_half = right_half + 2 * (right_half - blurred_right_half);

	Mat final_image = moon.clone();
	sharp_right_half.copyTo(final_image(Rect(moon.cols / 2, 0, moon.cols / 2, moon.rows)));

	imshow("moon", moon);
	imshow("moon_filtered", final_image);

	waitKey(0);
	return 0;
}

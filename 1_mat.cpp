#include <opencv2/opencv.hpp>

// using namespace cv;
using namespace std;

int main()
{
	int w = 250;
	int h = 500;
	cv::Mat image(h, w, CV_8UC3, cv::Scalar(255, 0, 255));
	cout << "Size: " << image.size().height << ", " << image.size().width << endl;
	imshow("image", image);

	cv::waitKey();
	return 0;
}
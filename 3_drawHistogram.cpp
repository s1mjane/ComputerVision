#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat drawHistogram(Mat src)
{
	Mat hist;
	Mat histImage;
	int i, hist_w, hist_h, bin_w, histSize;
	float range[] = {0, 256};
	const float *histRange = {range};

	hist_w = 512;
	hist_h = 400;
	histSize = 256;
	bin_w = cvRound((double)hist_w / histSize);

	histImage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);

	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (int i = 0; i < histSize; i++)
	{
		rectangle(histImage, Point(bin_w * i, hist_h), Point(bin_w * i + hist_w / histSize, hist_h - cvRound(hist.at<float>(i))), Scalar(0, 0, 0), -1);
	}
	return histImage;
}

int main()
{
	Mat image;
	Mat hist_equalized_image;
	Mat hist_graph;
	Mat hist_equalized_graph;

	image = imread("lena.png", 0);
	if (!image.data)
		exit(1);

	equalizeHist(image, hist_equalized_image);

	hist_graph = drawHistogram(image);
	hist_equalized_graph = drawHistogram(hist_equalized_image);

	imshow("input", image);
	imshow("hist equalized image", hist_equalized_image);
	imshow("hist graph", hist_graph);
	imshow("hist equalized graph", hist_equalized_graph);

	waitKey(0);
	return 0;
}
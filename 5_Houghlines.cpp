#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// --- HoughLines
// int main()
// {
// 	Mat image, edge, result;
// 	float rho, theta, a, b, x0, y0;
// 	Point p1, p2;
// 	vector<Vec2f> lines;
// 	image = imread("chess_pattern.png");
// 	result = image.clone();

// 	cvtColor(image, image, CV_BGR2GRAY);
// 	Canny(image, edge, 50, 200, 3);

// 	HoughLines(edge, lines, 1, CV_PI / 180, 150, 0, CV_PI);

// 	for (int i = 0; i < lines.size(); i++)
// 	{
// 		rho = lines[i][0];
// 		theta = lines[i][1];
// 		a = cos(theta);
// 		b = sin(theta);

// 		x0 = a * rho;
// 		y0 = b * rho;

// 		p1 = Point(cvRound(x0 + 1000 * (-b)), cvRound(y0 + 1000 * a));
// 		p2 = Point(cvRound(x0 - 1000 * (-b)), cvRound(y0 - 1000 * a));

// 		line(result, p1, p2, Scalar(0, 0, 255), 3, 8);
// 	}
// 	imshow("input", image);
// 	imshow("edge", edge);
// 	imshow("hough", result);

// 	waitKey(0);
// }

// --- HoughLinesP
int main()
{
	Mat image, edge, result;
	vector<Vec4i> lines;
	image = imread("chess_pattern.png");
	result = image.clone();
	cvtColor(image, image, CV_BGR2GRAY);
	Canny(image, edge, 50, 200, 3);

	HoughLinesP(edge, lines, 1, CV_PI / 180, 50, 10, 300);

	for (int i = 0; i < lines.size(); i++)
	{
		Vec4i I = lines[i];
		line(result, Point(I[0], I[1]), Point(I[2], I[3]), Scalar(0, 0, 255), 3, 8);
	}

	imshow("input", image);
	imshow("edge", edge);
	imshow("hough", result);

	waitKey(0);
}
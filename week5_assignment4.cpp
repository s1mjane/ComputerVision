#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap("road.mp4");
	Mat frame;

	Rect Left_roi(200, 400, 400, 200);
	Rect Right_roi(600, 400, 400, 200);

	namedWindow("Left canny");
	namedWindow("Right canny");
	moveWindow("Left canny", 200, 0);
	moveWindow("Right canny", 600, 0);
	namedWindow("Frame");

	// int fps = cap.get(CAP_PROP_FPS);
	// int delay = 1000 / fps;
	// int totalFrames = cap.get(CAP_PROP_FRAME_COUNT);
	// int frameNumber = 0;

	auto start_time = chrono::steady_clock::now();

	while (true)
	{
		cap >> frame;

		Mat Left_frame = frame(Left_roi);
		Mat Right_frame = frame(Right_roi);

		// Convert frames to grayscale (use cvtColor to make a gray-scale image)
		Mat Left_gray, Right_gray;
		cvtColor(Left_frame, Left_gray, COLOR_BGR2GRAY);
		cvtColor(Right_frame, Right_gray, COLOR_BGR2GRAY);

		// Apply Gaussian blur for removing noise (blur function with mask size as 5X5)
		GaussianBlur(Left_gray, Left_gray, Size(5, 5), 0);
		GaussianBlur(Right_gray, Right_gray, Size(5, 5), 0);

		// Apply Canny edge detection (use 10 and 60)
		Mat Left_canny, Right_canny;
		Canny(Left_gray, Left_canny, 10, 60);
		Canny(Right_gray, Right_canny, 10, 60);

		// Display canny edges
		imshow("Left canny", Left_canny);
		imshow("Right canny", Right_canny);

		// Extract lines using Hough Line Transform
		vector<Vec2f> Left_lines, Right_lines;
		HoughLines(Left_canny, Left_lines, 1, CV_PI / 180, 85, 30, 60);
		HoughLines(Right_canny, Right_lines, 1, CV_PI / 180, 30, 120, 150);

		// Filter and merge lines
		float Left_rho = 0, Left_theta = 0, Right_rho = 0, Right_theta = 0;
		int Left_count = 0, Right_count = 0;

		for (const auto &line : Left_lines)
		{
			float rho = line[0];
			float theta = line[1];
			float angle_deg = theta * 180 / CV_PI;

			if (angle_deg >= 30 && angle_deg <= 60)
			{
				Left_rho += rho;
				Left_theta += theta;
				Left_count++;
			}
		}

		for (const auto &line : Right_lines)
		{
			float rho = line[0];
			float theta = line[1];
			float angle_deg = theta * 180 / CV_PI;

			if (angle_deg >= 120 && angle_deg <= 150)
			{
				Right_rho += rho;
				Right_theta += theta;
				Right_count++;
			}
		}

		// Average the filtered lines
		if (Left_count > 0)
		{
			Left_rho /= Left_count;
			Left_theta /= Left_count;
		}

		if (Right_count > 0)
		{
			Right_rho /= Right_count;
			Right_theta /= Right_count;
		}

		// Calculate line endpoints
		Point Left_pt1, Left_pt2, Right_pt1, Right_pt2;

		double a = cos(Left_theta);
		double b = sin(Left_theta);
		double x0 = a * Left_rho;
		double y0 = b * Left_rho;
		Left_pt1.x = cvRound(x0 + 1000 * (-b));
		Left_pt1.y = cvRound(y0 + 1000 * (a));
		Left_pt2.x = cvRound(x0 - 1000 * (-b));
		Left_pt2.y = cvRound(y0 - 1000 * (a));

		a = cos(Right_theta);
		b = sin(Right_theta);
		x0 = a * Right_rho;
		y0 = b * Right_rho;
		Right_pt1.x = cvRound(x0 + 1000 * (-b));
		Right_pt1.y = cvRound(y0 + 1000 * (a));
		Right_pt2.x = cvRound(x0 - 1000 * (-b));
		Right_pt2.y = cvRound(y0 - 1000 * (a));

		if (Left_count > 0 && Left_theta >= CV_PI * 30 / 180 && Left_theta <= CV_PI * 60 / 180)
		{
			line(frame, Left_pt1 + Left_roi.tl(), Left_pt2 + Left_roi.tl(), Scalar(0, 0, 255), 2);
		}

		if (Right_count > 0 && Right_theta >= CV_PI * 120 / 180 && Right_theta <= CV_PI * 150 / 180)
		{
			line(frame, Right_pt1 + Right_roi.tl(), Right_pt2 + Right_roi.tl(), Scalar(0, 0, 255), 2);
		}

		imshow("Frame", frame);

		auto end_time = chrono::steady_clock::now();
		auto elapsed_time = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

		if (elapsed_time >= 20)
			break;

		if (waitKey(25) == 'q')
			break;

		// if (frameNumber >= fps * 20)
		// 	break;

		// waitKey(delay);
		// frameNumber++;
	}

	cap.release();
	destroyAllWindows();

	return 0;
}

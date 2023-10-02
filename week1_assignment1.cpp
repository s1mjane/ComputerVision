#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat frame;
	int fps;
	int delay;
	VideoCapture cap("background.mp4");

	if (!cap.isOpened())
	{
		cout << "no such file!" << endl;
		waitKey(0);
	}

	fps = cap.get(CAP_PROP_FPS);
	delay = 1000 / fps;

	int totalFrames = cap.get(CAP_PROP_FRAME_COUNT); // 영상의 전체 프레임 수
	int frameNumber = 0;
	while (1)
	{
		cap >> frame;

		if (frame.empty()) // 프레임 없는 경우
		{
			cout << "no frame (end of video)" << endl;
			break;
		}

		if (frameNumber >= fps * 3)
			break; // 3초가 되면 break

		imshow("background", frame);										   // background라는 이름으로 창 열기
		waitKey(delay);														   // 프레임 딜레이 걸어서 보여줌
		cout << "frames: " << frameNumber + 1 << " / " << totalFrames << endl; // 프레임 수 출력
		frameNumber++;														   // frame number +1
	}

	waitKey(1000);		 // 끝나기 전 1초 대기
	cap.release();		 // 연결 끊기
	destroyAllWindows(); // 창 닫기

	return 0;
}
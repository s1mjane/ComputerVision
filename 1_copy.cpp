#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int main()
{
	Mat m1 = (Mat_<double>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);

	Mat m_shollow = m1;
	Mat m_deep = m1.clone();

	cout << "m1 =\n"
		 << m1 << endl;
	cout << "m_shollow =\n"
		 << m_shollow << endl;
	cout << "m_deep =\n"
		 << m_deep << endl;

	m1.at<double>(0, 0) = 100;
	cout << "m1 =\n"
		 << m1 << endl;
	cout << "m_shollw =\n"
		 << m_shollow << endl;
	cout << "m_deep =\n"
		 << m_deep << endl;

	waitKey();
}
#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat resim = imread("dikdortgen.jpg", IMREAD_GRAYSCALE);
	Canny(resim, resim, 190, 250);
	vector<Vec4i> tespit;
	HoughLinesP(resim, tespit, 1, CV_PI / 180, 100, 100, 10);
	cvtColor(resim, resim, COLOR_GRAY2BGR);
	
	for (int i = 0; i < tespit.size(); i++)
	{
		line(resim, Point(tespit[i][0], tespit[i][1]), Point(tespit[i][2], tespit[i][3]), Scalar(200, 100, 20), 1);
		cout << "cizgi bulundu" << endl;
		waitKey(1000);
		imshow("bulundu", resim);
		waitKey(2000);
		destroyWindow("bulundu");

	}
	imshow("dikdortgen", resim);
	waitKey(0);

	
}
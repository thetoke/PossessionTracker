/*
	By Vlada Kucera on March 11 ,2016 from www.funvision.blogspot.nl
	Modified by Matt Moynihan, 2017
*/

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include<stdexcept>
#include<iostream>
#include<string>

using namespace std;
using namespace cv; 

int main(int argc, const char** argv)
{
	// Name of the downloaded my cascades..  
	string cascadeName = "cascade.xml";

	// Load the cascade 
	CascadeClassifier detectorBody;

	bool loaded1 = detectorBody.load(cascadeName);

	Mat img;
	Mat original;

	img = imread(argv[1]);
	img.copyTo(original);

	// Prepare vector for results 
	vector<Rect> human;

	// Prepare gray image 
	cvtColor(img, img, CV_BGR2GRAY);

	// equalize Histogram   
	equalizeHist(img, img);

	// detect body in the img  
	// Set the proper min and max size for typical frame 
	detectorBody.detectMultiScale(img, human, 1.04, 4, 0 | 1, Size(40, 200), Size(110, 350));

	if (human.size() > 0)
	{
		for (int gg = 0; gg < human.size(); gg++)
		{
			rectangle(original, human[gg].tl(), human[gg].br(), Scalar(0, 0, 255), 2, 8, 0);
		}
	}

	cv::imshow("Detector Results",original);
	waitKey(10);

	return 0;
}
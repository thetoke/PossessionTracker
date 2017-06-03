
#include<opencv2/opencv.hpp>
#include<windows.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace cv; 


int main(int argc, char* argv[])
{
	
	VideoCapture cap(argv[1]);
	int fps = cap.get(CV_CAP_PROP_FPS);



	if (!cap.isOpened())

	{
		std::cout << "!!! Failed to open file: " << argv[1] << std::endl;
		return -1;
	}

	Mat frame;

	int frameNumber = 1;

	for (;;) 
	{

		clock_t begin = clock();

		
		if (!cap.read(frame))
			break;

		cap >> frame;
		if (!frame.data)
			continue;

		Point textOrg(30,30);
		int fontFace = FONT_HERSHEY_COMPLEX_SMALL;
		double fontScale = 1.5;
		int thickness = 2;

		putText(frame, std::to_string(fps), textOrg, fontFace, fontScale, Scalar::all(255), thickness, 8);

		imshow("Dedly Boys", frame);

		char key = cvWaitKey(10); 
		if (key == 27) // ESC

			break;

		Sleep(200);

		clock_t end = clock();
		double elapsed_secs = 10 * double(end - begin) / CLOCKS_PER_SEC;
		frameNumber++;
		fps = (int) frameNumber / elapsed_secs;
	}
	
	return 0;

}

//#include <ctype.h>
//#include <stdio.h>
//#include <iostream>
//
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/opengl_interop.hpp>
//#include <opencv2/gpu/gpu.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//
///*
//To compile:
//g++ /home/ubuntu/Desktop/FindGoalAndBoulder.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_calib3d -lopencv_contrib -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_video -lopencv_videostab -o FindGoalAndBoulder
//
//Quick formatting fix:
//
//
//*/
//
//using namespace cv;
//using namespace std;
//
///*
//TODO: Setup executable as startup process on boot.
//TODO: Cron job keep alive?
//TODO: I2C and handshake try catch.
//TODO Error: HIGHGUI ERROR: V4L/V4L2: VIDIOC_S_CROP error
//occurs at startup of the program.
//
//
//*/
//
//static void help()
//{
//	cout <<
//		"\nCall:\n"
//		"./FindGoalAndBoulder [camera #, default 0]\n" << endl;
//}
//
////int sigma = 3;
//int smoothType = CV_GAUSSIAN;
//
//int main(int argc, char** argv)
//{
//	/*
//	Recreate steps from GRIP
//	HSL Threshold
//	HUE: 60-114
//	Saturation: 59-255
//	Luminescense: 60-255
//	Find Contours:
//	Filter Contours:
//	Min Area: 100
//	Max Width: 1000?
//	Max Height: 1000
//
//	*/
//
//	// Class for video capturing from video files or cameras.
//	VideoCapture cap;
//	// Provide some helpful runtime info.
//	help();
//
//	if (argc == 1 || (argc == 2 && strlen(argv[1]) == 1 && isdigit(argv[1][0])))
//	{
//		cap.open(argc == 2 ? argv[1][0] - '0' : 0);
//	}
//	else if (argc >= 2)
//	{
//		cap.open(argv[1]);
//		// Check if we succeeded with communicating with the camera
//		if (cap.isOpened())
//			cout << "Video " << argv[1] <<
//			": width=" << cap.get(CV_CAP_PROP_FRAME_WIDTH) <<
//			", height=" << cap.get(CV_CAP_PROP_FRAME_HEIGHT) <<
//			", nframes=" << cap.get(CV_CAP_PROP_FRAME_COUNT) << endl;
//		if (argc > 2 && isdigit(argv[2][0]))
//		{
//			int pos;
//			sscanf(argv[2], "%d", &pos);
//			cout << "seeking to frame #" << pos << endl;
//			cap.set(CV_CAP_PROP_POS_FRAMES, pos);
//		}
//	}
//
//	if (!cap.isOpened())
//	{
//		cout << "Could not initialize capturing...\n";
//		return -1;
//	}
//
//	namedWindow("RoboVision", 0);
//	//createTrackbar( "Sigma", "Laplacian", &sigma, 15, 0 );
//
//	// OpenCV C++ n-dimensional dense array class
//	Mat smoothed, laplace, result;
//
//	for (;;)
//	{
//		Mat frame;
//		// get a new frame from camera
//		cap >> frame;
//		if (frame.empty())
//			break;
//
//		/*int ksize = (sigma*5)|1;
//		if(smoothType == CV_GAUSSIAN)
//		//GaussianBlur(frame, smoothed, Size(ksize, ksize), sigma, sigma);
//		else if(smoothType == CV_BLUR)
//		blur(frame, smoothed, Size(ksize, ksize));
//		else
//		medianBlur(frame, smoothed, ksize);
//		*/
//
//		Laplacian(smoothed, laplace, CV_16S, 5);
//		//convertScaleAbs(laplace, result, (sigma+1)*0.25);
//		// Show the image in the window.
//
//		int c = waitKey(30);
//		if (c == ' ')
//			smoothType = smoothType == CV_GAUSSIAN ? CV_BLUR : smoothType == CV_BLUR ? CV_MEDIAN : CV_GAUSSIAN;
//		if (c == 'q' || c == 'Q' || (c & 255) == 27)
//			break;
//	}
//	// the camera will be deinitialized automatically in VideoCapture destructor
//	return 0;
//}

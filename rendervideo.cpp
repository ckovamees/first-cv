#include "rendervideo.h"
#include "applicationexceptions.h"

#include <boost/concept_check.hpp>
#include <opencv2/opencv.hpp>


using namespace cv;

namespace fcv {
  
  RenderVideo::RenderVideo():BaseCV(), _url()
  {

  }

  RenderVideo::~RenderVideo()
  {

  }

  void RenderVideo::Execute()
  {
      VideoCapture cap("udp://233.1.1.1:10201");
      if (!cap.isOpened())
	throw VideoException(_url);
      
      Mat edges;
      namedWindow("edges", WINDOW_AUTOSIZE);
      
      for (;;) {
	Mat frame;
	cap >> frame;
	cvtColor(frame, edges, COLOR_BGR2GRAY);
	GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
	Canny(edges, edges, 0, 30, 3);
//	imshow("edges", edges);
	
	imshow("edges", frame);
	
	if (waitKey(30) >=0)
	  break;
      }      
  }
  
  void RenderVideo::Wait(int delay)
  {
  }
}

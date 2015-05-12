#include "firstgreyscale.h"

using namespace cv;
using namespace std;

namespace fcv {
  
  FirstGreyScale::FirstGreyScale(std::string filename):FirstCV(), _filename(filename)
  {
  }

  FirstGreyScale::~FirstGreyScale()
  {
  }

  void FirstGreyScale::Execute()
  {
      Mat image;
      image = imread(_filename);
      
      if (image.empty())
      {
	  cout << "Could not open image" << endl;         
	  throw new Exception();
      }
      
      Mat grayImage;
      cvtColor(image, grayImage, COLOR_BGR2GRAY); 
      
      namedWindow("Display Image", WINDOW_AUTOSIZE );
      imshow("Display Image", grayImage);
  }
  
}
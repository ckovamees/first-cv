#include "firstgreyscale.h"
#include "applicationexceptions.h"

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
	  throw IOException(_filename);
      }
            
      Mat grayImage;
      cvtColor(image, grayImage, COLOR_BGR2GRAY); 
      
      namedWindow("Input Image", WINDOW_AUTOSIZE );
      namedWindow("Converted Image", WINDOW_AUTOSIZE );
      
      imshow("Input  Image", image);
      imshow("Converted Image", grayImage);
  }
  
}
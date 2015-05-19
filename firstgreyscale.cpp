#include "firstgreyscale.h"
#include "applicationexceptions.h"

using namespace cv;
using namespace std;

namespace fcv {
  
  FirstGreyScale::FirstGreyScale(std::string filename, bool enableOutput):BaseCV(), _filename(filename), _enableOutput(enableOutput)
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
      
      if (_enableOutput) {
	string grayFilename = AppendFilename(_filename, "_gray");
	cout << "Grayscale filename: " << grayFilename << endl;      
	imwrite( grayFilename.c_str(), grayImage );
      }
      
      imshow("Input Image", image);                        
      imshow("Converted Image", grayImage);            
  }
  
}
#include "renderimage.h"

using namespace std;
using namespace cv;

namespace fcv {
  
  RenderImage::RenderImage(string filename):FirstCV(), _filename(filename)
  {   
  }

  RenderImage::~RenderImage()
  {

  }

  void RenderImage::Execute()
  {
      Mat image;
      image = imread(_filename);
      
      if (image.empty())
      {
	  cout << "Could not open image" << endl;         
	  throw new Exception();
      }
      
      namedWindow("Display Image", WINDOW_AUTOSIZE );
      imshow("Display Image", image);
  }

}
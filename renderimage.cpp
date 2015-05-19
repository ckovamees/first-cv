#include "renderimage.h"
#include "applicationexceptions.h"

using namespace std;
using namespace cv;

namespace fcv {
  
  RenderImage::RenderImage(string filename):BaseCV(), _filename(filename)
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
	  throw IOException(_filename);
      }
      
      namedWindow("Display Image", WINDOW_AUTOSIZE );
      imshow("Display Image", image);
  }

}
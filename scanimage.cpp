#include "scanimage.h"
#include "applicationexceptions.h"

using namespace cv;

namespace fcv {
  
  ScanImage::ScanImage(std::string filename, bool grayscale):BaseCV(), _filename(filename), _grayscale(grayscale)
  {
  }

  ScanImage::~ScanImage()
  {
  }

  void ScanImage::Execute()
  {
      cout << "Scan Image is not implemented yet!" << endl;
  }
  
}
#include "renderimage.h"
#include "firstgreyscale.h"

#include <string>
#include <memory>

using namespace std;
using namespace fcv;

int main(int argc, char** argv)
{
  //std::string filename("/home/ckovamees/src/opencv/opencv-3.0.0-rc1/samples/data/licenseplate_motion.jpg");
  std::string filename("/home/ckovamees/src/opencv/opencv-3.0.0-rc1/samples/data/HappyFish.jpg");
  
  try {
    if (argc > 1)
      filename = argv[1];

    //auto image = make_shared<RenderImage>(filename);
    shared_ptr<FirstCV> image = make_shared<RenderImage>(filename);
    
    image = make_shared<FirstGreyScale>(filename);
    image->Execute();
    image->Wait(0);
    
  } catch (...)
  {
    
  }
}

#include "firstcv.h"

namespace fcv {
  
  FirstCV::FirstCV()
  {
  }

  FirstCV::~FirstCV()
  {
  }

  void FirstCV::Wait(int delay)
  {
    cv::waitKey(delay);
  }

}
#ifndef FirstCV_H
#define FirstCV_H

#include <opencv2/opencv.hpp>

namespace fcv {

  class FirstCV
  {
  public:
      FirstCV();
      virtual ~FirstCV();
      
      virtual void Execute() = 0;
      
      virtual void Wait(int delay = 0);
      
  private:

  };
  
}

#endif // FirstCV_H

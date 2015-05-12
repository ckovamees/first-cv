#ifndef RENDERIMAGE_H
#define RENDERIMAGE_H

#include "firstcv.h"
#include <string>

namespace fcv {
  
  class RenderImage : public FirstCV
  {
  public:  
    //RenderImage() {}
    RenderImage(std::string filename);
    ~RenderImage();
    
    virtual void Execute();
    
  private:
    std::string _filename;
  };

}

#endif // RENDERIMAGE_H

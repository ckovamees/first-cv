#ifndef RENDERVIDEO_H
#define RENDERVIDEO_H

#include "basecv.h"

namespace fcv {
  class RenderVideo : public BaseCV
  {
  public:
    RenderVideo();
    ~RenderVideo();
  
    virtual void Execute();
    virtual void Wait(int delay = 0);
    
  private:
    std::string _url;
  };

}

#endif // RENDERVIDEO_H

#ifndef FIRSTGREYSCALE_H
#define FIRSTGREYSCALE_H

#include "firstcv.h"
#include <string>

namespace fcv {

  class FirstGreyScale: public FirstCV
  {
  public:
    FirstGreyScale(std::string filename);
    ~FirstGreyScale();
    
    virtual void Execute();
    
  private:
    std::string _filename;
  };
  
}

#endif // FIRSTGREYSCALE_H

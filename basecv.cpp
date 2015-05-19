#include "basecv.h"

#include <sstream>

namespace fcv {
  
  BaseCV::BaseCV()
  {
  }

  BaseCV::~BaseCV()
  {
  }

  void BaseCV::Wait(int delay)
  {
    cv::waitKey(delay);
  }

  std::string BaseCV::AppendFilename(std::string filename, std::string append)
  {
    path p(filename);    
    path c = canonical(p);
    
    path newpath = c.parent_path() / path(c.stem().string() + append + c.extension().string());
    
    return newpath.string();
  }
  
}
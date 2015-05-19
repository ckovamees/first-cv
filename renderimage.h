#ifndef RENDERIMAGE_H
#define RENDERIMAGE_H

#include "basecv.h"
#include <string>

namespace fcv {
  
  /**
   * @brief Class that loads image from disk and renders it using OpenCV.
   * 
   */
  class RenderImage : public BaseCV
  {
  public:      
    RenderImage(std::string filename);
    /**
     * @brief Ctor taking a filename to what image to load and render.
     * 
     * @param filename fullpath to filename that will be loaded and rendered.
     */
    ~RenderImage();
    
    /**
     * @brief Overriden vitrual method that will load the specifed filename and render it to screen using OpenCV.
     * 
     * @return void
     */
    virtual void Execute();
    
  private:
    std::string _filename;
  };

}

#endif // RENDERIMAGE_H

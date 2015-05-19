#ifndef FIRSTGREYSCALE_H
#define FIRSTGREYSCALE_H

#include "basecv.h"
#include <string>

namespace fcv {

  /**
   * @brief Class that will load image ffrom disk, render it and create a grayscale
   * verion and render that too. Optionally this class can also write the grayscale image to disk.
   * 
   */
  class FirstGreyScale: public BaseCV
  {
  public:
    /**
     * @brief Ctor for class loading image, converting to grayscale and render them.
     * 
     * @param filename image to load.
     * @param writeOutput if true the grayscale image will be written to disk. Default to (false).
     * The written filename will be <filename>_gray.<extension> in the smae location as the input filename.
     */
    FirstGreyScale(std::string filename, bool writeOutput = false);
    ~FirstGreyScale();
    
    /**
     * @brief Starts the functionallity of loading, converting and render images.
     * 
     * @return void
     */
    virtual void Execute();
    
  private:
    std::string _filename;
    bool _enableOutput;
  };
  
}

#endif // FIRSTGREYSCALE_H

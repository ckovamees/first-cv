#ifndef SCANIMAGE_H
#define SCANIMAGE_H

#include "basecv.h"
#include <string>

namespace fcv {
  
  /**
   * @brief Class that scans images and return benchamrks.
   * 
   */
  class ScanImage :  public BaseCV
  {
  public:
    /**
     * @brief Ctor for class that scans images and provides benchmarks.
     * 
     * @param filename ...
     * @param grayscale ...
     */
    ScanImage(std::string filename, bool grayscale = false);
    ~ScanImage();
    
    /**
     * @brief Starts scanning functionallit, not yet implemented!
     * 
     * @return void
     */
    virtual void Execute();
    
  private:
    std::string _filename;
    bool _grayscale;
  };

}

#endif // SCANIMAGE_H

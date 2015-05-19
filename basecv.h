#ifndef FirstCV_H
#define FirstCV_H

#include <opencv2/opencv.hpp>
#include <boost/filesystem/operations.hpp>

using namespace boost::filesystem;

namespace fcv {

  /**
   * @brief Base class defining calling convetions.
   * 
   */
  class BaseCV
  {
  public:
      BaseCV();
      virtual ~BaseCV();
      
      /**
       * @brief Pure virtual method that need to be override in children. Calling this method will start the functionallity of the child class.
       * 
       * @return void
       */
      virtual void Execute() = 0;
      
      /**
       * @brief Wait for keypress to terminate.
       * 
       * @param delay if specified will wait ms and then automatically return.
       * @return void
       */
      virtual void Wait(int delay = 0);
      
      /**
       * @brief Appends a text to the stem of the filename.
       * 
       * @param filename Original filename to append to.
       * @param append Test to append to the stem.
       * @return std::string appended filename
       */
      virtual std::string AppendFilename(std::string filename, std::string append);
  private:

  };
  
}

#endif // FirstCV_H

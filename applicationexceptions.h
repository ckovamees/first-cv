#ifndef APPLICATIONEXCEPTION_H
#define APPLICATIONEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

namespace fcv {

  class Exception : public std::exception
  {
  public:    
    Exception():exception() {}
    Exception(string message):exception(), _message(message) {}
    
    virtual const char * what() 
    {
      _message.c_str();
    }
    
  protected:    
    std::string _message;
  };
  
  class IOException : public Exception
  {
  public:    
    IOException():Exception() {}
    IOException(string filename = nullptr):Exception("Could not open file."), _filename(filename) {}    
    
    virtual const char * what() 
    {
      ostringstream ss;
      ss << Exception::what();
      
      if (! _filename.empty())
	ss << " " << _filename;
      
      return ss.str().c_str();
    }
    
  protected:
    std::string _filename;
  };

}

#endif // APPLICATIONEXCEPTION_H

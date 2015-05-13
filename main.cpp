#include "renderimage.h"
#include "firstgreyscale.h"
#include "applicationexceptions.h"

#include <string>
#include <memory>
#include <exception>
#include <boost/program_options.hpp>

using namespace std;
using namespace fcv;
using namespace boost::program_options;

int main(int argc, char** argv)
{
  string filename;

  options_description desc("Allowed options");
  desc.add_options()
    ("help,h", "show help")
    ("gray,g", "convert input image to grayscale")
    ("input,i", value<string>(&filename)->default_value("../data/HappyFish.jpg"), "input filename")
    ;    

    positional_options_description p;
    p.add("input", -1);
  
  try {
    variables_map vm;
    store(command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
    notify(vm);

    if (vm.count("help")) {
      cout << desc << endl;
      return 1;
    }
    
    //auto image = make_shared<RenderImage>(filename);
    shared_ptr<FirstCV> task;
    
    
    task = make_shared<RenderImage>(filename);
    
    if (vm.count("gray")) {
      task = make_shared<FirstGreyScale>(filename);
    }
    
    
    task->Execute();
    task->Wait(0);
    
  } catch (IOException & ex)
  {      
      cout << ex.what() << endl;
  } catch (...)
  {
      cout << "Uncaught exception." << endl;
  }
}

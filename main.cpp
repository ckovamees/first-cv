#include "renderimage.h"
#include "firstgreyscale.h"
#include "scanimage.h"
#include "rendervideo.h"
#include "applicationexceptions.h"

#include <string>
#include <memory>
#include <exception>
#include <boost/program_options.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

using namespace std;
using namespace fcv;
using namespace boost::program_options;
using namespace boost::filesystem;

/**
 * @brief main method that will check command-line arguments and
 * start appropriate test functionallity.
 * 
 * @param argc ...
 * @param argv ...
 * @return int
 */
int main(int argc, char** argv)
{
  string filename;
  string url = "udp://233.1.1.1:10201";
  
  options_description desc("Allowed options");
  desc.add_options()
    ("help,h", "show help")
    ("gray,g", "convert input image to grayscale")
    ("scan,s", "sacan every image")
    ("input,i", value<string>(&filename)->default_value("../data/HappyFish.jpg"), "input filename")
    ("write,w", "(use with -g) write output to file <filename>_gray.<ext>")
    ("video,v", "render video")
    //("url", value<string>(&url)->default_value("udp://233.1.1.1:10201"), "render video")
    ("url", "render video")
    ;    

    positional_options_description p;
    p.add("input", -1);    
  
  try {
    // Parse command-line
    variables_map vm;
    store(command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
    notify(vm);

    // Start checking command-line arguments
    if (vm.count("help")) {
      cout << desc << endl;
      return 1;
    }
    
    // Use base class as reference
    shared_ptr<BaseCV> task; 
    
    if (vm.count("scan")) {
      task = make_shared<ScanImage>(filename, vm.count("gray"));
    } else if (vm.count("gray")) {
      task = make_shared<FirstGreyScale>(filename, vm.count("write"));
    } else if (vm.count("video")) {
      task = make_shared<RenderVideo>();
    }
    
    // Default action if no other is found
    if (task == nullptr)
      task = make_shared<RenderImage>(filename);
    
    // Start task and wait until keypress
    task->Execute();
    task->Wait(0);
    
    // TODO: Destroy windows
    
  } catch (IOException & ex) {      
      cout << ex.what() << endl;  
  } catch (cv::Exception & ex) {      
      cout << "OpenCV exception: " << ex.what() << endl;
  } catch (...) {
      //cout << "Unknown error." << endl;
      cout << desc << endl;
  }
}

#include <cob_read_text/text_detect.h>
#include <iostream>

int main(int argc, char* argv[])
{
  if (argc < 4)
  {
    std::cout << "not enought input: detect_text <image> <correlation> <dictionary>" << std::endl;
    return -1;
  }
  DetectText detector = DetectText();
  detector.readLetterCorrelation(argv[2]);
  detector.readWordList(argv[3]);
  ros::init(argc, argv, "run_detection");
  ros::NodeHandle nh;
  detector.setParams(nh);
  detector.detect(std::string(argv[1]));
  return 0;
}

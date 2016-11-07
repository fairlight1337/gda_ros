#include <iostream>
#include <cstdlib>

#include <ros/ros.h>


int main(int argc, char** argv) {
  int nReturnvalue = EXIT_FAILURE;
  
  ros::init(argc, argv, "gda_ros");
  
  ros::spin();
  
  /* Begin code here. */
  nReturnvalue = EXIT_SUCCESS;
  /* End code here. */
  
  return nReturnvalue;
}

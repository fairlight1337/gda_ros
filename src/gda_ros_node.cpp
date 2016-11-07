#include <iostream>
#include <cstdlib>

#include <ros/ros.h>
#include <gda_ros/PlanningService.h>
#include <gdaplanner/GDAPlanner.h>

using namespace gdaplanner;
using namespace gda_ros;


GDAPlanner::Ptr g_gpPlanner;


bool planningCallback(PlanningService::Request& psReq, PlanningService::Response& psRes) {
  ROS_INFO("Received a planning request");
  
  if(g_gpPlanner) {
    if(psReq.goal_conditions.size() > 0) {
      ROS_INFO("Goal conditions:");
      
      for(std::string strLine : psReq.goal_conditions) {
	ROS_INFO(std::string(" * " + strLine).c_str());
	  
	  // TODO: Feed goal condition into the planner here.
      }
      
      if(psReq.world_state.size() > 0) {
	ROS_INFO("World state:");
	
	for(std::string strLine : psReq.world_state) {
	  ROS_INFO(std::string(" * " + strLine).c_str());
	  
	  // TODO: Do something with the world state here; feed it into
	  // the planner, for example.
	}
      } else {
	ROS_INFO("No world state");
      }
      
      // TODO: Plan and assert the result into the service response.
    }
    
    return true;
  } else {
    ROS_ERROR("No planner available.");
  }
  
  return false;
}


int main(int argc, char** argv) {
  int nReturnvalue = EXIT_FAILURE;
  
  ros::init(argc, argv, "gda_ros");
  ros::NodeHandle nh("~");
  
  ROS_INFO("Initializing planner");
  g_gpPlanner = GDAPlanner::create();
  
  ros::ServiceServer srvPlanning = nh.advertiseService("plan", planningCallback);
  
  ROS_INFO("Service ready, you're good to go!");
  
  ros::spin();
  
  ROS_INFO("Shutting down.");
  
  nReturnvalue = EXIT_SUCCESS;
  
  return nReturnvalue;
}

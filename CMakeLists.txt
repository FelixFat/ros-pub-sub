cmake_minimum_required(VERSION 3.0.2)
project(ros_pub_sub)

find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_install_python(PROGRAMS src/pub_talker.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

catkin_install_python(PROGRAMS src/pub_talker.py src/sub_listener.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

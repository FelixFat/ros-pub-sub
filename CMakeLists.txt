cmake_minimum_required(VERSION 3.0.2)
project(temp_package)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_message_files(
  FILES
  Message.msg
)

add_service_files(
  FILES
  Service.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_install_python(PROGRAMS src/pub_talker.py src/sub_listener.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

add_executable(srv_server src/srv_server.cpp)
target_link_libraries(srv_server ${catkin_LIBRARIES})
add_dependencies(srv_server temp_package_gencpp)

add_executable(srv_client src/srv_client.cpp)
target_link_libraries(srv_client ${catkin_LIBRARIES})
add_dependencies(srv_client temp_package_gencpp)

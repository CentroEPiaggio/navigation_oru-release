cmake_minimum_required(VERSION 2.8.3)
project(orunav_manipulator_control)

add_definitions(-std=c++11)

find_package(catkin COMPONENTS lwr_controllers)

if(${lwr_controllers_FOUND})

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  roscpp
  std_msgs
  orunav_msgs
  visualization_msgs
  tf
  tf_conversions
  roslib
  lwr_controllers
)

catkin_package(
  CATKIN_DEPENDS roscpp roslib
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(manipulator_control src/manipulator_control.cpp src/manipulator_control_main.cpp)
add_dependencies(manipulator_control ${catkin_EXPORTED_TARGETS})
target_link_libraries(manipulator_control ${catkin_LIBRARIES})

add_executable(manipulator_control_test tests/manipulator_control_test.cpp)
add_dependencies(manipulator_control_test ${catkin_EXPORTED_TARGETS})
target_link_libraries(manipulator_control_test ${catkin_LIBRARIES})

add_executable(manipulator_control_status_parser tests/manipulator_control_status_parser.cpp)
add_dependencies(manipulator_control_status_parser ${catkin_EXPORTED_TARGETS})
target_link_libraries(manipulator_control_status_parser ${catkin_LIBRARIES})

#############
## Install ##
#############

install(TARGETS manipulator_control manipulator_control_test manipulator_control_status_parser
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

endif()
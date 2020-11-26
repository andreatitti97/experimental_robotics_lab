# Install script for directory: /home/andrea/experimental_robotics_lab/src/assignment_2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/andrea/experimental_robotics_lab/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/exp_assignment2/action" TYPE FILE FILES "/home/andrea/experimental_robotics_lab/src/assignment_2/action/Planning.action")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/exp_assignment2/msg" TYPE FILE FILES
    "/home/andrea/experimental_robotics_lab/devel/share/exp_assignment2/msg/PlanningAction.msg"
    "/home/andrea/experimental_robotics_lab/devel/share/exp_assignment2/msg/PlanningActionGoal.msg"
    "/home/andrea/experimental_robotics_lab/devel/share/exp_assignment2/msg/PlanningActionResult.msg"
    "/home/andrea/experimental_robotics_lab/devel/share/exp_assignment2/msg/PlanningActionFeedback.msg"
    "/home/andrea/experimental_robotics_lab/devel/share/exp_assignment2/msg/PlanningGoal.msg"
    "/home/andrea/experimental_robotics_lab/devel/share/exp_assignment2/msg/PlanningResult.msg"
    "/home/andrea/experimental_robotics_lab/devel/share/exp_assignment2/msg/PlanningFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/exp_assignment2/cmake" TYPE FILE FILES "/home/andrea/experimental_robotics_lab/build/assignment_2/catkin_generated/installspace/exp_assignment2-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/andrea/experimental_robotics_lab/devel/include/exp_assignment2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/andrea/experimental_robotics_lab/devel/share/roseus/ros/exp_assignment2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/andrea/experimental_robotics_lab/devel/share/common-lisp/ros/exp_assignment2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/andrea/experimental_robotics_lab/devel/share/gennodejs/ros/exp_assignment2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/andrea/experimental_robotics_lab/devel/lib/python2.7/dist-packages/exp_assignment2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/andrea/experimental_robotics_lab/devel/lib/python2.7/dist-packages/exp_assignment2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/andrea/experimental_robotics_lab/build/assignment_2/catkin_generated/installspace/exp_assignment2.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/exp_assignment2/cmake" TYPE FILE FILES "/home/andrea/experimental_robotics_lab/build/assignment_2/catkin_generated/installspace/exp_assignment2-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/exp_assignment2/cmake" TYPE FILE FILES
    "/home/andrea/experimental_robotics_lab/build/assignment_2/catkin_generated/installspace/exp_assignment2Config.cmake"
    "/home/andrea/experimental_robotics_lab/build/assignment_2/catkin_generated/installspace/exp_assignment2Config-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/exp_assignment2" TYPE FILE FILES "/home/andrea/experimental_robotics_lab/src/assignment_2/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/exp_assignment2" TYPE PROGRAM FILES "/home/andrea/experimental_robotics_lab/src/assignment_2/scripts/go_to_point_ball.py")
endif()


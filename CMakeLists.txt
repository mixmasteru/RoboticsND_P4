cmake_minimum_required(VERSION 3.17)
project(project4)

set(CMAKE_CXX_STANDARD 14)

add_executable(project4
        src/my_robot/config/base_local_planner_params.yaml
        src/my_robot/config/costmap_common_params.yaml
        src/my_robot/config/global_costmap_params.yaml
        src/my_robot/config/local_costmap_params.yaml
        src/my_robot/launch/amcl.launch
        src/my_robot/launch/robot_description.launch
        src/my_robot/launch/world.launch
        src/my_robot/maps/map.pgm
        src/my_robot/maps/map.yaml
        src/my_robot/meshes/hokuyo.dae
        src/my_robot/model/Building/model.config
        src/my_robot/model/Building/model.sdf
        src/my_robot/model/my_ball/model.config
        src/my_robot/model/my_ball/model.sdf
        src/my_robot/urdf/my_robot.gazebo
        src/my_robot/urdf/my_robot.xacro
        src/my_robot/worlds/myworld.world
        src/my_robot/CMakeLists.txt
        src/my_robot/my_robot.rviz
        src/my_robot/package.xml
        src/pgm_map_creator/launch/request_publisher.launch
        src/pgm_map_creator/maps/map.pgm
        src/pgm_map_creator/maps/map_org.pgm
        src/pgm_map_creator/msgs/CMakeLists.txt
        src/pgm_map_creator/msgs/collision_map_request.proto
        src/pgm_map_creator/src/collision_map_creator.cc
        src/pgm_map_creator/src/request_publisher.cc
        src/pgm_map_creator/world/myworld.world
        src/pgm_map_creator/world/udacity_mtv
        src/pgm_map_creator/CMakeLists.txt
        src/pgm_map_creator/LICENSE
        src/pgm_map_creator/package.xml
        src/pgm_map_creator/README.md
        src/teleop_twist_keyboard/CHANGELOG.rst
        src/teleop_twist_keyboard/CMakeLists.txt
        src/teleop_twist_keyboard/package.xml
        src/teleop_twist_keyboard/README.md
        src/teleop_twist_keyboard/teleop_twist_keyboard.py
        src/wall_chaser/launch/wall_chaser.launch
        src/wall_chaser/src/drive_bot.cpp
        src/wall_chaser/src/SimpleWallChaser.cpp
        src/wall_chaser/srv/DriveToTarget.srv
        src/wall_chaser/CMakeLists.txt
        src/wall_chaser/package.xml
        src/CMakeLists.txt
        src/env.bash
        README.md)

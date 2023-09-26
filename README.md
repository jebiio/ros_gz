[![Build Status](https://github.com/gazebosim/ros_gz/actions/workflows/ros2-ci.yml/badge.svg?branch=ros2)](https://github.com/gazebosim/ros_gz/actions/workflows/ros2-ci.yml)

ROS 2 version | Gazebo version | Branch | Binaries hosted at
-- | -- | -- | --
Humble | Fortress | [humble](https://github.com/gazebosim/ros_gz/tree/humble) | https://packages.ros.org
Humble | Garden | [humble](https://github.com/gazebosim/ros_gz/tree/humble) | only from source
Iron | Fortress | [iron](https://github.com/gazebosim/ros_gz/tree/iron) | https://packages.ros.org
Iron | Garden | [iron](https://github.com/gazebosim/ros_gz/tree/iron) | only from source



# ROS와 Gazebo 연동

## Packages

이 repo에는 ROS와 Gazebo 연동을 위한 아래와 같이 패키지들로 구성:

* [ros_gz](https://github.com/gazebosim/ros_gz/tree/ros2/ros_gz):
  다른 package에 대한 정보만 제공하는 Metapackage
* [ros_gz_image](https://github.com/gazebosim/ros_gz/tree/ros2/ros_gz_image):
  Unidirectional transport bridge for images from
  [Gazebo Transport](https://gazebosim.org/libs/transport)
  to ROS using
  [image_transport](http://wiki.ros.org/image_transport).
* [ros_gz_bridge](https://github.com/gazebosim/ros_gz/tree/ros2/ros_gz_bridge):
  [Gazebo Transport](https://gazebosim.org/libs/transport)
  와 ROS 양방향 전송을 위한 bridge.
* [ros_gz_sim](https://github.com/gazebosim/ros_gz/tree/ros2/ros_gz_sim):
  Convenient launch files and executables for using
  [Gazebo Sim](https://gazebosim.org/libs/gazebo)
  with ROS.
* [ros_gz_sim_demos](https://github.com/gazebosim/ros_gz/tree/ros2/ros_gz_sim_demos):
  Demos using the ROS-Gazebo integration.
* [ros_gz_point_cloud](https://github.com/gazebosim/ros_gz/tree/ros2/ros_gz_point_cloud):
  Plugins for publishing point clouds to ROS from
  [Gazebo Sim](https://gazebosim.org/libs/gazebo) simulations.

## 설치

### 바이너리 설치

1. Add https://packages.ros.org

        sudo sh -c 'echo "deb [arch=$(dpkg --print-architecture)] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'
        curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
        sudo apt-get update

1. Install `ros_gz`

        sudo apt install ros-humble-ros-gz

### 소스 설치

#### ROS

[ROS Humble](https://index.ros.org/doc/ros2/Installation/) 설치

#### Gazebo

[Garden](https://gazebosim.org/docs) 설치

`GZ_VERSION` 환경 변수 설정 :

    export GZ_VERSION=garden

> 컴파일 할때 이 변수가 설정되어 있으면 됨!

#### ros_gz 컴파일하기


1. colcon workspace 생성:

    ```
    # Setup the workspace
    mkdir -p ~/ws/src
    cd ~/ws/src

    # Download needed software
    git clone https://github.com/gazebosim/ros_gz.git -b ros2
    ```

1. 의존성 설치:

    ```
    cd ~/ws
    rosdep install -r --from-paths src -i -y --rosdistro humble
    ```

    > 만약 `rosdep`로 Gazebo libraries 설치가 실패하면, [Gazebo installation instructions](https://gazebosim.org/docs/latest/install) 지시대로 따라하기.

1. workspace 빌드하기:

    ```
    # Source ROS distro's setup.bash
    source /opt/ros/<distro>/setup.bash

    # Build and install into workspace
    cd ~/ws
    colcon build
    ```

## 빌드 중 error 해결하기
* rosidl_pycommon module not found 에러 발생
```bash
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
git clone https://github.com/ros2/rosidl.git
cd rosidl/rosidl_pycommon
sudo python3 setup.py install
```

## ROSCon 2022

[![](img/video_img.png)](https://vimeo.com/showcase/9954564/video/767127300)

## Project Template
[A template project integrating ROS and Gazebo simulator](https://github.com/gazebosim/ros_gz_project_template)

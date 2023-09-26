// Copyright 2022 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROS_GZ_BRIDGE__CONVERT__KARI_INTERFACES_HPP_
#define ROS_GZ_BRIDGE__CONVERT__KARI_INTERFACES_HPP_

#include <ignition/msgs/optical_flow.pb.h>

#include <kari_interfaces/msg/optical_flow.hpp>

#include "ros_gz_bridge/convert_decl.hpp"

namespace ros_gz_bridge
{

template<>
void
convert_ros_to_gz(
  const kari_interfaces::msg::OpticalFlow & ros_msg,
  ignition::msgs::OpticalFlow & gz_msg);

template<>
void
convert_gz_to_ros(
  const ignition::msgs::OpticalFlow & gz_msg,
  kari_interfaces::msg::OpticalFlow & ros_msg);

}  // namespace ros_gz_bridge

#endif  // ROS_GZ_BRIDGE__CONVERT__KARI_INTERFACES_HPP_
// Copyright 2018 Open Source Robotics Foundation, Inc.
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

#include "convert/utils.hpp"
#include "ros_gz_bridge/convert/kari_interfaces.hpp"

namespace ros_gz_bridge
{

template<>
void
convert_ros_to_gz(
  const kari_interfaces::msg::OpticalFlow & ros_msg,
  ignition::msgs::OpticalFlow & gz_msg)
{
  convert_ros_to_gz(ros_msg.header, (*gz_msg.mutable_header()));
  gz_msg.set_distance(ros_msg.ground_distance);
  gz_msg.set_integrated_x(ros_msg.flow_x);
  gz_msg.set_integrated_y(ros_msg.flow_y);
  gz_msg.set_quality(ros_msg.quality);

}

template<>
void
convert_gz_to_ros(
  const ignition::msgs::OpticalFlow & gz_msg,
  kari_interfaces::msg::OpticalFlow & ros_msg)
{
  convert_gz_to_ros(gz_msg.header(), ros_msg.header);
  ros_msg.ground_distance = gz_msg.distance();
  ros_msg.flow_x = gz_msg.integrated_x();
  ros_msg.flow_y = gz_msg.integrated_y();
  ros_msg.quality = gz_msg.quality();
}

}  // namespace ros_gz_bridge

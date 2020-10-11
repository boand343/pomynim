// Generated by gencpp from file webots_ros/supervisor_virtual_reality_headset_get_orientationResponse.msg
// DO NOT EDIT!


#ifndef WEBOTS_ROS_MESSAGE_SUPERVISOR_VIRTUAL_REALITY_HEADSET_GET_ORIENTATIONRESPONSE_H
#define WEBOTS_ROS_MESSAGE_SUPERVISOR_VIRTUAL_REALITY_HEADSET_GET_ORIENTATIONRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Quaternion.h>

namespace webots_ros
{
template <class ContainerAllocator>
struct supervisor_virtual_reality_headset_get_orientationResponse_
{
  typedef supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> Type;

  supervisor_virtual_reality_headset_get_orientationResponse_()
    : orientation()  {
    }
  supervisor_virtual_reality_headset_get_orientationResponse_(const ContainerAllocator& _alloc)
    : orientation(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Quaternion_<ContainerAllocator>  _orientation_type;
  _orientation_type orientation;





  typedef boost::shared_ptr< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> const> ConstPtr;

}; // struct supervisor_virtual_reality_headset_get_orientationResponse_

typedef ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<std::allocator<void> > supervisor_virtual_reality_headset_get_orientationResponse;

typedef boost::shared_ptr< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse > supervisor_virtual_reality_headset_get_orientationResponsePtr;
typedef boost::shared_ptr< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse const> supervisor_virtual_reality_headset_get_orientationResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator1> & lhs, const ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator2> & rhs)
{
  return lhs.orientation == rhs.orientation;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator1> & lhs, const ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace webots_ros

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8ed1de3b69473461225107f55ad59b9d";
  }

  static const char* value(const ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8ed1de3b69473461ULL;
  static const uint64_t static_value2 = 0x225107f55ad59b9dULL;
};

template<class ContainerAllocator>
struct DataType< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "webots_ros/supervisor_virtual_reality_headset_get_orientationResponse";
  }

  static const char* value(const ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Quaternion orientation\n"
"\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.orientation);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct supervisor_virtual_reality_headset_get_orientationResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::webots_ros::supervisor_virtual_reality_headset_get_orientationResponse_<ContainerAllocator>& v)
  {
    s << indent << "orientation: ";
    s << std::endl;
    Printer< ::geometry_msgs::Quaternion_<ContainerAllocator> >::stream(s, indent + "  ", v.orientation);
  }
};

} // namespace message_operations
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_SUPERVISOR_VIRTUAL_REALITY_HEADSET_GET_ORIENTATIONRESPONSE_H

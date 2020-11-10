// Generated by gencpp from file assignment_1/GoToRequest.msg
// DO NOT EDIT!


#ifndef ASSIGNMENT_1_MESSAGE_GOTOREQUEST_H
#define ASSIGNMENT_1_MESSAGE_GOTOREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace assignment_1
{
template <class ContainerAllocator>
struct GoToRequest_
{
  typedef GoToRequest_<ContainerAllocator> Type;

  GoToRequest_()
    : x(0)
    , y(0)  {
    }
  GoToRequest_(const ContainerAllocator& _alloc)
    : x(0)
    , y(0)  {
  (void)_alloc;
    }



   typedef int64_t _x_type;
  _x_type x;

   typedef int64_t _y_type;
  _y_type y;





  typedef boost::shared_ptr< ::assignment_1::GoToRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::assignment_1::GoToRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GoToRequest_

typedef ::assignment_1::GoToRequest_<std::allocator<void> > GoToRequest;

typedef boost::shared_ptr< ::assignment_1::GoToRequest > GoToRequestPtr;
typedef boost::shared_ptr< ::assignment_1::GoToRequest const> GoToRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::assignment_1::GoToRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::assignment_1::GoToRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace assignment_1

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::assignment_1::GoToRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::assignment_1::GoToRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::assignment_1::GoToRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::assignment_1::GoToRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::assignment_1::GoToRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::assignment_1::GoToRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::assignment_1::GoToRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3b834ede922a0fff22c43585c533b49f";
  }

  static const char* value(const ::assignment_1::GoToRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3b834ede922a0fffULL;
  static const uint64_t static_value2 = 0x22c43585c533b49fULL;
};

template<class ContainerAllocator>
struct DataType< ::assignment_1::GoToRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "assignment_1/GoToRequest";
  }

  static const char* value(const ::assignment_1::GoToRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::assignment_1::GoToRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 x\n\
int64 y\n\
";
  }

  static const char* value(const ::assignment_1::GoToRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::assignment_1::GoToRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GoToRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::assignment_1::GoToRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::assignment_1::GoToRequest_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<int64_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<int64_t>::stream(s, indent + "  ", v.y);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ASSIGNMENT_1_MESSAGE_GOTOREQUEST_H

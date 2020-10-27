; Auto-generated. Do not edit!


(cl:in-package assignment_1-msg)


;//! \htmlinclude user_cmd.msg.html

(cl:defclass <user_cmd> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:string
    :initform ""))
)

(cl:defclass user_cmd (<user_cmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <user_cmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'user_cmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name assignment_1-msg:<user_cmd> is deprecated: use assignment_1-msg:user_cmd instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <user_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader assignment_1-msg:command-val is deprecated.  Use assignment_1-msg:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <user_cmd>) ostream)
  "Serializes a message object of type '<user_cmd>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'command))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'command))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <user_cmd>) istream)
  "Deserializes a message object of type '<user_cmd>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'command) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'command) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<user_cmd>)))
  "Returns string type for a message object of type '<user_cmd>"
  "assignment_1/user_cmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'user_cmd)))
  "Returns string type for a message object of type 'user_cmd"
  "assignment_1/user_cmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<user_cmd>)))
  "Returns md5sum for a message object of type '<user_cmd>"
  "cba5e21e920a3a2b7b375cb65b64cdea")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'user_cmd)))
  "Returns md5sum for a message object of type 'user_cmd"
  "cba5e21e920a3a2b7b375cb65b64cdea")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<user_cmd>)))
  "Returns full string definition for message of type '<user_cmd>"
  (cl:format cl:nil "string command~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'user_cmd)))
  "Returns full string definition for message of type 'user_cmd"
  (cl:format cl:nil "string command~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <user_cmd>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'command))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <user_cmd>))
  "Converts a ROS message object to a list"
  (cl:list 'user_cmd
    (cl:cons ':command (command msg))
))

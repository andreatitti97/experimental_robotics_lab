;; Auto-generated. Do not edit!


(when (boundp 'assignment_1::user_cmd)
  (if (not (find-package "ASSIGNMENT_1"))
    (make-package "ASSIGNMENT_1"))
  (shadow 'user_cmd (find-package "ASSIGNMENT_1")))
(unless (find-package "ASSIGNMENT_1::USER_CMD")
  (make-package "ASSIGNMENT_1::USER_CMD"))

(in-package "ROS")
;;//! \htmlinclude user_cmd.msg.html


(defclass assignment_1::user_cmd
  :super ros::object
  :slots (_command ))

(defmethod assignment_1::user_cmd
  (:init
   (&key
    ((:command __command) "")
    )
   (send-super :init)
   (setq _command (string __command))
   self)
  (:command
   (&optional __command)
   (if __command (setq _command __command)) _command)
  (:serialization-length
   ()
   (+
    ;; string _command
    4 (length _command)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _command
       (write-long (length _command) s) (princ _command s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _command
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _command (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get assignment_1::user_cmd :md5sum-) "cba5e21e920a3a2b7b375cb65b64cdea")
(setf (get assignment_1::user_cmd :datatype-) "assignment_1/user_cmd")
(setf (get assignment_1::user_cmd :definition-)
      "string command


")



(provide :assignment_1/user_cmd "cba5e21e920a3a2b7b375cb65b64cdea")



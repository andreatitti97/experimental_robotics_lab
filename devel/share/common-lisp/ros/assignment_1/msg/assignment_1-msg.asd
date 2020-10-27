
(cl:in-package :asdf)

(defsystem "assignment_1-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "user_cmd" :depends-on ("_package_user_cmd"))
    (:file "_package_user_cmd" :depends-on ("_package"))
  ))
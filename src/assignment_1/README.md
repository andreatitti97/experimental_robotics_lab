# Assignment - 1 Experimental Robotics Laboratory
## Introduction
In this assignment is required to build a basic software architecture that simulates the behaviour of a robotic dog, in particulary similar to the MIRO robot. The robot should switch between 3 state of possible action:
 -__NORMAL__ : Robot move in random position.
 -__SLEEP__ : Robot go to home (predefined position) and don't move for some time
 -__PLAY__: Robot after a vocal command 'play' should follow a gesture recognition and return to the user and before stop playing should 
## Software architecture and states diagrams 
The architecture consist of 4 elements, 3 nodes and one server. 
 -__user_cmd__: Is a node of type 'publisher'. Simulate the user speech command publishing a string with 'play' randomly to '/cmd_string' topic.
 -__pos_generator__: Node type 'publisher'. Simulate both the gesture recognition and the 'NORMAL' state behaviour, publishing geometry_msgs/2DPose to the '/position' topic. This message corresponds to the 2D position of the robot that is random chosen.
 -__user_cmd__: Node that is the core of the system, is here where the state are handled with a Finite State Machine that switch between the 3 states of our robot. In fact this node subscribe both '/position' and '/cmd_string' from which receiverespectively the command to switch to PLAY state and the position for the navigation during NORMAL and PLAY.
 -__navigation_server__: The service of the architecture simulate the navigation system of the robot, the 'user_cmd' make a request to the server sending a goal position and the server simulate the navigation responding that the goal posisition i reached after a delay.

FOR SEE THE GRAPH TYPE THE COMMAND BELOW DURING THE EXECUTION OF THE WHOLE PROJECT

```
$ rqt_graph
```


## Finite State Machine 
The FSM as already said is implemented inside 'usr_cmd' node, below the charactheristic of each state:  
* __NORMAL__ : Initial state. It check uf the user send the cmd and in this case enter state PLAY, otherwise remain in NORMAL mode and navigate randomly requesting for each random posisiton (coming from the /pos_generator node) the navigation service. This routine is iterated randomly before go to sleep (for see better the behaviour i choose 5 iterations max).
* __PLAY__ : If the FSM enter this state after receveing the 'user_cmd' the robot start move randomly (as it follows the user gesture) and after some time return to the user: the cmd_manager make the request giving the user posistion to the nvigation service.
* __SLEEP__ : The robot go to the home (pre defined positon), 'cmd_manager' request to the /navigation service to navigate giving the home position.

For see the behaviour of the FSM use the command below in a different terminal.
```
$ rosrun smach_viewer smach_viewer.py
```

## Packges and file list

 __Package__ : - assignment_1

 __File List__: (/assignment_1/src)

		- cmd_manager.py
		- user_cmd.cpp
		- navigation_server.cpp
		- pos_generator.cpp
		
## Documentation
file:///home/andrea/experimental_robotics_lab/src/assignment_1/doc/html/index.html
		
## Installation
Install the _smach_ library which allows to implement a _Finite State Machine.
```
$ sudo apt-get install ros-kinetic-smach-viewer
```
compile the ROS workspace using (remeber to source the workspace in every terminal for using the application)
```
$ cd /<your_workspace>
$ catkin_make
```
then in the same directory as before( the root of the ws ) type:
```
$ roslaunch assignment1 assignment1.launch
```
However in the terminal you can see the following logs:
- __Going to x = .. and y = ..__ which is actually a log of the _navigation_server_  
- __Robot arrived position x = .. and y = ..__ 
- __Received cmd_play__ which means that the _cmd_manager_ has recived a string _play_ from the _user_cmd_ node
- __Returning Home__ and 
- __Going To User__ and __Robot returned to user__ when the robot is arrived.


## Limitation
- _Static useful positions_: The user and home posisitons are both defined statically, it's not possible to change them during the execution
- _Map_:  Static Map definition, correspond to simply 2 axis with a max dimension.
- During _SLEEP_ all 'user_cmd' PLAY from the /cmd_String topic are rejected, also the first PLAY cmd in normal mode is rejected.
- We cannot block the system while doing an action inside a state, there are no routine to handling particular situation. (i.e. if the robot in SLEEP mode or in PLAY mode every cmd or possible action is ignored until the finish of the action):


## Possible improvements:
- Replace the node _pos_generator.cpp_ with more nodes for effectevely use the gesture recognition.
- Make the robot recognize autonomosly the user posisiton. 
- Implement a simulation environment (i.e. Gazebo) 
- Implemente a navigation algortihm (i.e SLAM ...)
- Implement voice recognition. 
## Contacts
Andrea Tiranti e-mail: andrea.tiranti97@gmail.com


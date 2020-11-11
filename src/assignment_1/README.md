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

##Packges and file list
 __Package__ : - assignment_1
 __File List__: (/assignment_1/src)
		- cmd_manager.py
		- user_cmd.cpp
		- navigation_server.cpp
		- pos_generator.cpp
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

## System's limitation and possible improvements
### Limitation
As already mentioned there are some position which currently must be configured in advance such as:
- _Home_ position: is currently set in position x = 10 and y = 20 as you can see in the _commandManager_ (__homeX__ and __homeY__ global variables)
- _User position_: since the robot is currently not able to localize person , therefore it was necessary to give the system a known position for it and of course we assume that the person always remains in the same position.
- _Map_:  was defined simply with two parameters indicating the maximum dimension along the x and y axes (__Xmax__ and __Ymax__ in the _Navigation_ code) which is sufficent since it is just a 2D map . No obstacles have been added since it was not required to implement an obstacle avoidance algorithm. 

Regarding the _FSM_ was necessary to add some constraints which consist of : 
When ther robot is in a SLEEP mode it cannot do anything utill the sleeptime is over. So even if the _commandManager_ recives a _play_ command from the _speackPerception_ publisher it could not go to _PLAY_ mode. Another limitation is that currently is not possible to remain in the _PLAY_ state without first returning to the NORMAL state (for istance sending a _play_ string from _speakPerception_).

### Possible improvements:
- Improve the _getPosition_ node with a drive which is really able to percive pointing gesture positions. And maybe move the currently random postion generator in the _commandManager_ node for maintaining the random navigation fiture. 
- Give the possibility to the user to change the home and his/here positions. 
- Implement a proper simulation environment. 
- Add a more efficent and realistic navigation algorithm and/or a SLAM algo.
- Develop drivers to actually receive sensor data also from a microphone.
## Contacts
Andrea Tiranti e-mail: andrea.tiranti97@gmail.com


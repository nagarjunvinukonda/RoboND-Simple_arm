# RoboND-Simple_arm
Simple arm manipulator in ROS which focuses away when looking at uniform colour


# Launching the nodes
After downloading we can launch and interact with simple_arm
```
$ cd /home/workspace/catkin_ws/
$ source devel/setup.bash
$ roslaunch simple_arm robot_spawn.launch
```
# Interacting with the arm
After launching, the arm should move away from the grey sky and look towards the blocks. To view the camera image stream:
```
$ rqt_image_view /rgb_camera/image_raw
```
To check that everything is working as expected, open a new terminal and send a service call to point the arm directly up towards the sky (note that the line break in the message is necessary):
```
$ cd /home/workspace/catkin_ws/
$ source devel/setup.bash
$ rosservice call /arm_mover/safe_move "joint_1: 0
joint_2: 0"
```

![Screenshot (37)](https://user-images.githubusercontent.com/49041896/93392653-2bd18180-f83f-11ea-9e7f-74de4a0bb2eb.png)

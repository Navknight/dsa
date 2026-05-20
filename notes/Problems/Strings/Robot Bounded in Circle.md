---
difficulty: Medium
topics: ["Simulation"]
source: Leetcode
star: false
code: ../../../LeetCode/robot_bounded_in_circle.cpp
---

[[Simulation]]

[Robot Bounded In Circle - LeetCode](https://leetcode.com/problems/robot-bounded-in-circle/?envType=study-plan-v2&id=programming-skills) #  # -  loop over the instructions string and according to each instruction - G,L,R. update a set of integers - x,y,dir
representing the coordinate of x,y and the direction of the robot with 0 = north and 3 = west.
if the x and y coordinates are 0 at the end of the loop, then the robot is already at the origin and hence completed a circle.
if the direction variable is anything other than 0, that means the robot can turn during the instruction set and hence it can form a circle.
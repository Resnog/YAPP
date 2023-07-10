# YAPP
Yet Another Path Planner - Using Python

For the python implementation the main idea is to use PyBullet as a simulation
environment, this way Bullet3 is used without too much tinkering allowing an 
easier testing and simulation.

The being said, libraries like the Robotics Toolbox of Peter Corke are being 
ported to Python. Also using NumPy, SciPy, Matplotlib, TensorFlow and from 
here on you can pick your poison, it gives multiple choices regarding libraries
and possible implementations.

This makes for a fun time in testing some algorithms, but alas, this isn't really
about a performant solution. A last thing anyone might want to add is that though 
PyBullet has no real ROS or ROS2 support, this is something thas has been solved
by many research departments for their specific use cases, some have even published
their solutions.

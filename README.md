This project (from the 42 school syllabus) uses the raycasting technique to create a 3D world based on the videogame Wolfenstein 3D. 
(The world in my project is inspired by the video game Rainbow Unicorn Attack. If you don't know it, you should check it out)!

https://raw.githubusercontent.com/lyie28/CUB3D/master/cub3D.bmp

The project is designed to work on Linux. I will add a Mac version when I get a spare moment.

How to download:

git clone https://github.com/lyie28/CUB3D

How to run:

make
./cub3D map.cub

Keys:

- N move up
- S move right
- E move left
- W move down
- <- (turn camera to left)
- -> (turn camera to right)
- Esc (exit)


How to modify:
You can modify the map.cub file to change the resolution, colours and images that are projected in the program.

Resources:

I followed Pikuma's raycasting course to get to grips with the maths behind this project.
I would thoroughly recommend the course to anyone who wants to learn how to use the raycasting technique. [https://courses.pikuma.com/courses/raycasting-c]

Not to 42 students**:
Note that for the 42 assessment, when you use --save, your program should not open the game in a window. It should only create the .bmp image. (I will update this later)

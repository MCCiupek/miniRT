### MiniRT

### Mandatory part

Check that the project compiles well (without relink) when you execute the main command and that the executable name is « miniRT »

(Y/N)


### Configuration file

Check that you can configure camera(s), light(s), the window size, the ambiant light ratio and simple objects in the configuration site in accordance with the format described in the subject. Also check that the program returns an error and exits properly when the configuration file is misconfigured or if the filename doesn’t end with « .rt » extension.

(Y/N)


### Technical elements of the display

In this section we’ll evaluate technical elements of the display. Run the program and execute the following 6 tests. If at least one fails, no points will be awarded for this section. Move to the next one.

- With only one parameter a window must open when launching the program and stay open during the program’s whole execution.
- Hide either part of the window or the whole window with another window or the screen’s border, minimize the window and maximize it back. In every case the window’s content must remain consistant.
- When you change the window resolution in the configuration file, the window’s content must remain consistant.
- If the resolution set in the configuration file is bigger than the display resolution the window resolution has to be limited to the display resolution.
- With the option « —save » as the second parameter, check that the program doesn’t open a window but only generate a « .bmp » image of the render with the expected size.
- Pressing « EXC » or clicking the Red Cross of the window exits the program properly

(Y/N)


### The 5 Basic Shapes

In this section we’ll evaluate the 5 basic shapes. Run the program and execute the following 5 tests. If at least one fails, no points will be awarded for this section. Move to the next one.

- Place a sphere at the coordinates (0, 0, 0). With the camera facing the sphere, display the rendered image. The sphere should be visible and displayed without glitching.
- Place a plane with a ‘z’ value of null. With the camera facing the plane, display the rendered image. The plane should be visible and displayed without glitching.
- Place a square’s center at the coordinates (0, 0, 0) with a side size of 10 and a blue (0, 0, 255) color. With the camera facing the square, display the rendered image. The square should be visible and displayed without glitching.
- Place a cylinder extending along the y axis. With the camera facing the cylinder, display the rendered image. The cylinder should be visible and displayed without glitching.
- Place a triangle with the following coordinates : point1 (0, 20, 0), point2(0, 0, 0), point3 (0, 10, 20) with a color set to (255, 255, 0). Display the image rendered. The triangle should be visible and displayed without glitching.

(Y/N)


### Translation and rotation

In this section we’ll evaluate that rotation and translation transformations can be applied on the scene’s objects. Run the program and execute the following 2 tests. If at least one fails, no points will be awarded for this section. Move to the next one.

- Place two sphere at the coordinates (0, 0, 0), the camera facing those spheres. Then put a translation on one of the two spheres oriented in a direction parallel to the camera’s, of a greater distance than the sphere diameter and display the rendered image. Both spheres should be visible and displayed without glitching.
- Place a cylinder extending along the y axis, the camera facing the cylinder. Then put a 90° rotation (PI/2 radian) along the z axis and display the rendered image. The cylinder should be visible and displayed without glitching.

(Y/N)


### Multi-objects


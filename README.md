# MiniRT

## Mandatory part

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

In this section we’ll evaluate that it’s possible to put several object in one scene. Run the program and execute the following 2 tests. If at least one fails, no points will be awarded for this section. Move to the next one.

- Place several intersecting objects on the scene, such as for example a sphere and a cylinder, and display the rendered image. Both objects should be visible and displayed without glitching (especially where both objects intersect).
- Execute the same test, but ensure it’s possible le to place the same object several times, for example two cylinders, two spheres and a plane.

(Y/N)


### Camera’s position and direction

In this section we’ll evaluate that the camera conditions of the subject are respected. Run the program and execute the following 5 tests. If at least one fails, no points will be awarded for this section. Move to the next one.

- Generate a random scene and place the camera extending along the x axis pointed towards the coordinates (0, 0, 0) and display the rendered image. The scene lust be visible and displayed without glitching.
- Generate a random scene and place the camera extending along the y axis pointed towards the coordinates (0, 0, 0) and display the rendered image. The scene lust be visible and displayed without glitching.
- Generate a random scene and place the camera extending along the z axis pointed towards the coordinates (0, 0, 0) and display the rendered image. The scene lust be visible and displayed without glitching.
- Generate a random scene and place the camera at a random location which isn’t on any axis or a diagonal, pointed towards the coordinates (0, 0, 0) and display the rendered image. The scene lust be visible and displayed without glitching.
- Place three cameras in the configuration file and ask the student to show you which keyboard keys they choose to switch between cameras. You must be able to switch between cameras without exiting the program. The scene must be visible and displayed from the new point of view without glitching.

(Y/N)


### Brightness 1/2

In this section we’ll evaluate brightness on the scene’s objects. Run the program and execute the following 2 tests. If at least one fails, no points will be awarded for this section. Move to the next one.

- Place a sphere at the coordinates (0, 0, 0), the camera facing the sphere, and put a spot left or right of the camera but position in such way that the sphere will be lit sideways. Display the rendered image. The sphere should be visible, illuminated and displayed without glitching.
- Place a sphere at some coordinates resulting form a translation, the camera facing the sphere, and place a spot left or right of the camera but position in such way that the sphere will be lit sideways. Display the rendered image. The sphere should be visible, properly illuminated and displayed without glitching. Properly means that the holo of light should be computed after translation not before.

(Y/N)


### Brightness 2/2

In this section we’ll evaluate shadow management generated by the scene’s objects. Run the program and execute the following 2 tests. If at least one fails, no points will be awarded for this section. Move to the next one.

- Place a vertical spot, a sphere and a plane. The spot lighting the sphere’s position to create a sphere shadow on the plane. Put the camera aside so we can see the sphere, the place and the sphere’s shadow on the plane. The shadow must be properly displayed without glitching.
- Put a complex scene together with several objects like on illustration V.6 page 10 of the subject. Shadows lust be properly displayed without glitching.

(Y/N)


### Multi-spots

In this section we’ll evaluate that it’s possible to have several spots in the same scene. Run the program and execute the following test. If at least one fails, no points will be awarded for this section. Move to the next one.

- Put together a scene with several objects including at least a plane in which shadows will be projected as well as 2 spots minimum. Check that brightness, shadows  and shine effect (if implemented) work properly.

(Y/N)


## Bonus

(…)

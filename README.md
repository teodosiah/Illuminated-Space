# Illuminated Space
C ++ algorithm that calculates the following task:
  Imagine having a light source attached to the top of a large room. This light source illuminates a certain space from the floor of the room. 
  What we want to find is the geometric representation of the light beam and the illuminated floor space under the conditions described below:
   - The light source is schematically represented by a regular quadrangular pyramid with a surrounding edge equal to the main one.
   - At the base of the pyramid there is a square "blend"(opening) that is centered on the base and can change from fully closed to the full size of the base.
   - We assume that the space between the "blend" and the main edges of the pyramid does not miss light.

  The light beam descends from the top of the pyramid
  Let us fix the beginning of a rectangular coordinate system at the top of the pyramid. Axes X and Y are parallel to the main edges of the pyramid, 
  Z points down to the floor.  The light source can rotate around the Y-axis, with a fixed point at the top of the pyramid, 
  but not around the X and Z axes.

  As input parameters we define:
  - The length of the main edge of the light body (from 10 cm to 25 cm);
  - The height of the room (from 260 cm to 480 cm);
  - Blend side size not greater than the length of the main edge of the light body;
  - Angle of rotation of the light source around the Y-axis (in degrees) [-60, +60], for 0 degrees we accept the vertical position of the light source;

With user defined parameters, calculate the coordinates of the points that define the illuminated floor space (assuming there is no light scattering).
The calculated coordinates (rounded to the second decimal point) display on the screen.

The user can choose between two options:
- Task 1: The calculations are on an unlimited plane
- Task 2: Calculate the coordinates of the points on the floor of a room (the room is square). The user has to specify the area of the room.

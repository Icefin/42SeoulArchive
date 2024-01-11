### Description
---
FdF is a C-based wireframe viewer that utilizes a minimal graphics library.

A wireframe model is a visual representation of three-dimensional physical object used in 3D computer graphics. It is created by specifying each edge of the physical object where two mathematically continuous smooth surfaces meet, or by connecting an object's constituent vertices using lines or curves.
![!\[Alt text\](result.png)](screen.png)

### Features
---
- Translatable, rotatable, zoomable camera with keyboard input
- Support two camera modes : Orthographic, Perspective projection mode
- Line drawing with bresenham's algorithm
- Vertex clipping outside of camera view
- Simple vertex shader convert vertex from world space to screen space


### Controls
---
- W - Move the camera forward
- A - Move the camera left
- S - Move the camera backward
- D - Move the camera right
- O - Rotate the camera up
- K - Rotate the camera left
- L - Rotate the camera down
- : - Rotathe the camera right
- Q - Zoom in the camera
- E - Zoom out the camera
- P - Switch camera mode to realistic, slow rendering
- ESC - Exit the program
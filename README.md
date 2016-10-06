# ComputerGraphics

This repository is for the Graphics assessment for Year 2. It contains multiple compiled programs for each required part of the assessment.

Each is implemented as an application class derived from <b>BaseApplication</b>. To run a certain example simply change the application being created within <b>main.cpp</b>.

Current working examples are:

- <b>IntroToOpenGL</b> [Read Me](https://docs.google.com/document/d/1IJtbUiv4CHTNCCFirTcbIrJLG3M_SDe69oCyLwc9VXA/edit?usp=sharing) (Demostrates setting up and OpenGL context window using GLFW as the wrangler)
- <b>SolarSystemApplication</b> (uses Gizmos to demonstrate matrix parenting)
- <b>RenderingGeomApplication</b> (rendered quad using GL VAO, VBO, IBO and hard-coded shader program)
- <b>TexturingApplication</b> (texture applied across a quad using GL VAO, VBO and IBO)
- <b>ProceduralGenerationApplication</b> (demonstrates using Perlin Noise to populate a texture and displacement mapping in a vertex shader)
- <b>GUIApplication</b> (demonstrates using IMGUI for UI elements)
  - <b>LightingSphereApplication</b> (demonstrates Phong lighting on a generated sphere)

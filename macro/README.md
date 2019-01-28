# Input Macros Playback

This was a toy project to learn about how z3d games read / handle inputs. When activated it points hijacks important data structures pointing to the *live* inputs and instead points them prerecorded inputs.

Only buttons, touchscreen, and circle pad are hooked. Gyro, accelerometer, ZL/ZR/cpp, and homebutton are not hooked and will still funciton as normal. Since this is running in process the home menu can interupt the input playback with no playback issues.

### Note
Currently this uses inputs chosen at compile time but it would certainly be possible to record inputs onto the heap and play them back or even from an input file on the sd card. However, for recording inputs / playing back it would be a lot simpler to instead create a proxy service to man-in-the-middle communication with the **hid:USER** port. Doing it that the other way allows for a lot more flexibility, the ability to implement save states / realtime saves the NTR does, fewer modifications to the game, and basic game agnostic support.

### How to use
Press d-pad left to swap between live inputs and prerecorded inputs

## Inputs demoed
The inputs currently programmed will perform max height consecutive mask jumps, a glitch in mm3d used to achive arbitrary height as zora.

#### Preconditions for the inputs:
- Be in the air as zora, with fins retracted
- Bottle on X
- Deku on Y and in the bottom right mask slot
- Goron in the mask slot above deku
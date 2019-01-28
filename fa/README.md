# Frame Advance
These hook into the main loop in the main thread of the respective game. Anything not handled by the main thread will not be paused, ie things like graphics, audio, trade / collapse timer, ... Inputs and touchscreen are buffered, gyro will act weird.

## How to Use
To use, d-pad left is step 1 frame then stop, d-pad right is stop / start.

## Warnings
Attemping to sleep the 3ds while the game is paused will essentially lock the device as it also pauses the handler for the 3ds properly going to sleep. You will need to either reboot the 3ds either by holding the power button. Additional note is that the handler for going to the home menu is paused, so going to the home menu and closing the game will get paused.

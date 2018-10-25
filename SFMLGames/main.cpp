#include "robot_config.h"

#ifndef VEX_SIMULATOR_MODE
#else
#endif

int main()
{
	#ifdef VEX_SIMULATOR_MODE
	vex::brain Brain;
	#else
	#define ACTIVE true
	#endif

	while (ACTIVE)
	{
		Brain.Screen.clearScreen(vex::color::red);
		Brain.Screen.drawRectangle(3, 3, 100, 100, vex::color::blue);

		// Swaps the buffers (ends the frame)
		Brain.Screen.render();
	}

	return 0;
}
#pragma once
#include <SFML/Graphics.hpp>
#include "vex_submodules.h"

#define VEX_SIMULATOR_MODE true
#define ACTIVE Brain.Screen.update()

void pollEvents(sf::Window* window);

namespace vex
{
	class brain
	{
	public:
		vex::lcd Screen;
	};
}
#pragma once
#include <SFML/Graphics.hpp>

namespace vex
{
	class analogUnits
	{
	public:
		static analogUnits pct;
		static analogUnits range8bit;
		static analogUnits range10bit;
		static analogUnits range12bit;
		static analogUnits mV;
	};

	class brakeType
	{
	public:
		static brakeType coast;
		static brakeType brake;
		static brakeType hold;
	};

	class color
	{
	public:
		color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
		const sf::Color underlying;
		static const color black;
		static const color white;
		static const color red;
		static const color green;
		static const color blue;
		static const color yellow;
		static const color orange;
		static const color purple;
		static const color cyan;
		static const color transparent;
	};

	class currentUnits
	{
	public:
		static currentUnits amp;
	};

	class directionType
	{
	public:
		static directionType fwd;
		static directionType rev;
	};

	class distanceUnits
	{
	public:
		static distanceUnits mm;
		static distanceUnits in;
		static distanceUnits cm;
	};

	class fontType
	{
	public:
		static fontType mono12;
		static fontType mono15;
		static fontType mono20;
		static fontType mono30;
		static fontType mono40;
		static fontType mono60;

		static fontType prop20;
		static fontType prop30;
		static fontType prop40;
		static fontType prop60;
	};

	class percentUnits
	{
	public:
		static percentUnits pct;
	};

	class powerUnits
	{
	public:
		static powerUnits watt;
	};

	class rotationUnits
	{
	public:
		static rotationUnits deg;
		static rotationUnits rev;
		static rotationUnits raw;
	};

	class timeUnits
	{
	public:
		static timeUnits sec;
		static timeUnits msec;
	};

	class torqueUnits
	{
	public:
		static torqueUnits Nm;
		static torqueUnits InLb;
	};

	class velocityUnits
	{
	public:
		static velocityUnits pct;
		static velocityUnits rpm;
		static velocityUnits dps;
	};
}
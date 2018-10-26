#pragma once
#include <SFML/Graphics.hpp>
#include "vex_submodules.h"

#define VEX_SIMULATOR_MODE true
#define ACTIVE Brain.Screen.update()

void pollEvents(sf::Window* window);

namespace vex
{
	class accelerometer
	{
	public:
		int32_t value(analogUnits units);
		int32_t value(percentUnits units);
		void changed(void(*callback(void)));
	};

	class analog_in
	{
	public:
		int32_t value(analogUnits units);
		int32_t value(percentUnits units);
		void changed(void(*callback(void)));
	};

	class brain
	{
	public:
		void resetTimer();
		void setTimer(double value, timeUnits units);
		double timer(timeUnits units);
		
		vex::lcd Screen;
		vex::sdcard SDcard;
	};

	class bumper
	{
	public:
		int32_t pressing();
		void pressed(void(*callback(void)));
		void released(void(*callback(void)));
	};

	class competition
	{
	public:
		void autonomous(void(*callback(void)));
		void drivercontrol(void(*callback(void)));
		bool isEnabled();
		bool isDriverControl();
		bool isAutonomous();
		bool isCompetitionSwitch();
		bool isFieldControl();
	};

	class controller
	{
	public:
		vex::button & ButtonL1;
		vex::button& ButtonL2;
		vex::button& ButtonR1;
		vex::button& ButtonR2;
		vex::button& ButtonUp;
		vex::button& ButtonDown;
		vex::button& ButtonLeft;
		vex::button& ButtonRight;
		vex::button& ButtonX;
		vex::button& ButtonB;
		vex::button& ButtonY;
		vex::button& ButtonA;
		vex::axis& Axis1;
		vex::axis& Axis2;
		vex::axis& Axis3;
		vex::axis& Axis4;
		void rumble(const char *str);
		vex::lcd Screen;
	};

	class digital_in
	{
	public:
		void high(void(*callback(void)));
		void low(void(*callback(void)));
		int32_t value();
	};

	class digital_out
	{
	public:
		void set(bool value);
		int32_t value();
	};

	class encoder
	{
	public:
		void resetRotation();
		void setRotation(double val, rotationUnits units);
		double rotation(rotationUnits units);
		double velocity(velocityUnits units);
		void changed(void(*callback(void)));
	};

	class gyro
	{
	public:
		void startCalibration();
		int32_t value(analogUnits units);
		double value(rotationUnits units);
		int32_t value(percentUnits units);
		bool isCalibrating();
		void changed(void(*callback(void)));
	};

	class light
	{
	public:
		int32_t value(analogUnits units);
		int32_t value(percentUnits units);
		void changed(void(*callback(void)));
	};

	class limit
	{
	public:
		int32_t pressing();
		void pressed(void(*callback(void)));
		void released(void(*callback(void)));
	};

	class line
	{
	public:
		int32_t value(analogUnits units);
		int32_t value(percentUnits units);
		void changed(void(*callback(void)));
	};

	class motor
	{
	public:
		void setReversed(bool value);
		void setVelocity(double velocity, velocityUnits units);
		void setStopping(brakeType mode);
		void resetRotation();
		void setRotation(double value, rotationUnits units);
		void setTimeout(int32_t time, timeUnits units);

		void setMaxTorque(double value, percentUnits units);
		void setMaxTorque(double value, torqueUnits units);
		void setMaxTorque(double value, currentUnits units);

		void spin(directionType dir);
		void spin(directionType dir, double velocity, velocityUnits units);

		bool rotateTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);
		bool rotateTo(double rotation, rotationUnits units, bool waitForCompletion = true);

		bool rotateFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);
		bool rotateFor(double rotation, rotationUnits units, bool waitForCompletion = true);
		void rotateFor(double time, timeUnits units, double velocity, velocityUnits units_v);
		void rotateFor(double time, rotationUnits units);

		void startRotateTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v);
		void startRotateTo(double rotation, rotationUnits units);
		void startRotateFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v);
		void startRotateFor(double rotation, rotationUnits units);

		void stop();
		void stop(brakeType mode);

		bool isSpinning();
		double rotation(rotationUnits units);
		double velocity(velocityUnits units);
		double current(currentUnits units);
		double power(powerUnits units);
		double torque(torqueUnits units);
		double efficiency(percentUnits units);
		double temperature(percentUnits units);
	};

	class motor29
	{
	public:
		void setVelocity(double velocity, percentUnits units);
		void setReversed(bool value);
		void spin(directionType dir);
		void spin(directionType dir, double velocity, velocityUnits units);
		void stop();
	};

	class motor_victor
	{
	public:
		void setVelocity(double velocity, percentUnits units);
		void setReversed(bool value);
		void spin(directionType dir);
		void spin(directionType dir, double velocity, velocityUnits units);
		void stop();
	};

	class pot
	{
	public:
		int32_t value(analogUnits units);
		int32_t value(percentUnits units);
		double value(rotationUnits units);
		void changed(void(*callback(void)));
	};

	class pwn_out
	{
	public:
		void state(int32_t value, percentUnits units);
	};

	class servo
	{
	public:
		void position(double value, percentUnits units);
		void position(double value, rotationUnits units);
	};

	class sonar
	{
	public:
		double distance(distanceUnits units);
		void changed(void(*callback(void)));
	};

	class task
	{
	public:
		void setPriority(int32_t priority);
		void stop();
		void suspend();
		void resume();
		int32_t priority();
		static void sleep(uint32_t time);
		static void yield();
		static void stop(int(*callback(void)));
	};

	class vision
	{
	public:
		// TODO: setLEdMode, takeSnapshot overloads, getLedMode, object array
		class object
		{
			const int& id;
			const int& originX;
			const int& originY;
			const int& centerX;
			const int& centerY;
			const int& width;
			const int& height;
			const double& angle;
			const bool& exists;
		};
		bool setLedBrightness(uint8_t percent);
		bool setLedColor(uint8_t red, uint8_t green, uint8_t blue);
		int32_t takeSnapshot(uint32_t id);
		int32_t takeSnapshot(uint32_t id, uint32_t count);
		int32_t objectCount;
		uint8_t getLedBrightness();
		bool getLedColor(uint8_t *red, uint8_t *green, uint8_t *blue);
		object largestObject;
	};
}
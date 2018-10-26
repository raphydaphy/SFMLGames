#pragma once
#include <SFML/Graphics.hpp>
#include "vex_types.h"

#define VEX_SIMULATOR_MODE true
#define ACTIVE Brain.Screen.update(Controller)

void pollEvents(sf::Window* window);

namespace vex
{
	// -- SUBMODULES --
	class axis
	{
	public:
		void changed(void(*callback(void)));
		int32_t value();
		int32_t position(percentUnits units);
	};

	class button
	{
	public:
		void(*pressedCallback)(void);
		void pressed(void(*callback)(void));
		void released(void(*callback(void)));
		bool pressing();
	};

	class controller
	{
	public:
		controller();
		void(*joystickButtonCallback)(vex::controller, sf::Event);
		void(*joystickAxisCallback)(vex::controller, sf::Event);
		vex::button ButtonL1;
		vex::button ButtonL2;
		vex::button ButtonR1;
		vex::button ButtonR2;
		vex::button ButtonUp;
		vex::button ButtonDown;
		vex::button ButtonLeft;
		vex::button ButtonRight;
		vex::button ButtonX;
		vex::button ButtonB;
		vex::button ButtonY;
		vex::button ButtonA;
		vex::axis Axis1;
		vex::axis Axis2;
		vex::axis Axis3;
		vex::axis Axis4;
		void rumble(const char *str);
		//vex::lcd Screen;
	};

	class lcd
	{
	private:
		sf::RenderWindow *window = nullptr;
	public:
		lcd(int x, int y, int width, int height, const char *title);
		bool update(vex::controller Controller);
		// -- VEX SIM END --

		void setCursor(int32_t row, int32_t col);
		void setFont(fontType font);
		void setPenWidth(uint32_t width);
		void setOrigin(int32_t x, int32_t y);

		void setPenColor(const color &color);
		void setPenColor(const char *color);
		void setPenColor(int hue);

		void setFillColor(const color &color);
		void setFillColor(const char *color);
		void setFillColor(int hue);

		void pressed(void(*callback(void)));
		void released(void(*callback(void)));

		void print(const char *format, ...);
		void printAt(int32_t x, int32_t y, const char *format, ...);
		void printAt(int32_t x, int32_t y, bool bOpaque, const char *format, ...);

		void clearScreen();
		void clearScreen(const color &color);
		void clearScreen(const char *color);
		void clearScreen(int hue);

		void clearLine();
		void clearLine(int number, const color &color);
		void clearLine(int number, const char *color);
		void clearLine(int number, int hue);

		void drawPixel(int x, int y);
		void drawLine(int x1, int y1, int x2, int y2);
		void drawRectangle(int x, int y, int width, int height);
		void drawRectangle(int x, int y, int width, int height, const color &color);
		void drawRectangle(int x, int y, int width, int height, const char *color);
		void drawRectangle(int x, int y, int width, int height, int hue);
		void drawCircle(int x, int y, int radius);
		void drawCircle(int x, int y, int radius, const color &color);
		void drawCircle(int x, int y, int radius, const char *color);
		void drawCircle(int x, int y, int radius, int hue);

		void render();
		void render(bool bVsyncWait, bool bRunScheduler = true);

		int32_t column();
		int32_t row();
		int32_t xPosition();
		int32_t yPosition();

		bool pressing();
		uint32_t capacity();
		double temperature();

	};

	class sdcard
	{
	public:
		int32_t loadFile(const char *name, uint8_t *buffer, int32_t len);
		int32_t saveFile(const char *name, uint8_t *buffer, int32_t len);
		int32_t appendFile(const char *name, uint8_t *buffer, int32_t len);
		bool isInserted();
	};

	// -- MAIN MODULES --
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
		brain();
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
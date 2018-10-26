#pragma once
#include <SFML/Graphics.hpp>
#include "vex_types.h"

namespace vex
{
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
		void pressed(void(*callback(void)));
		void released(void(*callback(void)));
		bool pressing();
	};
	class lcd
	{
	private:
		sf::RenderWindow *window = nullptr;
	public:
		lcd();
		bool update();
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
}

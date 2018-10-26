#include "robot_config.h"
#include <vector>
#include <algorithm>

const int PIECE_SIZE = 10;

class Pos
{
public:
	int x;
	int y;
	Pos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Pos operator+(const Pos& other)
	{
		return Pos(this->x + other.x, this->y + other.y);
	}
};

bool operator<(const Pos& a, const Pos& b)
{
	return a.x + a.y < b.x + b.y;
}

bool operator>(const Pos& a, const Pos& b)
{
	return a.x + a.y > b.x + b.y;
}

bool operator==(const Pos& a, const Pos& b)
{
	return a.x == b.x && a.y == b.y;
}

class Direction : public Pos
{
private:
	Direction(int x, int y) : Pos(x, y) { }
public:
	static Direction up()
	{
		return Direction(0, -1);
	}
	static Direction down()
	{
		return Direction(0, 1);
	}
	static Direction left()
	{
		return Direction(-1, 0);
	}
	static Direction right()
	{
		return Direction(1, 0);
	}
};

Pos food(std::rand() % 40 + 1, std::rand() % 20 + 1);

class Snake
{
public:
	Snake(int x, int y)
	{
		body.emplace_back(x, y);
	}
	bool move(Direction dir)
	{
		if (growth > 0)
		{
			std::cout << growth << std::endl;
			growth--;
		}
		else {
			std::cout << "decr" << std::endl;
			body.erase(std::prev(body.end()));
		}

		Pos head = dir + (body.front());
		if (std::find(body.begin(), body.end(), dir) == body.end())
		{
			body.insert(body.begin(), head);

			if (head == food)
			{
				food = Pos(std::rand() % 40 + 1, std::rand() % 20 + 1);
				grow(std::rand() % 5 + 3);
			}
			return true;
		}
		return false;
	}
	void grow(int amount)
	{
		growth += amount;
	}
	void render(vex::brain Brain)
	{
		bool first = true;
		for (Pos piece : body)
		{
			Brain.Screen.drawRectangle(piece.x * PIECE_SIZE, piece.y * PIECE_SIZE, PIECE_SIZE, PIECE_SIZE, first ? vex::color::orange : vex::color::yellow);
			first = false;
		}
	}
	unsigned long long int size()
	{
		return body.size();
	}
private:
	std::vector<Pos> body;
	int growth = 0;
};

std::vector<Direction> moves;

namespace ctrl
{
	void left()
	{
		moves.push_back(Direction::left());
	}

	void right()
	{
		moves.push_back(Direction::right());
	}

	void up()
	{
		moves.push_back(Direction::up());
	}

	void down()
	{
		moves.push_back(Direction::down());
	}
}

int main()
{
	#ifdef VEX_SIMULATOR_MODE

		// -- SIMULATOR INIT --
		vex::controller Controller;
		vex::brain Brain;

	#else
	#define ACTIVE true
	#endif

	Controller.ButtonLeft.pressed(ctrl::left);
	Controller.ButtonRight.pressed(ctrl::right);
	Controller.ButtonUp.pressed(ctrl::up);
	Controller.ButtonDown.pressed(ctrl::down);

	bool dead = false;

	Direction dir = Direction::right();
	Snake snake(5, 5);

	snake.grow(1000);

	while (ACTIVE)
	{
		Brain.Screen.clearScreen(vex::color::black);
		snake.render(Brain);

		if (!moves.empty())
		{
			dir = *moves.begin();
			moves.erase(moves.begin());
		}

		if (!snake.move(dir))
		{
			dead = true;
		}

		vex::task::sleep(150);
	}

	Brain.Screen.clearScreen(vex::color::red);

	Brain.Screen.drawRectangle(food.x * 10, food.y * 10, 10, 10, vex::color::blue);
	snake.render(Brain);

	Brain.Screen.printAt(10, 10, "You Died!! Score: " + snake.size());
}
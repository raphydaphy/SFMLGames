#include "robot-config.h"
#include <vector>
#include <algorithm>

const int PIECE_SIZE = 10;
const int WIDTH = 36;
const int HEIGHT = 23;

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

bool operator!=(const Pos& a, const Pos& b)
{
	return a.x != b.x || a.y != b.y;
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

Pos food(std::rand() % (WIDTH - 2) + 2, std::rand() % (HEIGHT - 2) + 2);

class Snake
{
public:
	Snake(int x, int y)
	{
		body.emplace_back(x, y);
		body.emplace_back(x - 1, y);
	}
	bool move(Direction dir)
	{
		if (growth > 0)
		{
			growth--;
		}
		else {
			body.erase(std::prev(body.end()));
		}

		Pos head = dir + (body.front());

		if (head.x < 0 || head.y < 0 || head.x > WIDTH || head.y > HEIGHT)
		{
			return false;
		}
		if (std::find(body.begin(), body.end(), head) == body.end())
		{
			body.insert(body.begin(), head);

			if (head == food)
			{
				food = Pos(std::rand() % (WIDTH - 2) + 2, std::rand() % (HEIGHT - 2) + 2);
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

Direction dir = Direction::right();
std::vector<Direction> moves;

namespace ctrl
{
	void left()
	{
		if (moves.empty() && dir == Direction::right())
			return;
		else if (!moves.empty() && moves.front() == Direction::right())
			return;
		moves.push_back(Direction::left());
	}

	void right()
	{
		if (moves.empty() && dir == Direction::left())
			return;
		else if (!moves.empty() && moves.front() == Direction::left())
			return;
		moves.push_back(Direction::right());
	}

	void up()
	{
		if (moves.empty() && dir == Direction::down())
			return;
		else if (!moves.empty() && moves.front() == Direction::down())
			return;
		moves.push_back(Direction::up());
	}

	void down()
	{
		if (moves.empty() && dir == Direction::up())
			return;
		else if (!moves.empty() && moves.front() == Direction::up())
			return;
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

	Controller.ButtonX.pressed(ctrl::left);
	Controller.ButtonB.pressed(ctrl::right);
	Controller.ButtonY.pressed(ctrl::up);
	Controller.ButtonA.pressed(ctrl::down);

	bool dead = false;
	Snake snake(5, 5);

	while (!dead)
	{
		Brain.Screen.clearScreen(vex::color::black);
		Brain.Screen.drawRectangle(food.x * 10, food.y * 10, 10, 10, vex::color::blue);
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

		vex::task::sleep(100);
		Brain.Screen.render();

		if (!ACTIVE)
		{
			dead = true;
		}
	}

	while (ACTIVE)
	{
		Brain.Screen.clearScreen(vex::color::red);

		Brain.Screen.drawRectangle(food.x * 10, food.y * 10, 10, 10, vex::color::blue);
		snake.render(Brain);

		Brain.Screen.printAt(10, 10, "You Died!! Score: " + snake.size());

		Brain.Screen.render();
	}
}
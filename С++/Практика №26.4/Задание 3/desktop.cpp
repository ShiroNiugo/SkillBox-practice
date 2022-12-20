#include <iostream>
#include <vector>

class Window
{
public:
	int startPositionX = 0, startPositionY = 0, height = 10, width = 10;
	void move(int x, int y)
	{
		if ((startPositionX + x < 50 && startPositionX + x >= 0 && height + x < 50 && height + x >= 0) && (startPositionY + y < 80 && startPositionY + y >= 0 && width + y < 80 && width + y >= 0))
		{
			startPositionX += x;
			startPositionY += y;
		}
	}
	void resize(int x, int y)
	{
		if ((x <= 50 && x > 0) && (y <= 80 && y > 0))
		{
			height = x;
			width = y;
		}
	}
};

class Desktop
{
	std::vector<std::vector<char>> virtualScreen;

public:
	void filling()
	{
		virtualScreen.resize(50, std::vector<char>(80, '0'));
	}
	void show(Window *window)
	{
		for (size_t i = 0; i < virtualScreen.size(); i++)
			for (size_t j = 0; j < virtualScreen[i].size(); j++)
				virtualScreen[i][j] = '0';
		if (window->height <= 50 && window->width <= 80 && window->startPositionX >= 0 && window->startPositionY >= 0)
			for (int i = window->startPositionX; i < window->startPositionX + window->height; i++)
				for (int j = window->startPositionY; j < window->startPositionY + window->width; j++)
					virtualScreen[i][j] = '1';
		for (auto &rows : virtualScreen)
		{
			for (auto column : rows)
				std::cout << column;
			std::cout << std::endl;
		}
	}
	std::vector<std::vector<char>> getGrid()
	{
		return virtualScreen;
	}
	std::vector<std::vector<char>> setGrid(std::vector<std::vector<char>> temp)
	{
		return virtualScreen = temp;
	}
};

void moveOrResize(Desktop *desktop, Window *window, bool move = true)
{
	int x, y;
	std::cout << (move ? "Input move (x y): " : "Input resize (height width): ");
	std::cin >> x >> y;
	desktop->filling();
	if (move)
		window->move(x, y);
	else
		window->resize(x, y);
	//std::cout << window->startPositionX << " " << window->startPositionY << " " << window->height << " " << window->width << std::endl;
	desktop->show(window);
}

int main()
{
	Desktop *desktop = new Desktop;
	Window *window = new Window;
	desktop->filling();
	desktop->show(window);
	std::string command;
	do
	{
		std::cout << "Input command: ";
		std::cin >> command;
		if (command == "move")
			moveOrResize(desktop, window);
		else if (command == "resize")
			moveOrResize(desktop, window, false);
		else if (command == "display")
			desktop->show(window);
	} while (command != "close");
	delete desktop;
	delete window;
	return 0;
}
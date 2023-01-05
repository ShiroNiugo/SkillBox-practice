#include <iostream>
#include <math.h>

class Figure
{
public:
	float coordinateX, coordinateY, square = 0;
	enum color
	{
		NONE = 0,
		RED = 1,
		BLUE = 2,
		GREEN = 4,
		PINK = 8
	};
	int colorFigure = 0;
};

class Rectangle : public Figure
{
public:
	float width, height;
	Rectangle *describing = nullptr;

	Rectangle(float inWidth, float inHeight, std::string color = "None") : width(inWidth), height(inHeight)
	{
		coordinateX = width / 2;
		coordinateY = height / 2;
		square = width * height;
		colorFigure |= (color == "None" ? NONE : PINK);
	}
};

class Circle : public Figure
{
public:
	float radius;
	Rectangle *describing = nullptr;
	Circle(float inRadius) : radius(inRadius)
	{
		square = atan(1) * 4 * radius;
		coordinateX = coordinateY = radius;
		colorFigure |= RED;
	}
};

class BoxOrTriangle : public Figure
{
public:
	float length;
	Rectangle *describing = nullptr;

	BoxOrTriangle(float inLength, std::string figure) : length(inLength)
	{
		if (figure == "square")
		{
			coordinateX = coordinateY = length / 2;
			square = length * 2;
			colorFigure |= GREEN;
		}
		else
		{
			coordinateX = length / 2;
			coordinateY = length * sqrt(3) / 6;
			square = pow(length, 2) * sqrt(3) / 4;
			colorFigure |= BLUE;
		}
	}
};

void parameters(float &a, std::string command)
{
	printf(command == "circle" ? "Input radius: " : "Input length: ");
	std::cin >> a;
}

template <typename T>
void show(T *a, std::string command, std::string parameter, bool describing = 1)
{
	std::cout << "Figure " << command << ((command == "rectangle" || command == "describing rectangle") ? ": width and height - " : (command == "circle" ? ": radius - " : ": length - ")) << parameter;
	std::cout << ", center figure - " << a->coordinateX << "x" << a->coordinateY;
	std::cout << ", square - " << a->square << ", color - " << (a->colorFigure & a->RED ? "red" : (a->colorFigure & a->BLUE ? "blue" : (a->colorFigure & a->GREEN ? "green" : (a->colorFigure & a->PINK ? "pink" : "none")))) << std::endl;
	if (describing)
		show(a->describing, "describing rectangle", std::to_string(a->describing->width) + "x" + std::to_string(a->describing->height), 0);
}

int main()
{
	std::string command;
	float parameter, parameter2;
	do
	{
		std::cout << "Input command: ";
		std::cin >> command;
		if (command == "circle")
		{
			parameters(parameter, command);
			Circle *circle = new Circle(parameter);
			circle->describing = new Rectangle(circle->radius * 2, circle->radius * 2);
			show(circle, command, std::to_string(circle->radius));
			delete circle;
		}
		else if (command == "square")
		{
			parameters(parameter, command);
			BoxOrTriangle *box = new BoxOrTriangle(parameter, command);
			box->describing = new Rectangle(box->length, box->length);
			show(box, command, std::to_string(box->length));
			delete box;
		}
		else if (command == "triangle")
		{
			parameters(parameter, command);
			BoxOrTriangle *triangle = new BoxOrTriangle(parameter, command);
			triangle->describing = new Rectangle(triangle->length, triangle->length * std::sqrt(3) / 2);
			show(triangle, command, std::to_string(triangle->length));
			delete triangle;
		}
		else if (command == "rectangle")
		{
			std::cout << "Input width and height: ";
			std::cin >> parameter >> parameter2;
			Rectangle *rectangle = new Rectangle(parameter, parameter2);
			rectangle->describing = new Rectangle(rectangle->width, rectangle->height);
			show(rectangle, command, std::to_string(rectangle->width) + "x" + std::to_string(rectangle->height));
			delete rectangle;
		}
	} while (command != "exit");
	return 0;
}
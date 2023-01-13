#include <iostream>
#include <cmath>

struct BoundingBoxDimensions
{
	double width = 0, height = 0;
	BoundingBoxDimensions(double w, double h) : width(w), height(h){};
};

class Shape
{
public:
	virtual double square() = 0;
	virtual BoundingBoxDimensions dimensions() = 0;
	virtual std::string type() = 0;
};
void printParams(Shape *shape)
{
	std::cout << "Type: " << shape->type() << std::endl;
	std::cout << "Square: " << shape->square() << std::endl;
	std::cout << "Width: " << shape->dimensions().width << std::endl;
	std::cout << "Height: " << shape->dimensions().height << std::endl << std::endl;
}

class Circle : virtual public Shape
{
	double radius;
public:
	double square() override{
		return atan(1) * 4 * radius;
	}
	BoundingBoxDimensions dimensions() override
	{
		BoundingBoxDimensions temp(radius*2,radius*2);
		return temp;
	}
	std::string type() override { return "Circle";}
	Circle(double r) : radius(r){}
};

class Rectangle : virtual public Shape
{
	BoundingBoxDimensions rectangle;
public:
	double square() override{
		return rectangle.width*rectangle.height;
	}
	BoundingBoxDimensions dimensions() override
	{
		BoundingBoxDimensions temp(rectangle.width,rectangle.height);
		return temp;
	}
	std::string type() override { return "Rectangle";}
	Rectangle(double w, double h) : rectangle(w, h){};
};

class Triangle : virtual public Shape
{
	double lengthA, lengthB, lengthC, perimeter, p;
public:
	double square() override
	{
		return sqrt(p * (p - lengthA) * (p - lengthB) * (p - lengthC));
	}
	BoundingBoxDimensions dimensions() override
	{
		double radius = lengthA * lengthB * lengthC / (4 * square());
		BoundingBoxDimensions temp(radius*2,radius*2);
		return temp;
	}
	std::string type() override { return "Triangle";}
	Triangle(double a, double b, double c) : lengthA(a), lengthB(b), lengthC(c), perimeter(a+b+c), p(perimeter/2){};
};

int main()
{
	Circle c(3);
	printParams(&c);
	Rectangle r(3, 4);
	printParams(&r);
	Triangle t(3, 4, 5);
	printParams(&t);
	return 0;
}
#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class square : public Shape
{
private:
    double side;

public:
    square(double s) : side(s) {}
    double area() override
    {
        return side * side;
    }
    double volume() override
    {
        throw logic_error("Volume not applicable for 2D shape");
    }
};

class Rectangle : public Shape
{
private:
    double length, breath;

public:
    Rectangle(double l, double b) : length(l), breath(b) {}
    double area() override
    {
        return length * breath;
    }
    double volume() override
    {
        throw logic_error("Volume not applicable for 2D shape");
    }
};

class Cube : public Shape
{
private:
    double side;

public:
    Cube(double s) : side(s) {}
    double area() override
    {
        return 6 * side * side;
    }
    double volume() override
    {
        return side * side * side;
    }
};

int main()
{
    Shape *shape1 = new square(4);
    Shape *shape2 = new Rectangle(4, 5);
    Shape *shape3 = new Cube(3);

    cout << "Area of square: " << shape1->area() << endl;
    cout << "Area of Rectangle: " << shape2->area() << endl;
    cout << "Area of Cube: " << shape3->area() << endl;
    cout << "Volume of Cube: " << shape3->volume() << endl;
    try
    {
        cout << "Volume of square: " << shape1->volume() << endl; // This will throw an exception
    }
    catch (const logic_error &e)
    {
        cout << "Error:" << e.what() << endl;
    }
}

#include <iostream>

using namespace std;

class TwoDShape
{
public:
    virtual double area() = 0;
};
class ThreeDShape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class square : public TwoDShape
{
private:
    double side;

public:
    square(double s) : side(s) {}
    double area() override
    {
        return side * side;
    }
};

class cube : public ThreeDShape
{
private:
    double side;

public:
    cube(double s) : side(s) {}
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
    TwoDShape *shape2D = new square(5);
    ThreeDShape *shape3D = new cube(8);
    cout << "The Area of Square IS" << shape2D->area() << endl;
    cout << "THE VOLUME IS " << shape3D->volume() << endl;
}
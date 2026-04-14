#include <iostream>
using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
};

class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << " I am basic burger " << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "I am standard burger" << endl;
    }
};

class Factory
{
public:
    Burger *createAlorithm(string type)
    {
        if (type == "Basic")
        {
            return new BasicBurger();
        }
        if (type == "Standard")
        {
            return new StandardBurger();
        }
        else
        {
            cout << "invalid type" << endl;
            return nullptr;
        }
    }
};

int main()
{
    string type = "Basic";
    Factory *myBurgerFactory = new Factory();

    Burger *burger = myBurgerFactory->createAlorithm(type);
    burger->prepare();
};
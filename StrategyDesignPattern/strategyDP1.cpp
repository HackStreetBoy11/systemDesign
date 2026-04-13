#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Walking
{
public:
    virtual void walk() = 0;
};
class CanWalk : public Walking
{
public:
    void walk() override
    {
        cout << "I can walk" << endl;
    }
};
class CannotWalk : public Walking
{
public:
    void walk() override
    {
        cout << "I cannot walk" << endl;
    }
};
class Talking
{
public:
    virtual void talk() = 0;
};
class CanTalk : public Talking
{
public:
    void talk() override
    {
        cout << "I can Talk" << endl;
    }
};

class CannotTalk : public Talking
{
public:
    void talk() override
    {
        cout << "I cannot Talk" << endl;
    }
};
class Person
{
protected:
    Walking *walking;
    Talking *talking;

public:
    Person(Walking *w, Talking *t)
    {
        this->walking = w;
        this->talking = t;
    }

    void Performwalk()
    {
        walking->walk();
    }
    void Performtalk()
    {
        talking->talk();
    }
};
int main()
{
    Person *obj = new Person(new CannotWalk(), new CanTalk());
    obj->Performwalk();
    obj->Performtalk();
}
#include <iostream>
using namespace std;

class Talkable
{
public:
    virtual void talk() = 0;
    virtual ~Talkable() {};
};

class NormalTalk : public Talkable
{
public:
    void talk() override
    {
        cout << " I am robot , talking normal" << endl;
    }
};
class NotTalk : public Talkable
{
public:
    void talk() override
    {
        cout << " I am robot , talking Not Normal" << endl;
    }
};

class Walkable
{
public:
    virtual void walk() = 0;
    virtual ~Walkable() {}
};

class NormalWalk : public Walkable
{
public:
    void walk() override
    {
        cout << " I am robot , walking normal" << endl;
    }
};
class NotWalk : public Walkable
{
public:
    void walk() override
    {
        cout << " I am robot , walking Not Normal" << endl;
    }
};

class Flyable
{
public:
    virtual void fly() = 0;
    virtual ~Flyable() {}
};

class NormalFly : public Flyable
{
public:
    void fly() override
    {
        cout << " I am robot , flying normal" << endl;
    }
};
class NotFLy : public Flyable
{
public:
    void fly() override
    {
        cout << " I am robot , flying Not Normal" << endl;
    }
};

class Robot
{
protected:
    Walkable *walkBehavior;
    Talkable *talkBehavior;
    Flyable *flyBehavior;

public:
    Robot(Walkable *w, Talkable *t, Flyable *f)
    {
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }

    void walk()
    {
        walkBehavior->walk();
    }
    void talk()
    {
        talkBehavior->talk();
    }
    void fly()
    {
        flyBehavior->fly();
    }

    virtual void projection() = 0; // Abstract method for subclasses
};

class CompanionRobot : public Robot
{
public:
    CompanionRobot(Walkable *w, Talkable *t, Flyable *f) : Robot(w, t, f) {}

    void projection() override
    {
        cout << "Displaying friendly companion features..." << endl;
    }
};

class WorkerRobot : public Robot
{
public:
    WorkerRobot(Walkable *w, Talkable *t, Flyable *f) : Robot(w, t, f) {}

    void projection() override
    {
        cout << "Display worker efficiency stats..." << endl;
    }
};

int main()
{
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NotFLy());
    robot1->walk();
    robot1->fly();
    robot1->talk();
    robot1->projection();
    cout << "----------------------" << endl;

    Robot *robot2 = new WorkerRobot(new NotWalk(), new NotTalk(), new NormalFly());
    robot2->walk();
    robot2->fly();
    robot2->talk();
    robot2->projection();

    return 0;
}
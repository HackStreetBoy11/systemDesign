#include <iostream>
using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};
class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Basic Burger" << endl;
    }
};
class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Standard Burger" << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Premium Burger" << endl;
    }
};
class BasicWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Basic Wheat Burger" << endl;
    }
};
class StandardWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Standard Wheat Burger" << endl;
    }
};

class PremiumWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Premium Wheat Burger" << endl;
    }
};

class Garlic
{
public:
    virtual void prepare() = 0;
    virtual ~Garlic() {}
};
class BasicGarlic : public Garlic
{
public:
    void prepare() override
    {
        cout << "Basic Garlic" << endl;
    }
};
class StandardGarlic : public Garlic
{
public:
    void prepare() override
    {
        cout << "Standard Garlic" << endl;
    }
};

class PremiumGarlic : public Garlic
{
public:
    void prepare() override
    {
        cout << "Premium Garlic" << endl;
    }
};
class BasicWheatGarlic : public Garlic
{
public:
    void prepare() override
    {
        cout << "Basic Wheat Garlic" << endl;
    }
};
class StandardWheatGarlic : public Garlic
{
public:
    void prepare() override
    {
        cout << "Standard Wheat Garlic" << endl;
    }
};

class PremiumWheatGarlic : public Garlic
{
public:
    void prepare() override
    {
        cout << "Premium Wheat Garlic" << endl;
    }
};

class Factory
{
public:
    virtual Burger *createBurger(string &type) = 0;
    virtual Garlic *createGarlic(string &type) = 0;
};

class Singh : public Factory
{
public:
    Burger *createBurger(string &type) override
    {
        if (type == "basic")
        {
            return new BasicBurger();
        }
        else if (type == "standard")
        {
            return new StandardBurger();
        }
        else if (type == "premium")
        {
            return new PremiumBurger();
        }
        else
        {
            cout << "INVALID STRING" << endl;
            return nullptr;
        }
    }
    Garlic *createGarlic(string &type)
    {
        if (type == "basic")
        {
            return new BasicGarlic();
        }
        else if (type == "standard")
        {
            return new StandardGarlic();
        }
        else if (type == "premium")
        {
            return new PremiumGarlic();
        }
        else
        {
            cout << "INVALID STRING" << endl;
            return nullptr;
        }
    }
};



class King : public Factory
{
public:
    Burger* createBurger(string &type) override
    {
        if (type == "basic")
        {
            return new BasicWheatBurger();
        }
        else if (type == "standard")
        {
            return new StandardWheatBurger();
        }
        else if (type == "premium")
        {
            return new PremiumWheatBurger();
        }
        else
        {
            cout << "INVALID STRING" << endl;
            return nullptr;
        }
    }
    Garlic *createGarlic(string &type)
    {
        if (type == "basic")
        {
            return new BasicWheatGarlic();
        }
        else if (type == "standard")
        {
            return new StandardWheatGarlic();
        }
        else if (type == "premium")
        {
            return new PremiumWheatGarlic();
        }
        else
        {
            cout << "INVALID STRING" << endl;
            return nullptr;
        }
    }
};


int main(){
    string type = "standard";
    Factory* myfactory = new King();
    Garlic* myGarlic = myfactory->createGarlic(type);
    myGarlic->prepare();
    
}
#include<iostream>
using namespace std;

// Product Class and subclass

class Burger{
    public:
    virtual void prepare()=0;
    virtual ~Burger(){}
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

class BurgerFactory{
    public:
    virtual Burger* CreateBurger(string& type)=0;
};

class SinghBurger: public BurgerFactory{
    public:
    Burger* CreateBurger(string& type)override{
        if(type=="basic")
        {
            return new BasicBurger();
        }
        else if(type=="standard"){
            return new StandardBurger();
        }
        else if(type=="premium"){
            return new PremiumBurger();
        }
        else {
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
    }
};

class KingBurger: public BurgerFactory{
    public:
    Burger* CreateBurger(string& type)
    {
        if(type=="basic")
        {
            return new BasicWheatBurger();
        }
        else if(type=="standard"){
            return new StandardWheatBurger();
        }
        else if(type=="premium"){
            return new PremiumWheatBurger();
        }
        else {
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type = "standard";
    BurgerFactory* burgerFactory = new KingBurger();
    Burger* burger = burgerFactory->CreateBurger(type);

    burger->prepare();
    return 0;  
}

#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
private:
    static Singleton *instance;
    static mutex mtx;
    Singleton()
    {
        cout << "You called Singleton class" << endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr){
            lock_guard<mutex> lock(mtx); // lock for thread safety
            if(instance==nullptr)
                instance = new Singleton(); // build a pointer instances which has the value of hte obj, recall it will give the same obj not the new one
        }
        return instance;
    }
};

Singleton *Singleton ::instance = nullptr;
mutex Singleton::mtx;

// Singleton* Singleton:: instance = new Singleton(); // egar inisilization

int main()
{
    Singleton *obj = Singleton::getInstance();
    Singleton *obj1 = Singleton::getInstance();

    cout << (obj == obj1) << endl;
}
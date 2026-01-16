#include <iostream>
#include <mutex>
using namespace std;

// class Singleton
// {
    // private:
    //     static Singleton *instance;
    //     // locking and unlocking mechanism for thread safety
    
    //     static mutex mtx;
    
    //     Singleton()
    //     {
        //         cout << "Singleton Constructor called.New Object created" << endl;
        //     }
        
        // public:
        //     static Singleton *getInstance()
        //     {
            //         if (instance == nullptr)
            //         {
                //             lock_guard<mutex> lock(mtx); // lock for thread safety
                //             if(instance==nullptr) // double-checked locking
                //             {
                    //                 instance = new Singleton();
                    //             }
                    //         }
                    //         return instance;
                    //     }
                    // };
                    
                    // Singleton *Singleton::instance = nullptr; // static variable declaration
                    // mutex Singleton::mtx;
                    // int main()
                    // {
                        //     Singleton *obj1 = Singleton::getInstance();
                        //     Singleton *obj2 = Singleton::getInstance();
                        
                        //     cout << (obj1 == obj2) << endl;
                        // }
                        


  
                        // <--- EAGER INITIALIZATION APPROACH --->
class Singleton
{
private:
    static Singleton *instance; // Eager initialization
    Singleton()
    {
        cout << "Singleton Constructor called.New Object created" << endl;
    }

public:
    static Singleton *getInstance()
    {
        return instance;
    }
};

Singleton *Singleton::instance = new Singleton();

int main()
{
    // Singleton *obj1 = Singleton::getInstance();
    // Singleton *obj2 = Singleton::getInstance();
    // cout<<(obj1 == obj2) << endl;
}
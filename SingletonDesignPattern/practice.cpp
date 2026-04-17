#include<iostream>
using namespace std;

class Singleton{
    public:
        Singleton(){
            cout<<"You called Singleton class"<<endl;
        }
};
int main(){
    Singleton* obj = new Singleton();
    Singleton* obj1 = new Singleton();

    cout<<(obj==obj1)<<endl;
}
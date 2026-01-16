#include <iostream>
using namespace std;

class MySQLDatabase
{
public:
    void saveToSQL(string data)
    {
        cout << "Saving data to MySQL Database: " << data << endl;
    }
};

class MongoDBDatabase
{
public:
    void saveToMongo(string data)
    {
        cout << "Saving data to MongoDB Database: " << data << endl;
    }
};

class UserService
{
private:
    MySQLDatabase sqlDb;
    MongoDBDatabase mongoDb;

public:
    void storeUserToSql(string user)
    {
        sqlDb.saveToSQL(user);
    }

    void storeUserToMongo(string user)
    {
        mongoDb.saveToMongo(user);
    }
};

int main()
{
    UserService service;
    service.storeUserToSql("harshit");
    service.storeUserToMongo("Varun");
}

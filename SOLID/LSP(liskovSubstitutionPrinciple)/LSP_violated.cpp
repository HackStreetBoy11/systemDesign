#include <iostream>
#include <vector>
using namespace std;

class Account
{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount() : balance(0) {};
    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited " << amount << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrew " << amount << ", New Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds for withdrawal of " << amount << ", Current Balance: " << balance << endl;
        }
    }
};

class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount() : balance(0) {};
    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited " << amount << ", New Balance: " << balance << endl;
    }
    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrew " << amount << ", New Balance: " << balance << endl;
        }
        else
        {
            cout << "Overdraft limit exceeded for withdrawal of " << amount << ", Current Balance: " << balance << endl;
        }
    }
};

class FixedTermAccount : public Account
{
private:
    double balance;

public:
    FixedTermAccount() : balance(0) {};

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited " << amount << ", New Balance: " << balance << endl;
    }
    void withdraw(double amount) override
    {
        throw logic_error("Withdrawals are not allowed from Fixed term accounts.");
    }
};

class BankClient
{
    private:
        vector<Account *> accounts;
    public:
        BankClient(vector<Account*> accounts){
            this->accounts = accounts;
        }
        void processTransactions(){
            for(Account* acc: accounts){
                acc->deposit(1000);
                try{
                    acc->withdraw(500);
                }catch(const logic_error&e){
                    cout<<"Exception:"<<e.what()<<endl;
                }
            }
        }
};


int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient client(accounts);
    client.processTransactions();

    // Clean up
    for(Account* acc: accounts){
        delete acc;
    }

    return 0;
}
#include <iostream>
using namespace std;

// Invariant : Balance cannot be negative
class BankAccount
{
protected:
    double balance;

public:
    BankAccount(double b)
    {
        if (b < 0)
            throw invalid_argument("Balance can't be negative");
        balance = b;
    }
    virtual void withdraw(double amount)
    {
        if (balance - amount < 0)
            throw runtime_error("Inufficient funds");
        balance += amount;
        cout << "Withdrew " << amount << ", New Balance: " << balance << endl;
    }
};

// Brakes invariant : should not be allowed
class CheatAccount : public BankAccount
{
public:
    CheatAccount(double b) : BankAccount(b) {}

    void withdraw(double amount) override
    {
        balance -= amount; // can go negative
        cout << "Withdrew " << amount << ", New Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount *bankAccount = new CheatAccount(100);
    bankAccount->withdraw(200);
}
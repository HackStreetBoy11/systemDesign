#include <iostream>
using namespace std;

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

    // History constraint: Withdraw should be allowed
    virtual void withdraw(double amount)
    {
        if (balance - amount < 0)
            throw runtime_error("Insufficient funds");
        balance -= amount;
        cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
public:
    FixedDepositAccount(double b) : BankAccount(b) {}

    // LSP break! History constraint broke!
    //  Parent class behavior change:Now withdraw is not allowed
    // This class will brake client code that relies on withdraw
    void withdraw(double amount) override
    {
        throw runtime_error("Withdrawals not allowed on Fixed Deposit Account");
    }
};

int main()
{
    BankAccount *bankAccount = new FixedDepositAccount(1000);
    bankAccount->withdraw(100);
}
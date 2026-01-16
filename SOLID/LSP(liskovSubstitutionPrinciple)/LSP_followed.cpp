#include <iostream>
#include <vector>
#include <typeinfo>
#include <stdexcept>
using namespace std;

class DepositOnlyAccount
{
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount
{
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount
{
private:
    double balance;

public:
    SavingAccount() : balance(0) {};
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited " << amount << ", New Balance: " << balance << endl;
    }
    void withdraw(double amount)
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

class CurrentAccount : public WithdrawableAccount
{
private:
    double balance;

public:
    CurrentAccount() : balance(0) {};
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited " << amount << ", New Balance: " << balance << endl;
    }
    void withdraw(double amount)
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

class FixedTermAccount : public DepositOnlyAccount
{
private:
    double balance;

public:
    FixedTermAccount() : balance(0) {};
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited " << amount << ", New Balance: " << balance << endl;
    }
};

class BankClient
{
private:
    vector<WithdrawableAccount *> withdrawableAccounts;
    vector<DepositOnlyAccount *> depositOnlyAccounts;

public:
    BankClient(vector<WithdrawableAccount *> withdrawableAccounts,
               vector<DepositOnlyAccount *> depositOnlyAccounts)
    {
        this->withdrawableAccounts = withdrawableAccounts;
        this->depositOnlyAccounts = depositOnlyAccounts;
    }
    void processTransactions()
    {
        for (WithdrawableAccount *acc : withdrawableAccounts)
        {
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for (DepositOnlyAccount *acc : depositOnlyAccounts)
        {
            acc->deposit(2000);
        }
    }
};

int main()
{
    vector<WithdrawableAccount *> WithdrawableAccounts;
    WithdrawableAccounts.push_back(new SavingAccount());
    WithdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount *> DepositOnlyAccounts;
    DepositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient client(WithdrawableAccounts, DepositOnlyAccounts);
    client.processTransactions();
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() : accountNumber("12345"), accountHolderName("garv"), balance(1000.0) {}

    void deposit(double amount)
    {
        balance += amount;
        cout << "Account credited with: " << amount << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Account debited with: " << amount << endl;
        }
    }

    void displayAccountBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }

    friend bool validate(BankAccount &b, string accNum);
};

bool validate(BankAccount &b, string accNum)
{
    if (b.accountNumber == accNum)
    {
        cout << "Welcome, " << b.accountHolderName << "!" << endl;
        return true;
    }
    cout << "Invalid Account Number!" << endl;
    return false;
}

int menulist()
{
    int choice;
    cout << "MENULIST:" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Display Balance" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter Choice: ";
    cin >> choice;
    return choice;
}

int main()
{
    BankAccount b;
    string accountNumber;
    int choice = -1;
    double amount;

    cout << "Enter Your Account Number: ";
    cin >> accountNumber;

    if (validate(b, accountNumber))
    {
        while (choice != 0)
        {
            choice = menulist();
            switch (choice)
            {
            case 1:
                cout << "Enter Amount To Deposit: ";
                cin >> amount;
                b.deposit(amount);
                break;
            case 2:
                cout << "Enter Amount To Withdraw: ";
                cin >> amount;
                b.withdraw(amount);
                break;
            case 3:
                b.displayAccountBalance();
                break;
            case 0:
                cout << "Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
        }
    }
    return 0;
}

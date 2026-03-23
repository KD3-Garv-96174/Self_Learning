#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accountNumber, string accountHolderName, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        if (amount < 0)
        {
            throw amount; 
        }
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount)
    {
        if (amount < 0)
        {
            throw amount; 
        }
        if (amount > balance)
        {
            throw string("Insufficient balance"); 
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    }

    void displayBalance()
    {
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    int accNo;
    string name;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accNo;
    cout << "Enter account holder name: ";
    cin >> name;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(accNo, name, initialBalance);

    int choice;
    double amount;

    do
    {
        cout << "\n1. Deposit\n2. Withdraw\n3. Display Balance\n4. Exit\nEnter choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdraw amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.displayBalance();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
            }
        }
        catch (double amt)
        {
            cout << "Exception: Negative amount entered (" << amt << ")" << endl;
        }
        catch (string &msg)
        {
            cout << "Exception: " << msg << endl;
        }

    } while (choice != 4);

    return 0;
}

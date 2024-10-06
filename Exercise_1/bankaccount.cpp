// Your First C++ Program

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    // Private class attributes to be accessed within the class functions.
    private:
        string accountHolderName;
        int accountNumber;
        double balance;
        
    public:
        // Constructor for the BankAccount class. 
        BankAccount(string accountHolderName, int accountNumber, double balance) {
            this->accountHolderName = accountHolderName;
            this->accountNumber = accountNumber;
            this->balance = balance;
        }
        // Void function to display the account name, number, and balance.
        void displayAccountInfo() {
            cout << "Account Holder: "; cout << accountHolderName << endl;
            cout << "Account Number: "; cout << accountNumber << endl;
            cout << "Account Balance: $"; cout << balance << endl; 
            cout << "--------------------------" << endl;
        }
        // Deposit function.
        void deposit(int x){
            cout << "After depositing $" << x << endl;
            this->balance = balance + x;
        }
        // Withdraw function with validation.
        void withdraw(int x){
            if (balance - x < 0){
                cout << "Insufficient balance!\n";
                cout << "After attempting to withdraw $" << x << endl;
            } else {
                cout << "After withdrawing $" << x << endl;
                this->balance = balance - x;
            }
            
        }
};


int main() {
    // Creating a bank account
    BankAccount myAccount("John Doe", 123456, 500.00);
    // Display initial account information
    myAccount.displayAccountInfo();
    // Deposit money
    myAccount.deposit(150.00);
    myAccount.displayAccountInfo();
    // Withdraw money
    myAccount.withdraw(100.00);
    myAccount.displayAccountInfo();
    // Attempt to withrdaw more than the balance.
    myAccount.withdraw(600.00);
    myAccount.displayAccountInfo();
    return 0; 
}
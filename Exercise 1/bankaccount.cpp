// Your First C++ Program

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    private:
        string accountHolderName;
        int accountNumber;
        double balance;
        
    public:
        BankAccount(string accountHolderName, int accountNumber, double balance) {
            this->accountHolderName = accountHolderName;
            this->accountNumber = accountNumber;
            this->balance = balance;
        };
        void displayAccountInfo() {
            cout << "Account Holder: "; cout << accountHolderName << endl;
            cout << "Account Number: "; cout << accountNumber << endl;
            cout << "Account Balance: $"; cout << balance << endl; 
            cout << "--------------------------" << endl;
        };
        int deposit(int x){
            this->balance = balance + x;
            return balance;
        }
        int withdraw(int x){
            this->balance = balance - x;
            return balance; 
        }
};


int main() {
    // Creating a bank account
    BankAccount myAccount("John Doe", 123456, 500.00);
    // Display initial account information
    myAccount.displayAccountInfo();
    // Deposit money
    myAccount.deposit(150.00);
    cout << "After depositing $150:" << endl; myAccount.displayAccountInfo();
    // Withdraw money
    myAccount.withdraw(100.00);
    cout << "After withdrawing $100:" << endl; myAccount.displayAccountInfo();
    return 0; 
}
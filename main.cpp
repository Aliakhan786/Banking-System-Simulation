#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class to store customer information
class Customer {
private:
    string name;
    string address;
    long long phone;

public:
    Customer() {
        name = "Unknown";
        address = "Not Provided";
        phone = 0;
    }

    Customer(string n, string addr, long long ph) {
        name = n;
        address = addr;
        phone = ph;
    }

    void inputDetails() {
        cout << "Enter Customer Name: ";
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Phone Number: ";
        cin >> phone;
        cin.ignore(); // to flush the newline from input buffer
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
    }
};

// Class to represent a bank account
class Account {
private:
    int accountNumber;
    Customer customer;
    double balance;
    vector<string> transactionHistory;

public:
    Account() {
        accountNumber = 0;
        balance = 0.0;
    }

    Account(int accNo, Customer cust, double bal) {
        accountNumber = accNo;
        customer = cust;
        balance = bal;
        transactionHistory.push_back("Account created with ₹" + to_string(bal));
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }
        balance += amount;
        transactionHistory.push_back("Deposited ₹" + to_string(amount));
        cout << "Deposited Successfully.\n";
    }

    void withdraw(double amount) {
        if (amount > balance || amount <= 0) {
            cout << "Invalid or insufficient amount.\n";
            return;
        }
        balance -= amount;
        transactionHistory.push_back("Withdrawn ₹" + to_string(amount));
        cout << "Withdrawn Successfully.\n";
    }

    void checkBalance() {
        cout << "Current Balance: ₹" << balance << endl;
    }

    void displayAccountInfo() {
        cout << "\n--- Account Information ---\n";
        cout << "Account Number: " << accountNumber << endl;
        customer.displayDetails();
        cout << "Balance: ₹" << balance << endl;
    }

    void showTransactionHistory() {
        cout << "\n--- Transaction History ---\n";
        for (const string &entry : transactionHistory) {
            cout << "- " << entry << endl;
        }
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

// Main function: Menu-driven banking system
int main() {
    vector<Account> accounts;
    bool running = true;
    int choice;

    while (running) {
        cout << "\n======== BANKING SYSTEM MENU ========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Info\n";
        cout << "6. Show Transaction History\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Customer cust;
            cust.inputDetails();
            int accNo;
            double initBalance;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Initial Deposit Amount: ";
            cin >> initBalance;
            cin.ignore();
            Account newAcc(accNo, cust, initBalance);
            accounts.push_back(newAcc);
            cout << "Account created successfully!\n";
        } 
        else if (choice >= 2 && choice <= 6) {
            int accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cin.ignore();
            bool found = false;

            for (Account &acc : accounts) {
                if (acc.getAccountNumber() == accNo) {
                    found = true;

                    if (choice == 2) {
                        double amt;
                        cout << "Enter amount to deposit: ";
                        cin >> amt;
                        acc.deposit(amt);
                    } 
                    else if (choice == 3) {
                        double amt;
                        cout << "Enter amount to withdraw: ";
                        cin >> amt;
                        acc.withdraw(amt);
                    } 
                    else if (choice == 4) {
                        acc.checkBalance();
                    } 
                    else if (choice == 5) {
                        acc.displayAccountInfo();
                    } 
                    else if (choice == 6) {
                        acc.showTransactionHistory();
                    }
                    break;
                }
            }

            if (!found) {
                cout << "Account not found!\n";
            }
        } 
        else if (choice == 7) {
            running = false;
            cout << "Thank you for using the Banking System. Goodbye!\n";
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

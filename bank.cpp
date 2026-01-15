// #include <iostream>
// #include <vector>
// #include <stdexcept>
// using namespace std;

// class Account {
// private:
//     int accountNumber;
//     string holderName;
//     double balance;

// public:
//     Account(int accNo, string name, double bal) {
//         if (bal < 0)
//             throw invalid_argument("Initial balance cannot be negative");
//         accountNumber = accNo;
//         holderName = name;
//         balance = bal;
//     }

//     int getAccountNumber() const {
//         return accountNumber;
//     }

//     string getHolderName() const {
//         return holderName;
//     }

//     double getBalance() const {
//         return balance;
//     }

//     void deposit(double amount) {
//         if (amount <= 0)
//             throw invalid_argument("Invalid deposit amount");
//         balance += amount;
//         cout << "Amount deposited successfully!\n";
//     }

//     void withdraw(double amount) {
//         if (amount <= 0)
//             throw invalid_argument("Invalid withdrawal amount");
//         if (amount > balance)
//             throw runtime_error("Insufficient balance");
//         balance -= amount;
//         cout << "Amount withdrawn successfully!\n";
//     }

//     void display() const {
//         cout << "\nAccount Number : " << accountNumber;
//         cout << "\nHolder Name    : " << holderName;
//         cout << "\nBalance        : " << balance << endl;
//     }
// };

// /* ---------------- BANK CLASS ---------------- */
// class Bank {
// private:
//     vector<Account> accounts;

//     Account* findAccount(int accNo) {
//         for (auto &acc : accounts) {
//             if (acc.getAccountNumber() == accNo)
//                 return &acc;
//         }
//         return nullptr;
//     }

// public:
//     void createAccount() {
//         int accNo;
//         string name;
//         double bal;

//         cout << "Enter Account Number: ";
//         cin >> accNo;
//         cout << "Enter Holder Name: ";
//         cin.ignore();
//         getline(cin, name);
//         cout << "Enter Initial Balance: ";
//         cin >> bal;

//         accounts.push_back(Account(accNo, name, bal));
//         cout << "Account created successfully!\n";
//     }

//     void depositMoney() {
//         int accNo;
//         double amt;
//         cout << "Enter Account Number: ";
//         cin >> accNo;

//         Account* acc = findAccount(accNo);
//         if (!acc)
//             throw runtime_error("Account not found");

//         cout << "Enter amount to deposit: ";
//         cin >> amt;
//         acc->deposit(amt);
//     }

//     void withdrawMoney() {
//         int accNo;
//         double amt;
//         cout << "Enter Account Number: ";
//         cin >> accNo;

//         Account* acc = findAccount(accNo);
//         if (!acc)
//             throw runtime_error("Account not found");

//         cout << "Enter amount to withdraw: ";
//         cin >> amt;
//         acc->withdraw(amt);
//     }

//     void transferMoney() {
//         int fromAcc, toAcc;
//         double amt;

//         cout << "Enter Sender Account Number: ";
//         cin >> fromAcc;
//         cout << "Enter Receiver Account Number: ";
//         cin >> toAcc;

//         Account* sender = findAccount(fromAcc);
//         Account* receiver = findAccount(toAcc);

//         if (!sender || !receiver)
//             throw runtime_error("One or both accounts not found");

//         cout << "Enter amount to transfer: ";
//         cin >> amt;

//         sender->withdraw(amt);
//         receiver->deposit(amt);
//         cout << "Transfer successful!\n";
//     }

//     void displayAccount() {
//         int accNo;
//         cout << "Enter Account Number: ";
//         cin >> accNo;

//         Account* acc = findAccount(accNo);
//         if (!acc)
//             throw runtime_error("Account not found");

//         acc->display();
//     }
// };

// /* ---------------- MAIN FUNCTION ---------------- */
// int main() {
//     Bank bank;
//     int choice;

//     while (true) {
//         cout << "\n===== BANKING SYSTEM MENU =====\n";
//         cout << "1. Create Account\n";
//         cout << "2. Deposit Money\n";
//         cout << "3. Withdraw Money\n";
//         cout << "4. Transfer Money\n";
//         cout << "5. Display Account Details\n";
//         cout << "6. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         try {
//             switch (choice) {
//                 case 1: bank.createAccount(); break;
//                 case 2: bank.depositMoney(); break;
//                 case 3: bank.withdrawMoney(); break;
//                 case 4: bank.transferMoney(); break;
//                 case 5: bank.displayAccount(); break;
//                 case 6: 
//                     cout << "Thank you for using the banking system!\n";
//                     return 0;
//                 default:
//                     cout << "Invalid choice!\n";
//             }
//         }
//         catch (exception &e) {
//             cout << "Error: " << e.what() << endl;
//         }
//     }
// }
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

/* ACCOUNT CLASS */
class Account {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int accNo, string name, double bal) {
        if (bal < 0)
            throw invalid_argument("Balance cannot be negative");
        accountNumber = accNo;
        holderName = name;
        balance = bal;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    string getHolderName() const {
        return holderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount <= 0)
            throw invalid_argument("Invalid deposit amount");
        balance += amount;
        cout << "Amount of "<<amount<<" credited successfully to your account no "<<accountNumber<<"\n";
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw invalid_argument("Invalid withdrawal amount");
        if (amount > balance)
            throw runtime_error("Insufficient balance");
        balance -= amount;
        cout << "Amount of "<<amount<<" debited successfully to your account no "<<accountNumber<<"\n";
    }

    void display() const {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nHolder Name    : " << holderName;
        cout << "\nBalance        : " << balance << endl;
    }
};

/* BANK CLASS */
class Bank {
private:
    vector<Account> accounts;

    Account* findAccount(int accNo) {
        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNo)
                return &acc;
        }
        return nullptr;
    }

public:
    void createAccount() {
        int accNo;
        string name;
        double bal;

        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Holder Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> bal;

        accounts.push_back(Account(accNo, name, bal));
        cout << "Account created successfully!\n";
    }

    void depositMoney() {
        int accNo;
        double amt;
        cout << "Enter Account Number: ";
        cin >> accNo;

        Account* acc = findAccount(accNo);
        if (!acc)
            throw runtime_error("Account not found");

        cout << "Enter amount to deposit: ";
        cin >> amt;
        acc->deposit(amt);
    }

    void withdrawMoney() {
        int accNo;
        double amt;
        cout << "Enter Account Number: ";
        cin >> accNo;

        Account* acc = findAccount(accNo);
        if (!acc)
            throw runtime_error("Account not found");

        cout << "Enter amount to withdraw: ";
        cin >> amt;
        acc->withdraw(amt);
    }

    void transferMoney() {
        int fromAcc, toAcc;
        double amt;

        cout << "Enter Sender Account Number: ";
        cin >> fromAcc;
        cout << "Enter Receiver Account Number: ";
        cin >> toAcc;

        Account* sender = findAccount(fromAcc);
        Account* receiver = findAccount(toAcc);

        if (!sender || !receiver)
            throw runtime_error("One or both accounts not found");

        cout << "Enter amount to transfer: ";
        cin >> amt;

        sender->withdraw(amt);
        receiver->deposit(amt);
        cout << "Transfer successful!\n";
    }

    void displayAccount() {
        int accNo;
        cout << "Enter Account Number: ";
        cin >> accNo;

        Account* acc = findAccount(accNo);
        if (!acc)
            throw runtime_error("Account not found");

        acc->display();
    }
};

int main() {
    Bank bank;
    int choice;

    while (true) {
        cout << "\n___BANKING SYSTEM MENU___\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Money\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice(1to 6): ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: bank.createAccount(); break;
                case 2: bank.depositMoney(); break;
                case 3: bank.withdrawMoney(); break;
                case 4: bank.transferMoney(); break;
                case 5: bank.displayAccount(); break;
                case 6: 
                    cout << "Thank you for using the banking system!\n";
                    return 0;
                default:
                    cout << "Invalid choice!\n";
            }
        }
        catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

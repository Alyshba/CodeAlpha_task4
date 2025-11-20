#include <iostream>
#include <fstream>
using namespace std;

class Account {
public:
    string name;
    int accno;
    float balance;

    Account(string n, int acc, float bal) {
        name = n;
        accno = acc;
        balance = bal;
    }

    void deposit(float amount) {
        balance += amount;
        saveTransaction("Deposit", amount);
        cout << "Deposit successful.\n";
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            saveTransaction("Withdraw", amount);
            cout << "Withdrawal successful.\n";
        }
    }

    void transfer(Account &receiver, float amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            receiver.balance += amount;

            saveTransaction("Transfer to " + receiver.name, amount);
            receiver.saveTransaction("Received from " + name, amount);

            cout << "Transfer successful!\n";
        }
    }

    void saveTransaction(string type, float amount) {
        ofstream file("transactions.txt", ios::app);
        file << name << " | " << type << " | " << amount << endl;
    }

    void showDetails() {
        cout << "\n--- Account Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accno << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Account acc1("Alishba", 1001, 5000);
    Account acc2("Aiman", 1002, 3000);

    int choice;
    float amount;

    cout << "\n--- Banking System ---\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Transfer\n";
    cout << "4. Show Account Details\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter amount: ";
        cin >> amount;
        acc1.deposit(amount);
    }
    else if (choice == 2) {
        cout << "Enter amount: ";
        cin >> amount;
        acc1.withdraw(amount);
    }
    else if (choice == 3) {
        cout << "Enter amount: ";
        cin >> amount;
        acc1.transfer(acc2, amount);
    }
    else if (choice == 4) {
        acc1.showDetails();
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}

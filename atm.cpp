#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class BankAccount {
private:
  long int account_num;
  string name;
  int pin;
  double balance;
  string phone_num;

public:
  // Class methods
  long int getAccountNum();
  string getName();
  int getPin();
  double getBalance();
  string getPhoneNum();

  // Constructor
  BankAccount(string name_in = "none", int pin_in = 1111,
              double balance_in = 0.0, string phone_in = "");

  // Destructor
  // ~BankAccount() { cout << "destructor called\n"; }
};

long int createAccountNum() {
  srand(time(0));
  return (rand() % 1000000) + 1000000;
}

void showMenu() {
  cout << "**** Chase ATM ****\n";
  cout << "Select Options:\n";
  cout << "1. Create new bank account\n";
  cout << "2. Check balance\n";
  cout << "3. Cash withdraw\n";
  cout << "4. Show account details\n";
  cout << "5. Update mobile number\n";
  cout << "6. Exit\n\n";
  cout << "Enter you choice:\n";
}

BankAccount::BankAccount(string name_in, int pin_in, double balance_in,
                         string phone_in)
    : name{name_in}, pin{pin_in}, balance{balance_in}, phone_num{phone_in} {
  account_num = createAccountNum();
  cout << "Your Account Number is: " << account_num << '\n';
}

void createAccount() {
  string name_in;
  int pin_in;
  double funds;
  string phone_in;
  cout << "Enter name\n";
  cin >> name_in;
  cout << "Enter four digit personal identification number (PIN)\n";
  cin >> pin_in;
  cout << "Deposit funds\n";
  cin >> funds;
  cout << "Enter your phone number\n";
  cin >> phone_in;
  BankAccount(name_in, pin_in, funds, phone_in);
}

long int BankAccount::getAccountNum() { return account_num; }

string BankAccount::getName() { return name; }

int BankAccount::getPin() { return pin; }

double BankAccount::getBalance() { return balance; }

string BankAccount::getPhoneNum() { return phone_num; }

int main() {
  bool on = true;
  int choice = 0;
  vector<BankAccount> accounts{};

  // BankAccount my_acc{"roml", 5678, 1700, "5624378380"};
  // cout << my_acc.getAccountNum() << '\n';

  while (on) {
    showMenu();
    cin >> choice;

    switch (choice) {
    case 1:
      createAccount();
      break;
    case 2:
      cout << "**** Account Balance ****\n";
      // cout << "Account Number: " << my_acc.getAccountNum() << '\n';
      // cout << "Name: " << my_acc.getName() << '\n';
      // cout << "Balance: " << my_acc.getBalance() << '\n';
      break;
    case 3:
      cout << "You picked 2\n";
      break;
    case 4:
      cout << "**** Account Details ****\n";
      // cout << "Account Number: " << my_acc.getAccountNum() << '\n';
      // cout << "Name: " << my_acc.getName() << '\n';
      // cout << "Balance: " << my_acc.getBalance() << '\n';
      // cout << "PIN: " << my_acc.getPin() << '\n';
      // cout << "Phone Number: " << my_acc.getPhoneNum() << '\n';
      break;
    case 5:
      cout << "You picked 4\n";
      break;
    case 6:
      cout << "Thank you for banking with Chase" << '\n';
      on = false;
      exit(0);
    default:
      cout << "Please enter a valid option\n" << '\n';
    }
    cout << '\n';
  }

  return 0;
}
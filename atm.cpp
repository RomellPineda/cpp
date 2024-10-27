#include <iostream>

using namespace std;

class BankAccount {
private:
  // long int account_num;
  string name;
  int pin;
  double balance;
  string phone_num;

public:
  // Constructors
  BankAccount(string name_in = "none", int pin_in = 1111, double balance_in = 0.0, string phone_in = "");
  // Destructor
  ~BankAccount() { cout << "destructor called for " << name << endl; }
};

BankAccount::BankAccount(string name_in, int pin_in, double balance_in, string phone_in)
    : name{name_in}, pin{pin_in}, balance{balance_in}, phone_num{phone_in} {}

void showMenu() {
  cout << "**** Chase ATM ****\n";
  cout << "Select Options:\n";
  cout << "1. Check balance\n";
  cout << "2. Cash withdraw\n";
  cout << "3. Show user details\n";
  cout << "4. Update mobile number\n";
  cout << "5. Exit\n\n";
  cout << "Enter you choice:\n";
}

int main() {
  bool on = true;
  int choice = 0;

  while (on) {
    showMenu();
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "You picked 1" << endl;
      break;
    case 2:
      cout << "You picked 2" << endl;
      break;
    case 3:
      cout << "You picked 3" << endl;
      break;
    case 4:
      cout << "You picked 4" << endl;
      break;
    case 5:
      cout << "Thank you for banking with Chase" << endl;
      on = false;
      exit(0);
    default:
      cout << "Please enter a valid option\n" << endl;
    }
  }

  return 0;
}
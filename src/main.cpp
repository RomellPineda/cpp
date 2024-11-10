#include <iostream>
#include "BankAccount.h"

using std::cin;
using std::cout;
using std::string;

BankAccount createAccount()
{
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
  cout << "Enter your phone number (without spaces)\n";
  cin >> phone_in;
  return BankAccount(name_in, pin_in, funds, phone_in);
}

void displayAdditionalDetails(BankAccount b)
{
  cout << "PIN: " << b.getPin() << '\n';
  cout << "Phone Number: " << b.getPhoneNum() << '\n';
}

void displayDetails(BankAccount b)
{
  cout << "Account Number: " << b.getAccountNum() << '\n';
  cout << "Name: " << b.getName() << '\n';
  cout << "Balance: " << b.getBalance() << '\n';
}

bool validateAccount(BankAccount b)
{
  long int account_in;
  int max_attempts{3};
  int pin_in;

  for (int i{0}; i < max_attempts; i++)
  {
    cout << "Enter your Account Number\n";
    cin >> account_in;
    cout << "Enter your PIN\n";
    cin >> pin_in;
    if (account_in == b.getAccountNum() && pin_in == b.getPin())
    {
      return true;
    }
    else if (i < 2)
    {
      cout << "Account Number or PIN incorrect. Please try again\n";
    }
    else
    {
      cout << "Unable to validate account\n";
    }
  }
  return false;
}

void showMenu()
{
  cout << "**** Chase ATM ****\n";
  cout << "Select Options:\n";
  cout << "1. Create new bank account\n";
  cout << "2. Check balance\n";
  cout << "3. Withdraw\n";
  cout << "4. Deposit funds\n";
  cout << "5. Show account details\n";
  cout << "6. Exit\n\n";
  cout << "Enter you choice:\n";
}

int main()
{
  bool on = true;
  bool validated = false;
  int choice = 0;
  BankAccount current;

  while (on)
  {
    showMenu();
    cin >> choice;

    switch (choice)
    {
    case 1:
      current = createAccount();
      cout << "Your Account Number is: " << current.getAccountNum() << '\n';
      break;
    case 2:
      cout << "**** Account Balance ****\n";
      displayDetails(current);
      break;
    case 3:
      validated = validateAccount(current);
      if (validated)
      {
        current.withdraw();
      }
      break;
    case 4:
      validated = validateAccount(current);
      if (validated)
      {
        current.deposit();
      }
      break;
    case 5:
      cout << "**** Account Details ****\n";
      displayDetails(current);
      displayAdditionalDetails(current);
      break;
    case 6:
      cout << "Thank you for banking with Chase" << '\n';
      on = false;
      exit(0);
    default:
      cout << "Please enter a valid option\n"
           << '\n';
    }
    cout << '\n';
  }

  return 0;
}
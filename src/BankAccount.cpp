#include "BankAccount.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cin;
using std::cout;
using std::string;

long int createAccountNum()
{
  srand(time(0));
  return (rand() % 1000000) + 1000000;
}

BankAccount::BankAccount(string name_in, int pin_in, double balance_in,
                         string phone_in)
    : name{name_in}, pin{pin_in}, balance{balance_in}, phone_num{phone_in}
{
  account_num = createAccountNum();
}

long int BankAccount::getAccountNum() { return account_num; }

string BankAccount::getName() { return name; }

int BankAccount::getPin() { return pin; }

double BankAccount::getBalance() { return balance; }

string BankAccount::getPhoneNum() { return phone_num; }

void BankAccount::setBalance(double new_balance) { balance = new_balance; }

void BankAccount::withdraw()
{
  double current_balance = BankAccount::getBalance();
  double withdraw_amount;

  cout << "Enter amount you wish to withdraw\n";
  cin >> withdraw_amount;
  if (withdraw_amount <= current_balance)
  {
    BankAccount::setBalance(current_balance - withdraw_amount);
    cout << "Please collect your cash\n";
  }
  else
  {
    cout << "Unable to complete transaction. Please check Account Balance\n";
  }
}
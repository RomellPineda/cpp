#ifndef _BankAccount_H_
#define _BankAccount_H_
#include <string>

using std::string;

class BankAccount
{
private:
  long int account_num;
  string name;
  int pin;
  double balance;
  string phone_num;

public:
  // Class methods
  void deposit();
  void withdraw();
  long int getAccountNum();
  string getName();
  int getPin();
  double getBalance();
  string getPhoneNum();
  void setBalance(double new_balance);

  // Constructor
  BankAccount(string name_in = "none", int pin_in = 1111,
              double balance_in = 0.0,
              string phone_in = "no phone number on record");
};

#endif
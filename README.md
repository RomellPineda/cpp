## ATM Banking Application

Bank Application implemented in C++. Features include:
- Account creation
- Check balance
- Withdraw cash
- Deposit funds
- Display account details

## Running

Release version is runnable as a single file from most C++ compilers such as [programiz.com](https://www.programiz.com/cpp-programming/online-compiler/)

Mac Terminal commands can be used to compile and run locally
```
// Navigate to project folder
// Compile
g++ -std=c++11 main.cpp BankAccount.cpp -o atm.out
// Run
./atm.out
```

## Note

Initial run will create BankAccount object with default values. Select 5 from the options menu to obtain account number and utilize default PIN to play with other features or create a new account by selecting option 1.

## Exiting

Enter 6 to exit application.

#include <iostream>

class BankAccount {
private:
    // This member is private and cannot be accessed from outside the class.
    double balance;

public:
    // Constructor to initialize the balance.
    BankAccount(double initial_balance) : balance(initial_balance) {}

    // DECLARATION of the friend function.
    // It is declared inside the class with the 'friend' keyword.
    friend void printBalance(const BankAccount& account);
};

// DEFINITION of the friend function.
// It is defined outside the class, without 'friend' or 'BankAccount::'.
void printBalance(const BankAccount& account) {
    // Because it's a friend, this function can access the private 'balance' member.
    std::cout << "The account balance is: $" << account.balance << std::endl;
}

int main() {
    // Create an instance of the class.
    BankAccount my_account(1500.75);

    // Call the friend function to display the private data.
    // Note that we are not calling it like a member function (e.g., my_account.printBalance()).
    printBalance(my_account);

    return 0;
}

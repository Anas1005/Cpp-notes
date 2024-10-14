/*
 * ============================================
 *            NAMESPACES IN C++
 * ============================================
 *
 * This code provides a comprehensive understanding of 
 * namespaces in C++. It includes definitions, concepts, 
 * and practical examples to demonstrate how namespaces 
 * can be effectively used in C++ programming.
 * 
 * 1. **What is a Namespace?**
 *    - A namespace is a declarative region that provides 
 *      a scope to the identifiers (variables, functions, 
 *      classes, etc.) inside it. Namespaces help organize 
 *      code and avoid naming conflicts.
 * 
 * 2. **Defining a Namespace:**
 *    - You can define a namespace using the `namespace` keyword, 
 *      followed by the name of the namespace. The contents 
 *      of the namespace are enclosed in curly braces.
 * 
 * 3. **Using Directive:**
 *    - The `using` directive allows you to use names from a 
 *      namespace without qualifying them with the namespace name. 
 *      For example: `using namespace Bank;`.
 * 
 * 4. **Nested Namespaces:**
 *    - Namespaces can be nested within each other. This is useful 
 *      for organizing code hierarchically. For example, you might 
 *      have `Bank::Accounts::Savings`.
 * 
 * 5. **Static Member Functions:**
 *    - Static member functions belong to the class rather than 
 *      to any specific object instance. They can be accessed 
 *      without creating an instance of the class. This is ideal 
 *      for utility functions, such as transaction processing.
 * 
 * 6. **Real-world Applications:**
 *    - Namespaces are widely used in large applications to separate 
 *      different modules or components (e.g., Banking, E-commerce, 
 *      etc.), which helps facilitate code maintenance and collaboration.
 * 
 * 7. **Accessing Namespaces:**
 *    - You can access a member of a namespace using the scope resolution 
 *      operator `::`. For example: `Bank::Accounts::openAccount()`.
 * 
 * Example Application:
 * - The example below demonstrates a banking application where 
 *   we define a `Bank` namespace containing nested namespaces for 
 *   `Accounts` and `Transactions`. The `Transaction` class will 
 *   include a static member function to process transactions 
 *   without needing an instance of `Transaction`.
 * 
 * ============================================
 */

#include <iostream>
#include <string>

namespace Bank {
    // Nested namespace for account-related functionality
    namespace Accounts {
        class Account {
        public:
            Account(const std::string& owner, double balance)
                : owner(owner), balance(balance) {}

            void display() const {
                std::cout << "Account Owner: " << owner 
                          << ", Balance: " << balance << std::endl;
            }

            void deposit(double amount) {
                balance += amount;
                std::cout << "Deposited: " << amount 
                          << ". New Balance: " << balance << std::endl;
            }
        private:
            std::string owner;
            double balance;
            
        };
        

        void openAccount(const std::string& owner, double initialDeposit) {
            Account newAccount(owner, initialDeposit);
            std::cout << "Opening account for " << owner << " with initial deposit of " 
                      << initialDeposit << std::endl;
            newAccount.display();
        }
    }

    // Nested namespace for transaction-related functionality
    namespace Transactions {
        class Transaction {
        public:
            // Static function to process transactions without needing an instance
            static void processTransaction(const std::string& transactionId, double amount, Accounts::Account& account) {
                account.deposit(amount);
                std::cout << "Processed Transaction ID: " << transactionId << " for amount: " << amount << std::endl;
            }
        };
    }
}

int main() {
    // Using the Bank namespace
    using namespace Bank; // Using directive for convenience

    // Creating an account
    Accounts::openAccount("Alice", 1000.0);
    
    // Creating an account object
    Accounts::Account account1("Alice", 1000.0);
    
    // Processing a transaction
    Transactions::Transaction::processTransaction("T001", 500.0, account1); // Deposit

    return 0;
}

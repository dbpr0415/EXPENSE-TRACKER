#include <iostream>
#include <vector>
#include <iomanip>

// Structure to represent an expense
struct Expense {
    std::string description;
    double amount;
};

// Function to add an expense to the list
void addExpense(std::vector<Expense>& expenses) {
    Expense newExpense;

    std::cout << "Enter expense description: ";
    std::cin.ignore(); // Ignore any newline characters in the input buffer
    std::getline(std::cin, newExpense.description);

    std::cout << "Enter expense amount: ";
    std::cin >> newExpense.amount;

    expenses.push_back(newExpense);

    std::cout << "Expense added successfully!\n\n";
}

// Function to display all expenses and calculate the total
void viewExpenses(const std::vector<Expense>& expenses) {
    if (expenses.empty()) {
        std::cout << "No expenses to display.\n\n";
        return;
    }

    double total = 0.0;

    std::cout << std::setw(20) << std::left << "Description" << std::setw(10) << "Amount" << std::setw(10) << "Index" << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    for (size_t i = 0; i < expenses.size(); ++i) {
        const auto& expense = expenses[i];
        std::cout << std::setw(20) << std::left << expense.description << std::setw(10) << std::fixed << std::setprecision(2) << expense.amount << std::setw(10) << i << std::endl;
        total += expense.amount;
    }

    std::cout << std::string(50, '-') << std::endl;
    std::cout << std::setw(20) << std::left << "Total" << std::setw(10) << std::fixed << std::setprecision(2) << total << std::endl << std::endl;
}

// Function to calculate and return the total expenses
double calculateTotal(const std::vector<Expense>& expenses) {
    double total = 0.0;

    for (const auto& expense : expenses) {
        total += expense.amount;
    }

    return total;
}

// Function to delete an expense based on its index
void deleteExpense(std::vector<Expense>& expenses, size_t index) {
    if (index < expenses.size()) {
        expenses.erase(expenses.begin() + index);
        std::cout << "Expense deleted successfully!\n\n";
    } else {
        std::cout << "Invalid index. No expense deleted.\n\n";
    }
}

// Function to edit an expense based on its index
void editExpense(std::vector<Expense>& expenses, size_t index) {
    if (index < expenses.size()) {
        Expense& expenseToEdit = expenses[index];

        std::cout << "Editing Expense at Index " << index << ":\n";
        std::cout << "Current Description: " << expenseToEdit.description << "\n";
        std::cout << "Enter new description: ";
        std::cin.ignore();
        std::getline(std::cin, expenseToEdit.description);

        std::cout << "Current Amount: " << expenseToEdit.amount << "\n";
        std::cout << "Enter new amount: ";
        std::cin >> expenseToEdit.amount;

        std::cout << "Expense edited successfully!\n\n";
    } else {
        std::cout << "Invalid index. No expense edited.\n\n";
    }
}

int main() {
    std::vector<Expense> expenses;

    while (true) {
        std::cout << "Expense Tracker Menu:\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. View Expenses\n";
        std::cout << "3. Calculate Total Expenses\n";
        std::cout << "4. Delete Expense\n";
        std::cout << "5. Edit Expense\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                viewExpenses(expenses);
                break;
            case 3:
                {
                    double totalExpenses = calculateTotal(expenses);
                    std::cout << "Total Expenses: " << std::fixed << std::setprecision(2) << totalExpenses << std::endl << std::endl;
                }
                break;
            case 4:
                {
                    size_t index;
                    std::cout << "Enter the index of the expense to delete: ";
                    std::cin >> index;
                    deleteExpense(expenses, index);
                }
                break;
            case 5:
                {
                    size_t index;
                    std::cout << "Enter the index of the expense to edit: ";
                    std::cin >> index;
                    editExpense(expenses, index);
                }
                break;
            case 6:
                std::cout << "Exiting the Expense Tracker. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n\n";
        }
    }

    return 0;
}

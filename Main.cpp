#include "employee.h"
#include <iostream>
#include <limits>

void printMenu() {
    std::cout << "==============================\n";
    std::cout << "           Main Menu          \n";
    std::cout << "==============================\n";
    std::cout << "1. Add Employee\n";
    std::cout << "2. Edit Employee\n";
    std::cout << "3. Delete Employee\n";
    std::cout << "4. Search by Last Name\n";
    std::cout << "5. Display by Age and Last Name\n";
    std::cout << "6. Save and Exit\n";
    std::cout << "==============================\n";
}

int main() {
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    std::string filename = "employees.txt";

    loadEmployeesFromFile(employees, employeeCount, filename);

    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";

        while (!(std::cin >> choice) || choice < 1 || choice > 6) {
            std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            addEmployee(employees, employeeCount);
            break;
        case 2:
            editEmployee(employees, employeeCount);
            break;
        case 3:
            deleteEmployee(employees, employeeCount);
            break;
        case 4:
            searchByLastName(employees, employeeCount);
            break;
        case 5:
            displayByAgeAndLastName(employees, employeeCount);
            break;
        case 6:
            saveEmployeesToFile(employees, employeeCount, filename);
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
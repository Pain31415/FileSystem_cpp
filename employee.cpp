#include "employee.h"
#include <iostream>
#include <fstream>

void Employee::printInfo() const {
    std::cout << "Name: " << firstName << " " << lastName << ", Age: " << age << std::endl;
}

void addEmployee(Employee* employees, int& count) {
    Employee newEmployee;
    std::cout << "Enter first name: ";
    std::cin >> newEmployee.firstName;
    std::cout << "Enter last name: ";
    std::cin >> newEmployee.lastName;
    std::cout << "Enter age: ";
    std::cin >> newEmployee.age;

    employees[count++] = newEmployee;
}

void printEmployeesByAge(const Employee* employees, int count, int targetAge) {
    for (int i = 0; i < count; ++i) {
        if (employees[i].age == targetAge) {
            employees[i].printInfo();
        }
    }
}

void printEmployeesByLastName(const Employee* employees, int count, char targetLetter) {
    for (int i = 0; i < count; ++i) {
        if (!employees[i].lastName.empty() && employees[i].lastName.front() == targetLetter) {
            employees[i].printInfo();
        }
    }
}

void saveEmployeesToFile(const Employee* employees, int count, const std::string& filename) {
    std::ofstream outputFile(filename);

    for (int i = 0; i < count; ++i) {
        outputFile << employees[i].firstName << " " << employees[i].lastName << " " << employees[i].age << std::endl;
    }

    outputFile.close();
}

void loadEmployeesFromFile(Employee* employees, int& count, const std::string& filename) {
    std::ifstream inputFile(filename);

    Employee employee;
    while (inputFile >> employee.firstName >> employee.lastName >> employee.age) {
        employees[count++] = employee;
    }

    inputFile.close();
}
void editEmployee(Employee* employees, int count) {
    std::string lastNameToEdit;
    std::cout << "Enter the last name of the employee you want to edit: ";
    std::cin >> lastNameToEdit;

    for (int i = 0; i < count; ++i) {
        if (employees[i].lastName == lastNameToEdit) {
            std::cout << "Enter new first name: ";
            std::cin >> employees[i].firstName;
            std::cout << "Enter new last name: ";
            std::cin >> employees[i].lastName;
            std::cout << "Enter new age: ";
            std::cin >> employees[i].age;

            std::cout << "Employee information updated successfully.\n";
            return;
        }
    }

    std::cout << "Employee with last name " << lastNameToEdit << " not found.\n";
}

void deleteEmployee(Employee* employees, int& count) {
    std::string lastNameToDelete;
    std::cout << "Enter the last name of the employee you want to delete: ";
    std::cin >> lastNameToDelete;

    for (int i = 0; i < count; ++i) {
        if (employees[i].lastName == lastNameToDelete) {
            // Move the last employee in the array to the position of the one to be deleted
            employees[i] = employees[count - 1];
            --count;

            std::cout << "Employee with last name " << lastNameToDelete << " deleted successfully.\n";
            return;
        }
    }

    std::cout << "Employee with last name " << lastNameToDelete << " not found.\n";
}

void searchByLastName(const Employee* employees, int count) {
    std::string targetLastName;
    std::cout << "Enter the last name to search for: ";
    std::cin >> targetLastName;

    for (int i = 0; i < count; ++i) {
        if (employees[i].lastName == targetLastName) {
            employees[i].printInfo();
        }
    }
}

void displayByAgeAndLastName(const Employee* employees, int count) {
    int targetAge;
    std::cout << "Enter the target age: ";
    std::cin >> targetAge;

    char targetLetter;
    std::cout << "Enter the target letter for last name: ";
    std::cin >> targetLetter;

    for (int i = 0; i < count; ++i) {
        if (employees[i].age == targetAge && employees[i].lastName.front() == targetLetter) {
            employees[i].printInfo();
        }
    }
}
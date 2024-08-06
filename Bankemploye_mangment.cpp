#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Employee {
    string name;
    int id;
    string position;
};

void addEmployee(ofstream &file) {
    Employee emp;
    cout << "Enter employee name: ";
    getline(cin >> ws, emp.name);  // Read entire line including spaces
    cout << "Enter employee ID: ";
    cin >> emp.id;
    cout << "Enter employee position: ";
    getline(cin >> ws, emp.position);  // Read entire line including spaces

    // Write employee data to file
    file << emp.name << "," << emp.id << "," << emp.position << endl;
    cout << "Employee added successfully." << endl;
}

void showEmployees(ifstream &file) {
    Employee emp;
    string line;

    cout << "\nEmployee List:\n";
    cout << "Name\tID\tPosition\n";
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, emp.name, ',');
        ss >> emp.id;
        getline(ss >> ws, emp.position, ',');

        cout << emp.name << "\t" << emp.id << "\t" << emp.position << endl;
    }
}

int main() {
    ofstream outFile("employees.txt", ios::app);  // Append mode
    ifstream inFile("employees.txt");

    if (!outFile.is_open() || !inFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int choice;
    do {
        cout << "\nBank Employee Management System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Show Employees" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();  // Ignore any leftover newline characters

        switch (choice) {
            case 1:
                addEmployee(outFile);
                break;
            case 2:
                showEmployees(inFile);
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter again." << endl;
                break;
        }
    } while (choice != 3);

    outFile.close();
    inFile.close();

    return 0;
}

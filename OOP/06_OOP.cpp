#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Structure to store personal records
struct Person {
    string name;
    string dob;  // Date of Birth
    string phone;

    // Constructor
    Person(string n, string d, string p) : name(n), dob(d), phone(p) {}

    // Overloading < operator to sort by name
    bool operator<(const Person& other) const {
        return name < other.name;
    }
};

// Function to display personal records
void display(const vector<Person>& records) {
    cout << "Name\t\tDOB\t\tPhone" << endl;
    cout << "-------------------------------------------" << endl;
    for (const auto& person : records) {
        cout << person.name << "\t" << person.dob << "\t" << person.phone << endl;
    }
    cout << endl;
}

// Function to search for a person by name
void searchByName(const vector<Person>& records, const string& searchName) {
    // Use find_if to search for the person by name
    auto it = find_if(records.begin(), records.end(), [&searchName](const Person& person) {
        return person.name == searchName;
    });

    if (it != records.end()) {
        cout << "Record found:\n";
        cout << "Name: " << it->name << "\nDOB: " << it->dob << "\nPhone: " << it->phone << endl;
    } else {
        cout << "Record not found for the name: " << searchName << endl;
    }
}

int main() {
    vector<Person> records;

    // Adding some personal records to the vector
    records.push_back(Person("Manthan Kshirsagar", "15-04-2002", "9876543210"));
    records.push_back(Person("Anmol Karande", "23-07-1999", "9876543211"));
    records.push_back(Person("Shraddha Kapoor", "03-03-1987", "9876543213"));
    records.push_back(Person("Chris Evans", "13-06-1981", "9876543212"));

    // Display unsorted records
    cout << "Unsorted Records:\n";
    display(records);

    // Sort the records alphabetically by name
    sort(records.begin(), records.end());

    // Display sorted records
    cout << "Sorted Records:\n";
    display(records);

    // Search for a person by name
    string searchName;
    cout << "Enter the name to search: ";
    getline(cin, searchName);
    
    searchByName(records, searchName);

    return 0;
}

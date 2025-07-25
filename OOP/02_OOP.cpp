#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string *name;
    int rollNo;
    string Class;
    char division;
    string dob; // Date of Birth
    string bloodGroup;
    string contactAddress;
    long long telephone;
    string drivingLicense;

    static int studentCount; // Static member to keep track of number of students

public:
    // Default constructor
    Student() {
        name = new string("Unknown");
        rollNo = 0;
        Class = "None";
        division = '-';
        dob = "None";
        bloodGroup = "None";
        contactAddress = "None";
        telephone = 0;
        drivingLicense = "None";
        studentCount++;
    }

    // Parameterized constructor
    Student(string name, int rollNo, string Class, char division, string dob, string bloodGroup, string contactAddress, long long telephone, string drivingLicense) {
        this->name = new string(name);
        this->rollNo = rollNo;
        this->Class = Class;
        this->division = division;
        this->dob = dob;
        this->bloodGroup = bloodGroup;
        this->contactAddress = contactAddress;
        this->telephone = telephone;
        this->drivingLicense = drivingLicense;
        studentCount++;
    }

    // Copy constructor
    Student(const Student &s) {
        name = new string(*(s.name));
        rollNo = s.rollNo;
        Class = s.Class;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        telephone = s.telephone;
        drivingLicense = s.drivingLicense;
        studentCount++;
    }

    // Destructor
    ~Student() {
        delete name;  // Free dynamically allocated memory
        studentCount--;
    }

    // Friend class declaration
    friend class Database;

    // Static function to get student count
    static int getStudentCount() {
        return studentCount;
    }

    // Inline function to display basic info
    inline void displayBasicInfo() const {
        cout << "Name: " << *name << ", Roll No: " << rollNo << ", Class: " << Class << ", Division: " << division << endl;
    }

    // Exception handling in setting telephone number
    void setTelephone(long long tel) {
        try {
            if (to_string(tel).length() != 10)
                throw "Invalid telephone number!";
            this->telephone = tel;
        } catch (const char* msg) {
            cerr << "Error: " << msg << endl;
        }
    }
};

// Initialize static member
int Student::studentCount = 0;

// Friend class
class Database {
public:
    void displayCompleteInfo(const Student &s) {
        cout << "\n--- Student's Complete Information ---\n";
        cout << "Name: " << *(s.name) << "\nRoll No: " << s.rollNo
             << "\nClass: " << s.Class << "\nDivision: " << s.division
             << "\nDate of Birth: " << s.dob << "\nBlood Group: " << s.bloodGroup
             << "\nContact Address: " << s.contactAddress << "\nTelephone: " << s.telephone
             << "\nDriving License No: " << s.drivingLicense << endl;
    }
};

int main() {
    Student manthan("Manthan Kshirsagar", 58, "Second Year", 'A', "12/06/2004", "B+", "Pimpri Saudagar, Pune", 9876543210, "DL001122");

    Student anmol("Anmol Karande", 52, "Second Year", 'A', "15/08/2003", "O+", "Badlapur, Bihar", 9988776655, "DL334455");

    // Display basic information
    manthan.displayBasicInfo();
    anmol.displayBasicInfo();

    // Using friend class to display complete information
    Database db;
    db.displayCompleteInfo(manthan);
    db.displayCompleteInfo(anmol);

    // Static function to get student count
    cout << "\nTotal number of students: " << Student::getStudentCount() << endl;

    return 0;
}

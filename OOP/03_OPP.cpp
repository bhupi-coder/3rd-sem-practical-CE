#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Base class for publication
class Publication {
protected:
    string title;
    float price;

public:
    // Default constructor
    Publication() : title(""), price(0.0f) {}

    // Parameterized constructor
    Publication(string t, float p) : title(t), price(p) {}

    // Method to get data
    void getData() {
        cout << "Enter title: ";
        cin.ignore(); // Ignore leftover newline
        getline(cin, title);
        
        cout << "Enter price: ";
        cin >> price;

        if (price < 0) {
            throw runtime_error("Invalid price!");
        }
    }

    // Method to display data
    void displayData() const {
        cout << "Title: " << title << "\nPrice: " << price << endl;
    }
};

// Derived class for books
class Book : public Publication {
private:
    int pageCount;

public:
    // Default constructor
    Book() : Publication(), pageCount(0) {}

    // Method to get book data
    void getData() {
        try {
            Publication::getData();  // Get common data
            cout << "Enter page count: ";
            cin >> pageCount;

            if (pageCount < 0) {
                throw runtime_error("Invalid page count!");
            }
        } catch (runtime_error &e) {
            cout << "Exception: " << e.what() << endl;
            resetData();  // Reset data to zero values
        }
    }

    // Method to display book data
    void displayData() const {
        Publication::displayData();  // Display common data
        cout << "Page Count: " << pageCount << endl;
    }

    // Reset all data to zero values
    void resetData() {
        title = "";
        price = 0.0f;
        pageCount = 0;
    }
};

// Derived class for tapes
class Tape : public Publication {
private:
    float playTime;

public:
    // Default constructor
    Tape() : Publication(), playTime(0.0f) {}

    // Method to get tape data
    void getData() {
        try {
            Publication::getData();  // Get common data
            cout << "Enter playing time (in minutes): ";
            cin >> playTime;

            if (playTime < 0) {
                throw runtime_error("Invalid playing time!");
            }
        } catch (runtime_error &e) {
            cout << "Exception: " << e.what() << endl;
            resetData();  // Reset data to zero values
        }
    }

    // Method to display tape data
    void displayData() const {
        Publication::displayData();  // Display common data
        cout << "Playing Time: " << playTime << " minutes" << endl;
    }

    // Reset all data to zero values
    void resetData() {
        title = "";
        price = 0.0f;
        playTime = 0.0f;
    }
};

int main() {
    Book b;
    Tape t;

    // Get and display book details
    cout << "\nEnter details for the book:\n";
    b.getData();

    cout << "\nDetails of the book:\n";
    b.displayData();

    // Get and display tape details
    cout << "\nEnter details for the tape:\n";
    t.getData();

    cout << "\nDetails of the tape:\n";
    t.displayData();

    return 0;
}

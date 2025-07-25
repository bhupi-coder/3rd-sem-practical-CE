#include <iostream>
#include <fstream>  // For file handling
#include <string>

using namespace std;

int main() {
    // File name
    string filename = "example.txt";
    
    // 1. Create an output file and write information to it
    ofstream outfile(filename);
    
    if (!outfile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }
    
    // Write information to the file
    outfile << "This is an example of file handling in C++." << endl;
    outfile << "We are writing this to a file and then reading it." << endl;

    // Close the output file
    outfile.close();
    cout << "Data has been written to the file: " << filename << endl;

    // 2. Open the same file as input and read the information
    ifstream infile(filename);
    
    if (!infile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    // Read the information from the file and print it to the console
    string line;
    cout << "\nReading from the file: " << endl;
    while (getline(infile, line)) {
        cout << line << endl;
    }

    // Close the input file
    infile.close();

    return 0;
}

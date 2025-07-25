/*Experiment No.32 : Pizza parlor accepting maximum M orders.Orders are served in first come first served basis.Order once placed can not be cancelled.Write C++ program to simulate the system using circular queue using array.
*/


#include <iostream>
#include <cstdlib>
using namespace std;

class PizzaParlor {
    int front, rear, q[5];
    const int MAX = 5;

public:
    PizzaParlor() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to add an order
    void addOrder() {
        if (isFull()) {
            cout << "\nOrders are full.\n";
            return;
        }

        int pizzaID;
        cout << "\nEnter the Pizza ID: ";
        cin >> pizzaID;

        if (isEmpty()) { // First order
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        q[rear] = pizzaID;

        cout << "Order added successfully.\n";
    }

    // Function to serve an order
    void serveOrder() {
        if (isEmpty()) {
            cout << "\nNo orders to serve.\n";
            return;
        }

        cout << "\nOrder served is: " << q[front] << endl;

        if (front == rear) { // Only one order left
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Function to display the orders
    void displayOrders() {
        if (isEmpty()) {
            cout << "\nNo orders to display.\n";
            return;
        }

        cout << "\nCurrent Orders: ";
        int i = front;
        while (i != rear) {
            cout << q[i] << " <- ";
            i = (i + 1) % MAX;
        }
        cout << q[rear] << endl;
    }

    // Menu to interact with the system
    void menu() {
        int choice;
        do {
            cout << "\n\n*** PIZZA PARLOR ***\n";
            cout << "1. Add a Pizza Order\n";
            cout << "2. Display Orders\n";
            cout << "3. Serve a Pizza Order\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addOrder();
                    break;
                case 2:
                    displayOrders();
                    break;
                case 3:
                    serveOrder();
                    break;
                case 4:
                    cout << "Exiting...\n";
                    exit(0);
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (true);
    }
};

int main() {

    /*Student Details*/
    cout << "\n------------------------------------------------------" << endl;
    cout << "Name: Bhupen Jitendra Chirmade" << endl;
    cout << "Class: SE Computer (A)" << endl;
    cout << "Roll Number: 22" << endl;
    cout << "------------------------------------------------------\n";
    
    PizzaParlor p1;
    p1.menu();
    return 0;
}

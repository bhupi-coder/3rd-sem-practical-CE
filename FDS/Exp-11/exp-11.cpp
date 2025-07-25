/*
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. 
                    If the operating system does not use priorities, then the jobs are processed in the order they enter the system.
                    Write C++ program for simulating job queue. Write functions to add job and delete job from queue.
*/



#include <iostream>
#define MAX 10
using namespace std;

struct QueueStruct
{
    int data[MAX];
    int front, rear;
};

class Queue
{
    QueueStruct q;

public:
    Queue()
    {
        q.front = q.rear = -1;
    }

    bool isempty();
    bool isfull();
    void enqueue(int);
    int delqueue();
    void display();
};

// Function to check if the queue is empty
bool Queue::isempty()
{
    return (q.front == q.rear);
}

// Function to check if the queue is full
bool Queue::isfull()
{
    return (q.rear == MAX - 1);
}

// Function to add a job to the queue
void Queue::enqueue(int x)
{
    if (isfull())
    {
        cout << "Queue is full! Cannot add more jobs.\n";
    }
    else
    {
        q.data[++q.rear] = x;
        cout << "Job " << x << " added to the queue.\n";
    }
}

// Function to delete a job from the queue
int Queue::delqueue()
{
    if (isempty())
    {
        cout << "Queue is empty! No job to delete.\n";
        return -1;
    }
    else
    {
        int removedJob = q.data[++q.front];
        return removedJob;
    }
}

// Function to display all jobs in the queue
void Queue::display()
{
    if (isempty())
    {
        cout << "Queue is empty! No jobs to display.\n";
        return;
    }

    cout << "\nJobs in the Queue:\n";
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        cout << "Job " << q.data[i] << " ";
    }
    cout << endl;
}

int main()
{

    // Student Details
    cout << "\n------------------------------------------------------\n";
    cout << "Name: Bhupen Jitendra Chirmade\n";
    cout << "Class: SE Computer (A)\n";
    cout << "Roll Number: 22\n";
    cout << "------------------------------------------------------\n";

    Queue jobQueue;
    int choice, jobNumber;

    // Menu-driven program to manage job queue
    do
    {
        cout << "\n========= Job Queue Menu =========";
        cout << "\n1. Insert Job\n2. Delete Job\n3. Display Jobs\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Job Number to Insert: ";
            cin >> jobNumber;
            jobQueue.enqueue(jobNumber);
            break;

        case 2:
            if (!jobQueue.isempty())
            {
                cout << "\nDeleted Job = " << jobQueue.delqueue() << endl;
                jobQueue.display();
            }
            else
            {
                cout << "Queue is underflow! No jobs to delete.\n";
            }
            break;

        case 3:
            jobQueue.display();
            break;

        case 4:
            cout << "\nExiting Program... Thank you!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

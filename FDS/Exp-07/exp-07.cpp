/*
Experiment No. 19 :
Department of Computer Engineering has a student's club named 'Pinnacle Club'.
Students of Second, Third, and Final year of department can be granted membership on request.
Similarly, one may cancel the membership of the club.
The first node is reserved for the president of the club and the last node for the secretary.
Write a C++ program to maintain club member‘s information using a singly linked list.
Store student PRN and Name.

Write functions to:
a) Add and delete members as well as the president or even the secretary.
b) Compute the total number of members of the club.
c) Display members.
d) Display list in reverse order using recursion.
e) Concatenate two linked lists for two divisions.
*/

#include <iostream>
#include <string>
using namespace std;

class list;

class node
{
    int prn;
    string name;
    node *next;

public:
    node(int x, string nm)
    {
        prn = x;
        next = NULL;
        name = nm;
    }
    friend class list;
};

class list
{
    node *start;

public:
    list()
    {
        start = NULL;
    }

    void create();
    void display();
    void insertAtBeginning();
    void insertAtEnd();
    void insertAfter();
    void deleteAtFirst();
    void deleteByValue();
    void deleteAtEnd();
    int computeTotal();
    void sortList();
    void concatList(list &q1);
    void displayRev(node *t);

    bool reverseDisplay()
    {
        if (start == NULL)
            return false;
        displayRev(start);
        return true;
    }
};

void list::displayRev(node *t)
{
    if (t == NULL)
        return;
    displayRev(t->next);
    cout << "\nPRN NO: " << t->prn << " Name: " << t->name;
}

void list::create()
{
    int no;
    string nam;
    if (start == NULL)
    {
        cout << "Enter PRN number: ";
        cin >> no;
        cout << "Enter name: ";
        cin >> nam;
        start = new node(no, nam);
        cout << "\n=============== List Created ===============";
    }
    else
    {
        cout << "\nList is already created.";
    }
}

void list::display()
{
    node *t = start;
    if (start == NULL)
    {
        cout << "\nList is Empty";
    }
    else
    {
        cout << "\n=============== List: ===============\n";
        while (t != NULL)
        {
            cout << t->prn << " " << t->name << " \n";
            t = t->next;
        }
    }
}

void list::insertAtBeginning()
{
    int no;
    string nam;
    if (start == NULL)
    {
        create();
    }
    else
    {
        cout << "\nEnter PRN Number: ";
        cin >> no;
        cout << "Enter Name: ";
        cin >> nam;
        node *temp = new node(no, nam);
        temp->next = start;
        start = temp;
        cout << "Inserted " << temp->name << " at the beginning.";
    }
}

void list::insertAtEnd()
{
    int no;
    string nam;
    if (start == NULL)
    {
        create();
    }
    else
    {
        cout << "\nEnter PRN Number: ";
        cin >> no;
        cout << "Enter Name: ";
        cin >> nam;
        node *t = start;
        while (t->next != NULL)
        {
            t = t->next;
        }
        node *p = new node(no, nam);
        t->next = p;
    }
}

void list::insertAfter()
{
    int prev_no;
    cout << "\nEnter PRN No. after which you want to insert: ";
    cin >> prev_no;
    node *t = start;
    string nam;
    int flag = 0, no;

    while (t != NULL)
    {
        if (t->prn == prev_no)
        {
            flag = 1;
            break;
        }
        t = t->next;
    }

    if (flag == 1)
    {
        cout << "\nEnter PRN Number: ";
        cin >> no;
        cout << "Enter Name: ";
        cin >> nam;
        node *p = new node(no, nam);
        p->next = t->next;
        t->next = p;
    }
    else
    {
        cout << "\n"
             << prev_no << " is not in the list.";
    }
}

void list::deleteAtFirst()
{
    if (start == NULL)
    {
        cout << "\nClub is Empty..";
    }
    else
    {
        node *t = start;
        start = start->next;
        delete t;
        cout << "\nPresident deleted..";
    }
}

void list::deleteByValue()
{
    int no, flag = 0;
    cout << "\nEnter PRN No. of member to be deleted: ";
    cin >> no;

    node *t = start;
    node *prev = NULL;

    while (t != NULL)
    {
        if (t->prn == no)
        {
            flag = 1;
            break;
        }
        prev = t;
        t = t->next;
    }

    if (flag == 1)
    {
        prev->next = t->next;
        delete t;
        cout << "\nMember with PRN No: " << no << " is deleted.";
    }
    else
    {
        cout << "\nMember not found in List.";
    }
}

void list::deleteAtEnd()
{
    if (start == NULL)
    {
        cout << "\nClub is Empty..";
    }
    else
    {
        node *t = start;
        node *prev = NULL;

        while (t->next != NULL)
        {
            prev = t;
            t = t->next;
        }

        prev->next = NULL;
        delete t;
        cout << "\nSecretary Deleted.";
    }
}

int list::computeTotal()
{
    int count = 0;
    node *t = start;

    while (t != NULL)
    {
        count++;
        t = t->next;
    }

    return count;
}

void list::sortList()
{
    node *i;
    node *j;
    for (i = start; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->prn > j->prn)
            {
                swap(i->prn, j->prn);
                swap(i->name, j->name);
            }
        }
    }
    cout << "\n List is sorted.";
    display();
}

void list::concatList(list &q1)
{
    node *t = q1.start;
    if (t == NULL)
    {
        cout << "\nList 2 is empty";
        return;
    }

    node *p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = t;
    q1.start = NULL;
    cout << "\nAfter concatenation list: \n";
    display();
}

int main()
{
    /*Student Details*/
    cout << "\n------------------------------------------------------" << endl;
    cout << "Name: Bhupen Jitendra Chirmade" << endl;
    cout << "Class: SE Computer (A)" << endl;
    cout << "Roll Number: 22" << endl;
    cout << "------------------------------------------------------\n";

    list l1, l2;
    list *l;
    int choice, selectList;

    while (true)
    {
        cout << "\nSelect List\n1.List 1\n2.List 2\nEnter choice: ";
        cin >> selectList;
        l = (selectList == 1) ? &l1 : &l2;

        do
        {
            cout << "\n1. Create\n2. Insert President\n3. Insert Secretary\n4. Insert After Position(Member)\n";
            cout << "5. Display List\n6. Delete President\n7. Delete Secretary\n8. Delete Member\n";
            cout << "9. Find Total No. of Members\n10. Sort List\n11. Reselect List\n";
            cout << "12. Combine Lists\n13. Reverse Display\n0. Exit\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                l->create();
                break;
            case 2:
                l->insertAtBeginning();
                break;
            case 3:
                l->insertAtEnd();
                break;
            case 4:
                l->insertAfter();
                break;
            case 5:
                l->display();
                break;
            case 6:
                l->deleteAtFirst();
                break;
            case 7:
                l->deleteAtEnd();
                break;
            case 8:
                l->deleteByValue();
                break;
            case 9:
                cout << "\nTotal members (including President & Secretary): " << l->computeTotal();
                break;
            case 10:
                l->sortList();
                break;
            case 11:
                break; // Continue with list selection loop
            case 12:
                l1.concatList(l2);
                break;
            case 13:
                l->reverseDisplay();
                break;
            case 0:
                cout << "\n=============== GOOD BYE ===============\n";
                return 0;
            default:
                cout << "Wrong choice";
                break;
            }
        } while (choice != 11);
    }
}

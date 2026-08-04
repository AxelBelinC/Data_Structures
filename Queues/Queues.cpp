/* | 02/05/2026 || 02/05/2026 |
Axel Armando Belin Castorena - 355651
Intelligent Computing Engineering 2°A - UAA
Program objective: Through a menu, allow the modification and creation of queues.
*/

#include <iostream>
#include <stdlib.h>
#include <limits>

using namespace std;

struct node{
    int data;
    node *link;
} *head = nullptr, *tail = nullptr;

void Enqueue (int x);
void Dequeue ();
void ShowQueue();
void ClearQueue();

int main (){
    int option, x;
    cout << "====================================QUEUE=============================" << endl;
    do{
        ShowQueue();
        cout << endl << "========================MENU=========================" << endl;
        cout << "[1]. Enqueue" << endl;
        cout << "[2]. Dequeue" << endl;
        cout << "[3]. Show Queue" << endl;
        cout << "[4]. Clear Queue" << endl;
        cout << "[0]. Exit" << endl;
        cout << "=====================================================" << endl;
        cout << "Select an option: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls || clear");

        switch(option){
            case 1: 
                cout << "Enter the data to enqueue: " << endl;
                cin >> x;
                Enqueue(x);
            break;
            case 2: Dequeue(); break;
            case 3: ShowQueue(); break;
            case 4: ClearQueue(); break;
            default: 
                cout << "Please enter a valid option." << endl;
            break;
        }
        if (option != 0){
            cout << endl << "Please enter any key to return to the menu.";
            cin.get();
        }
        system ("cls || clear");
    } while (option != 0);

    return 0;
}

void Enqueue(int x){
    node *temp = new node();
    temp->data = x;
    temp->link = nullptr;
    if (head == nullptr){
        head = temp;
        tail = temp;
    } else {
        tail->link = temp;
        tail = temp;
    }
    cout << "Element: '" << tail->data << "' enqueue correctly." << endl;
}

void Dequeue(){
    if (head == nullptr){
        cout << "The queue is empty, first enqueue some elements." << endl;
        return;
    }
    node *temp = head;
    head = head->link;
    if (head == nullptr){
        tail = nullptr;
    }
    cout << "Element: '" << temp->data << "' dequeue correctly." << endl;
    delete temp;
}

void ShowQueue(){
    if (head == nullptr){
        cout << endl << "---EMPTY QUEUE---" << endl;
        return;
    }
    cout << "\tQUEUE:" << endl;
    node *temp = head;
    while (temp != nullptr){
        cout << "[" << temp->data << "] -> ";
        temp = temp->link;
    }
    cout << endl;
}

void ClearQueue(){
    if (head == nullptr){
        cout << "Nothing to delete, the queue is empty." << endl;
        return;
    }
    node *temp = nullptr;
    while (head != nullptr){
        temp = head;
        head = head->link;
        delete temp;
    }
    tail = nullptr;
    cout << "Queue cleared succesfully" << endl;
}
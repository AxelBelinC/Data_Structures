/*
| 29/04/2026 || 01/05/2026 |
Axel Armando Belin Castorena - 355651
Intelligent Computing Engineering 2°A - UAA
Program objective: Through a menu, allow the modification and creation of stacks with the possibility of use characters.
*/

#include <iostream>
#include <string>
#include <stdlib.h> //system ("clear || cls")
#include <limits> //cin.ignore

using namespace std;

struct node{
    string data;
    node *link;
} *head = nullptr;

void Push(string x);
void Pop();
void Show();
void Clear();

int main(){
    int option;
    string x;

    cout << "====================================STACKS WITH CHARACTERS=============================\n";
    do{
        Show();
        cout << endl << "========================MENU=========================" << endl;
        cout << "[1]. Push" << endl;
        cout << "[2]. Pop" << endl;
        cout << "[3]. Show Stack" << endl;
        cout << "[4]. Clear Stack" << endl;
        cout << "[0]. Exit" << endl;
        cout << "=====================================================" << endl;
        cout << "Select an option: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option){
            case 1:
                system("cls || clear");
                cout << endl << "Enter the data that you want to push: ";
                getline(cin, x);
                Push(x);
            break;
            case 2:
                system("cls || clear");
                Pop();
            break;
            case 3:
                system("cls || clear");
                Show();
            break;
            case 4:
                system("cls || clear");
                Clear();
            break;
            default:
                system("cls || clear");
                cout << endl << "Please enter a valid option." << endl;
            break;
        }
        if (option != 0){
            cout << endl << "Press any key to return to the menu.";
            cin.get();
        }
        system("cls || clear");
    } while (option != 0);

    return 0;
}

void Push(string x){
    node* temp = new node;
    temp->data = x;
    temp->link = head;
    head = temp;
    cout << endl << "Element: '" << x << "' correctly pushed." << endl;
}

void Pop(){
    node* temp = new node;
    if (head == nullptr){
        cout << endl << "Nothing to delete, the stack is already empty." << endl;
        return;
    }
    temp = head;
    head = head->link;
    delete(temp);
    if (head == nullptr){
        cout << endl << "Last element deleted, the stack is empty now." << endl;
    } else {
    cout << endl << "Last element deleted correctly." << endl;
    }
}

void Show(){
    node* temp = new node;
    if (head == nullptr){
        cout << endl << "---STACK EMPTY---"<< endl;
        return;
    }
    temp = head;
    cout << endl << "\tSTACK:";
    while (temp != nullptr){
        cout << endl << "[" << temp->data << "]";
        temp = temp->link;
    }
    cout << endl;
}

void Clear(){
    node *temp = new node;
    if (head == nullptr){
        cout << endl << "Nothing to clear, stack is empty." << endl;
        return;
    }
    while (head != nullptr){
        temp = head;
        head = head->link;
        delete(temp);
    }
    cout << endl << "Stack cleared correctly." << endl;
}

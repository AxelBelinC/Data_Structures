/*
| 29/04/2026 || 02/05/2026 |
Axel Armando Belin Castorena - 355651
Intelligent Computing Engineering 2°A - UAA
Program objective: Through a menu, allow the modification and creation of stacks with the possibility of use characters.
Updates: Adjust "new node" creation and system calls. Rename variables and functions for clarity.
*/

#include <iostream>
#include <string>
#include <stdlib.h> //system ("clear || cls")
#include <limits> //cin.ignore

using namespace std;

struct node{
    string data;
    node *link;
} *top = nullptr;

void Push(string x);
void Pop();
void ShowStack();
void ClearStack();

int main(){
    int option;
    string x;

    cout << "====================================STACKS WITH CHARACTERS=============================\n";
    do{
        ShowStack();
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
        system("cls || clear");

        switch (option){
            case 1:
                cout << endl << "Enter the data that you want to push: ";
                getline(cin, x);
                Push(x);
            break;
            case 2: Pop(); break;
            case 3: ShowStack(); break;
            case 4: ClearStack(); break;
            default: 
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
    node* temp = new node();
    temp->data = x;
    temp->link = top;
    top = temp;
    cout << endl << "Element: '" << x << "' correctly pushed." << endl;
}

void Pop(){
    if (top == nullptr){
        cout << endl << "Nothing to delete, the stack is already empty." << endl;
        return;
    }
    node *temp = top;
    top = top->link;
    if (top == nullptr){
        cout << endl << "Last element: '" << temp->data << "' deleted, the stack is empty now." << endl;
    } else {
    cout << endl << "Last element: '" << temp->data << "' deleted correctly." << endl;
    }
    delete temp;
}

void ShowStack(){
    if (top == nullptr){
        cout << endl << "---STACK EMPTY---"<< endl;
        return;
    }
    node *temp = top;
    cout << endl << "\tSTACK:";
    while (temp != nullptr){
        cout << endl << "[" << temp->data << "]";
        temp = temp->link;
    }
    cout << endl;
}

void ClearStack(){
    if (top == nullptr){
        cout << endl << "Nothing to clear, stack is empty." << endl;
        return;
    }
    node *temp = nullptr;
    while (top != nullptr){
        temp = top;
        top = top->link;
        delete temp;
    }
    cout << endl << "Stack cleared correctly." << endl;
}
/*
| 19/05/2026 || 19/05/2026 |
Axel Armando Belin Castorena - 355651
Intelligent Computing Engineering 2°A - UAA
Program objective: Implement Doubly Linked Stacks with numbers.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
} *top = nullptr;

void Push(int x);
void Pop();
void ShowStack();
void ClearStack();

int main(){
    int option, x;

    cout << "====================================Doubly Linked Stack=============================" << endl;
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
        system("cls || clear");

        switch(option){
            case 1:
                cout << "Enter the data that you want to push: ";
                cin >> x;
                Push(x);
            break;
            case 2: Pop(); break;
            case 3: ShowStack(); break;
            case 4: ClearStack(); break;
            default: cout << endl << "Please enter a valid option." << endl; break;
        }
        if (option != 0){
            cout << endl;
            system("pause");
        }
        system("cls || clear");
    }while(option != 0);
    return 0;
}

void Push(int x){
    node *temp = new node();
    temp->data = x;
    temp->prev = nullptr;
    if (top == nullptr){
        temp->next = nullptr;
    } else{
        top->prev = temp;
        temp->next = top;
    }
    top = temp;
    cout << endl << "Element [" << temp->data << "] pushed." << endl;
}

void Pop(){
    if (top == nullptr){
        cout << endl << "Stack already empty." << endl;
        return;
    }
    node *temp = top;
    top = top->next;
    if (top == nullptr){
        cout << endl << "Stack is empty now. Last element [" << temp->data << "] deleted." << endl;
    } else {
        cout << endl << "Element at the top [" << temp->data << "] deleted." << endl;
        top->prev = nullptr;
    }
    delete temp;
}

void ShowStack(){
    if (top == nullptr){
        cout << endl << "--EMPTY STACK--" << endl;
        return;
    }
    node *temp = top;
    cout << "--------STACK---------" << endl;
    while (temp != nullptr){
        cout << endl << "\t[" << temp->data << "]\r";
        temp = temp->next;
    }
    cout << endl;
}

void ClearStack(){
    if (top == nullptr){
        cout << endl << "Stack already empty." << endl;
        return;
    }
    while(top != nullptr){
        node *temp = top;
        top = top->next;
        delete temp;
    }
    cout << endl << "Memory Stack Restored" << endl;
}
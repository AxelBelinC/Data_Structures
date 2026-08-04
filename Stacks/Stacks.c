/*
| 09/04/2026 || 04/05/2026 |
Axel Armando Belin Castorena - 355651
Intelligent Computing Engineering 2°A - UAA
Program objective: Through a menu, allow the modification and creation of stacks.
Updates: Translated to English and reworked pointer allocations.
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
} *head = NULL;

//Function Prototypes
void Push(int x);
void Pop();
void ShowStack();
void ClearStack();

int main() {
	int op, x;
	printf("===================STACK=======================\n");
	do{
		ShowStack();
		printf("\n================MENU================\n");
		printf("[1]. Push\n");
		printf("[2]. Pop\n");
		printf("[3]. Show Stack\n");
		printf("[4]. Clear Stack\n");
		printf("[0]. EXIT");
		printf("\n====================================\n");
		scanf("%d", &op);
		system("cls");
	
		switch (op){
			case 1:
				printf("Enter the data that you want to push: ");
				scanf("%d", &x);
				Push(x);
			break;
			case 2:
				Pop();
			break;
			case 3:
				printf("Showing Stack...\n");
				ShowStack();
			break;
			case 4:
				printf("Deleting the stack...\n");
				ClearStack();
			break;
			case 0: 
        		printf("\nFinishing program...\n");
        	break;
			default:
				printf("Please enter a valid option.");
			break;
		}
		if (op != 0){
			printf("\nPress \"enter\" to return...\n");
			fflush(stdin);
			getchar();
		}
		system("cls");
	} while (op != 0);
	return 0;
}

//Function Implementations
void Push(int x){
	struct node *temp = NULL;
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL){
		printf("\nMemory Error.\n");
		return;
	}
	temp->data = x;
	temp->link = head;
	head = temp;
	printf("\nElement [%d] pushed correctly.\n", x);
}

void Pop(){
	struct node *temp;
	if (head == NULL){
		printf("The stack is already empty.\n");
		return;
	}
	temp = head;
	head = head->link;
	printf("\nThe last element: [%d] was deleted.\n", temp->data);
	free(temp);
	temp = NULL;
}

void ShowStack(){
	struct node *temp;
	if (head == NULL){
		printf("\nEmpty Stack.\n");
		return;
	}
	temp = head;
	printf("\nSTACK:\n");
	while(temp != NULL){ 
		printf("\n[%d]", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

void ClearStack(){
	struct node *temp = NULL;
	if (head == NULL){
		printf("\nEmpty Stack. Nothing to clear.\n");
		return;
	}
	while (head != NULL){
		temp = head;
		head = head->link;
		free(temp);
	}
	printf("\nStack cleared.\n");
}
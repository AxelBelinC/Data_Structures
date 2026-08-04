/* | 26/03/2026 || 19/05/2026 |
Axel Armando Belin Castorena - 355651
Intelligent Computing Engineering 2°A - UAA
Program objective: Through a menu, allow the modification of a sinlgy linked list.
Updates: Translating the program to english
*/

#include <stdio.h>
#include <stdlib.h> //malloc, null, system
#include <stdbool.h> 

struct node{
	int data;
	struct node *link;
} *head = NULL; 

//---------Function Prototypes--------------
void CreateList(int x);
void Insert_Start(int x);
void Insert_End(int x);
void Insert_Before(int x, int y);
void Insert_After(int x, int y);
void Delete_Start();
void Delete_End();
void ShowList();
void SearchElement(int x);
void CleanList();

int main (){
	int op, x, y;
	printf("-------------------------------------------------\n");
	printf("|\t\tSINGLY LINKED LIST\t\t|\n");
	printf("-------------------------------------------------\n");
	do {
		printf("\n=============================================\n");
		printf("\t\t     MENU");
		printf("\n=============================================\n");
		printf("[1]. Create List\n");
		printf("[2]. Insert at beginming\n");
		printf("[3]. Insert at end\n");
		printf("[4]. Insert before specific position\n");
		printf("[5]. Insert after specific position\n");
		printf("[6]. Delete first element\n");
		printf("[7]. Delete last element\n");
		printf("[8]. Show List\n");
		printf("[9]. Search an element\n");
		printf("[0]. Exit");
		printf("\n=============================================\n");
		printf("Option: ");
		scanf("%d", &op);
		system("cls");
	
		switch(op){
			case 1:
				printf("Enter the first element of the new list: ");
				scanf("%d", &x);
				CreateList(x);
			break;
			case 2:
				printf("Enter the element that you want at the beginning: ");
				scanf("%d", &x);
				Insert_Start(x);
			break;
			case 3:
				printf("Enter the element that you want at the end: ");
				scanf("%d", &x);
				Insert_End(x);
			break;
			case 4:
				printf("Enter the element that you want to insert: ");
				scanf("%d", &x);
				printf("\nBefore of: ");
				scanf("%d", &y);
				Insert_Before(x, y);
			break;
			case 5:
				printf("Enter the element that you want to inser: ");
				scanf("%d", &x);
				printf("\nAfter of: ");
				scanf("%d", &y);
				Insert_After(x, y);
			break;
			case 6:
				Delete_Start();
			break;
			case 7:
				Delete_End();
			break;
			case 8:
				ShowList();
			break;
			case 9:
				printf("Enter the element to search: ");
				scanf("%d", &x);
				SearchElement(x);
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
	CleanList();
	return 0;
}

//----------Function Implementations--------------
void CreateList(int x){
	if (head != NULL){
		printf("\nList already created. Select another option.\n");
		return;
	}
	head = (struct node *)malloc(sizeof(struct node));
	if (head == NULL){
		printf("\nMemory Error.\n");
		return;
	}
	head->data = x;
	head->link = NULL; 
	printf("\nList initialized with element [%d].\n", x);
}

void Insert_Start(int x){
	struct node *temp = NULL; 
	temp = (struct node *)malloc(sizeof(struct node)); 
	if (temp == NULL){
		printf("\nMemory Error.\n");
		return;
	}
	temp->data = x;
	temp->link = head; 
	head = temp;
	printf("\nElement [%d] inserted at the beginning.\n", x);
}

void Insert_End(int x){
	struct node *q, *temp = NULL;
	q = (struct node *)malloc(sizeof(struct node));
	if (q == NULL){
		printf("\nMemory Error.\n");
		return;
	}
	q->data = x;
	q->link = NULL;
	if (head == NULL){
		head = q;
	} else {
		temp = head;
		while (temp->link != NULL){ 
			temp = temp->link; 
		}
		temp->link = q;
	}
	printf("\nElement [%d] inserted at the end.\n", x);
}

void Insert_Before(int x, int y){
	struct node *temp, *prev, *new;
	if (head == NULL){
		printf("\nThe list is empty.\n");
		return;
	}
    if (head->data == y) {
        Insert_Start(x);
        return;
    }
    temp = head;
    while(temp != NULL && temp->data != y){
    	prev = temp; 
        temp = temp->link; 
	}
    if (temp == NULL){
    	printf("\nElement [%d] doesn't exist in the list.", y);
    	return;
	} else {
        new = (struct node *)malloc(sizeof(struct node));
        if (new == NULL) {
            printf("\nMemory Error.\n");
            return;
        }
        new->data = x;
        new->link = temp;   
        prev->link = new; 
	}
	printf("\nElement [%d] inserted before [%d].\n", x, y);
}

void Insert_After(int x, int y){
	if (head == NULL){
		printf("\nThe list is empty.\n");
		return;
	}
	struct node *q = NULL;
    struct node *temp = head;
    while (temp != NULL && temp->data != y) {
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("\nElement [%d] doesn't exist on the list.\n", y);
        return;
    }
    q = (struct node *)malloc(sizeof(struct node));
    if (q == NULL) {
        printf("\nMemory Error.\n");
        return;
    }
    q->data = x;
    q->link = temp->link; 
    temp->link = q;
	printf("\nElement [%d] inserted after [%d].\n", x, y);
}

void Delete_Start(){
	if (head == NULL){
		printf("\nThe list is already empty.\n");
		return;
	}	
	struct node *temp = head;
	head = head->link;
	printf("\nFirst element [%d] deleted.\n", temp->data);
	free(temp);
}

void Delete_End(){
	if (head == NULL){
		printf("\nThe list is empty.\n");
		return;
	}
	struct node *temp = head;
	if (head->link == NULL) {
        printf("\nThe only element [%d] was deleted.\n", head->data);
        free(head);
        head = NULL; 
        return;
    }
	struct node *prev = NULL;
    while(temp->link != NULL){
        prev = temp;   
        temp = temp->link; 
    }
	prev->link = NULL; 
    printf("\nThe last element [%d] was deleted.\n", temp->data);
    free(temp);
}

void ShowList(){
	if (head == NULL){
		printf("\nEmpty List.\n");
		return;
	}
	struct node *temp = head;
	printf("Linked List:\n");
	while (temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->link;
	}
	printf("NULL\n");
}

void SearchElement(int x){
	struct node *temp;
	int position = 1; 
    bool found = false;

    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }

    temp = head;

    while (temp != NULL) {
        if (temp->data == x) {
            printf("\nElement [%d] found at position [%d].\n", x, position);
            found = true;
            break; 
        }
        temp = temp->link;
        position++;
    }

    if (!found) {
        printf("\nElement [%d] wasn't found in the list.\n", x);
    }
}

void CleanList(){
	struct node *temp;
    while (head != NULL) {
        temp = head; 
        head = head->link; 
        free(temp); 
    }
    printf("\nRestored Linked List Memory\n");
}
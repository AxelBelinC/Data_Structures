/*
| 09/04/2026 || 29/04/2026 |
Axel Armando Belin Castorena - 355651
Intelligent Computing Engineering 2°A - UAA
Program objective: Through a menu, allow the modification and creation of stacks.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct node{
	int data;
	struct node *link;
} *head = NULL;

//Prototipos de Funciones
void Apilar(int x);
void Desapilar();
void MostrarPila();
void VaciarPila();

//Definición de Funciones
void Apilar(int x){
	struct node *q = NULL;
	q = (struct node *)malloc(sizeof(struct node));
	if (q == NULL){
		printf("\nError de memoria.\n");
		return;
	}
	q->data = x;
	if (head == NULL){ 
		q->link = NULL;
	} else { //"apilar"
		q->link = head; 
	}
	head = q;
	printf("\nElemento [%d] apilado correctamente.\n", x);
}

void Desapilar(){
	struct node *temp;
	if (head == NULL){
		printf("Nada que desapilar. La pila está vacía.\n");
		return;
	}
	temp = head;
	head = head->link;
	free(temp);
	printf("\nEl último elemento fue desapilado.\n");
}

void MostrarPila(){
	struct node *temp;
	if (head == NULL){
		printf("\nPila vacía.\n");
		return;
	}
	temp = head;
	printf("\nPILA:\n");
	while(temp != NULL){ 
		printf("\n[%d]", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

void VaciarPila(){
	struct node *temp;
	if (head == NULL){
		printf("\nPila vacía, nada que eliminar.\n");
		return;
	}
	while (head != NULL){
		temp = head;
		head = head->link;
		free(temp);
	}
	printf("\nPila eliminada correctamente.\n");
}

int main() {
	int op, x;
	setlocale(LC_ALL,"Spanish");
	printf("===================PILA=======================\n");
	do{
		system("cls");
		MostrarPila();
		printf("\n================MENÚ================\n");
		printf("[1]. APILAR\n");
		printf("[2]. DESAPILAR\n");
		printf("[3]. MOSTRAR PILA\n");
		printf("[4]. VACIAR PILA\n");
		printf("[0]. SALIR");
		printf("\n====================================\n");
		scanf("%d", &op);
	
		switch (op){
			case 1:
				system("cls");
				printf("Ingrese el número que quiera agregar a la pila: ");
				scanf("%d", &x);
				Apilar(x);
			break;
			case 2:
				system("cls");
				Desapilar();
			break;
			case 3:
				system("cls");
				printf("Mostrando pila..");
				MostrarPila();
			break;
			case 4:
				system("cls");
				printf("Vaciando la pila...\n");
				VaciarPila();
			break;
			case 0: 
        	system("cls");
        	printf("\nSaliendo del programa...\n");
        	break;
			default:
				system("cls");
				printf("Ingrese una opción válida.");
			break;
		}
		if (op != 0){
			printf("\nPresione enter para volver al menú..\n");
			fflush(stdin);
			getchar();
		}
	} while (op != 0);
}
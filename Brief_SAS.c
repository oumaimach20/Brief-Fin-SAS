#include<stdio.h>
#include<stdlib.h>

// Enumeration for priority levels
enum Priority {
	HIGH = 1,
	MEDIUM,
	LOW
};

// Structure for representing a date
struct Date {
	int day;
	int month;
	int year;
};

// Structure for representing a task
struct Task {
	char name[50];
	char description[100];
	struct Date deadline;
	enum Priority priority;
};

int main() {
	char choix;
	//Afficher le menu
	printf("   Bienvenue dans le logiciel de gestion des taches(:\n");
	printf("\n        Menu :\n");
	printf("\n1.Ajouter une tache.\n");
	printf("2.Afficher la liste des taches.\n");
	printf("3.Modifier une tache.\n");
	printf("4.Supprimer une tache.\n");
	printf("5.Ordonner les taches.\n");
	printf("6.Filtrer les taches.\n");
	printf("7.Quitter.\n");
	//Demander à l'utilisateur de choisir
	printf("\nVeuillez entrer votre choix:");
	scanf("%c", &choix);
	



}
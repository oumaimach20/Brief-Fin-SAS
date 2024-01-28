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
// Function to add a new task
int ajouter(struct Task taches[], int numTask) {
    printf("New task:\n");

    // Ask the user to enter task details
    printf("Name:");
    scanf("%s", taches[numTask].name);
    printf("Description: ");
    scanf(" %[^\n]s", taches[numTask].description);

    // Ask the user to enter the deadline
    printf("Deadline (day month year): ");
    scanf("%d %d %d", &taches[numTask].deadline.day, &taches[numTask].deadline.month, &taches[numTask].deadline.year);

    // Ask the user to choose the priority
    printf("Priority 1: High, 2: Medium, 3: Low): ");
    int priorityChoix;
    scanf("%d", &priorityChoix);

    switch (priorityChoix) {
    case 1:
        taches[numTask].priority = HIGH;
        break;
    case 2:
        taches[numTask].priority = MEDIUM;
        break;
    case 3:
        taches[numTask].priority = LOW;
        break;
    default:
        printf("Invalid priority choice.\n");
        break;
    }

    // Increment the total number of tasks
    numTask++;

    printf("Task added successfully!\n");

    return numTask;
}
// Function to display the list of tasks
void afficher(struct Task taches[], int numTask) {
    printf("\nList of tasks:\n");

    for (int i = 0; i < numTask; i++) {
        printf("Task %d:\n", i + 1);
        printf("Name: %s\n", taches[i].name);
        printf("Description: %s\n", taches[i].description);
        printf("Deadline: %d/%d/%d\n", taches[i].deadline.day, taches[i].deadline.month, taches[i].deadline.year);
        printf("Priority: ");
        switch (taches[i].priority) {
        case HIGH:
            printf("High\n");
            break;
        case MEDIUM:
            printf("Medium\n");
            break;
        case LOW:
            printf("Low\n");
            break;
        default:
            printf("Unknown\n");
        }
        printf("\n");
    }
}

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

    switch (choix) {
    case 1:
        // Add a task
        numTask = ajouter(taches, numTask);
        break;
    case 2:
        // Display the list of tasks
        //afficher(taches, numTask);
        break;
    case 3:
        // Modify a task
        // Add the code for modifying a task
        break;
    case 4:
        // Delete a task
        //Add the code for deleting an existing task
        break;
    case 5:
        // Sort tasks by date
        // Add the code for sorting tasks by date
        break;
    case 6:
        // Filter tasks by priority
        // Add the code for filtering tasks by priority
        break;
    case 7:
        // Quit the program
        printf("Goodbye!\n");
        break;
    default:
        printf("Invalid choice. Please try again.\n");
    }
	



}
#include <stdio.h>

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
    int priority;
};
// Global variables
struct Task taches[100];
int numTask = 0;
int filterPriority;

// Function prototypes
int ajouter();
void afficher();
int supprimer();
void modifier();
void echange(struct Task* a, struct Task* b);
void triBulleCroissant();
void triBulleDecroissant();
void filterByPriority();

int main() {
    int choix;
    int ordre;

    // Welcoming the user
    printf("Welcome to the Task Management Software:)\n");
    do {
        // Display the menu
        printf("\n             Menu:\n \n");
        printf("1. Add a task\n");
        printf("2. Display the list of tasks\n");
        printf("3. Modify a task\n");
        printf("4. Delete a task\n");
        printf("5. Sort tasks by date\n");
        printf("6. Filter tasks by priority\n");
        printf("7. Quit\n");
        printf("\n Choice: ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            // Add a task
            ajouter();
            break;
        case 2:
            // Display the list of tasks
            afficher();
            break;
        case 3:
            // Modify a task
            modifier();
            break;
        case 4:
            // Delete a task
            supprimer();
            break;
        case 5:
            // Sort tasks by date
            printf("Choose order for sorting:\n");
            printf("1. Ascending\n");
            printf("2. Descending\n");
            printf("Order: ");
            scanf("%d", &ordre);

            printf(" Tasks before the sort : \n");
            afficher();

            if (ordre == 1) {
                // Ascending order
                triBulleCroissant();
                printf("Tasks after the sort (Ascending): \n");
            }
            else if (ordre == 2) {
                // Descending order
                triBulleDecroissant();
                printf("Tasks after the sort (Descending): \n");
            }
            else {
                printf("Invalid order choice.\n");
                continue;
            }

            afficher();
            break;
        case 6:
            // Filter tasks by priority
            printf("Enter the priority to filter (1 for High, 2 for Medium, 3 for Low): ");
            scanf("%d", &filterPriority);
            filterByPriority();

            break;
        case 7:
            // Quit the program
            printf("Goodbye! It was nice to see you here!\n");
            break;
        default:
            printf("Invalid choice. Please try again:)\n");
        }
    } while (choix != 7);

    return 0;
}

// Function to add a new task
int ajouter() {
    printf("New task:\n");

    // Ask the user to enter task details
    printf("Name:");
    scanf("%s", taches[numTask].name);
    printf("Description: ");
    scanf(" %[^\n]s", taches[numTask].description);

    // Ask the user to enter the deadline
    printf("Deadline (day month year): ");
    scanf("%d %d %d", &taches[numTask].deadline.day, &taches[numTask].deadline.month, &taches[numTask].deadline.year);

    // Validate the deadline year
    if (taches[numTask].deadline.year != 2024) {
        printf("Invalid year. Please enter the year 2024.\n");
        return numTask; // Return without incrementing numTask
    }

    // Ask the user to choose the priority as an integer
    printf("Priority (1 for High, 2 for Medium, 3 for Low): ");
    scanf("%d", &taches[numTask].priority);

    // Increment the total number of tasks
    numTask++;

    printf("Task added successfully!\n");

    return numTask;
}

// Function to display the list of tasks
void afficher() {
    if (numTask == 0) {
        printf("No tasks to display.\n");
    }
    printf("\nList of tasks:\n");

    for (int i = 0; i < numTask; i++) {
        printf("\nTask %d:\n", i + 1);
        printf("Name: %s\n", taches[i].name);
        printf("Description: %s\n", taches[i].description);
        printf("Deadline: %d/%d/%d\n", taches[i].deadline.day, taches[i].deadline.month, taches[i].deadline.year);
        printf("Priority: %d\n", taches[i].priority);
        printf("\n");
    }
}

// Function to delete a task
int supprimer() {
    if (numTask == 0) {
        printf("No tasks to delete.\n");
        return numTask;
    }

    int indexToDelete;
    printf("Enter the index of the task to delete (1 to %d): ", numTask);
    scanf("%d", &indexToDelete);

    if (indexToDelete < 1 || indexToDelete > numTask) {
        printf("Invalid index. Please enter a valid index.\n");
    }
    else {
        // Confirmation prompt
        char confirmation;
        printf("Are you sure you want to delete Task %d? (Y/N): ", indexToDelete);
        scanf(" %c", &confirmation);

        if (confirmation == 'Y') {
            // Shift remaining tasks to fill the gap
            for (int i = indexToDelete - 1; i < numTask - 1; i++) {
                taches[i] = taches[i + 1];
            }

            // Decrement the total number of tasks
            numTask--;

            printf("Task deleted successfully!\n");
        }
        else {
            printf("Task deletion canceled.\n");
        }
    }

    return numTask;
}

// Function to edit a task
void modifier() {
    if (numTask == 0) {
        printf("No tasks to edit.\n");
        return;
    }

    int indexToEdit;
    printf("Enter the index of the task to edit (1 to %d): ", numTask);
    scanf("%d", &indexToEdit);

    if (indexToEdit < 1 || indexToEdit > numTask) {
        printf("Invalid index. Please enter a valid index.\n");
    }
    else {
        // Ask the user to enter new details
        printf("Enter new details for Task %d:\n", indexToEdit);
        printf("New Name: ");
        scanf("%s", taches[indexToEdit - 1].name);
        printf("New Description: ");
        scanf(" %[^\n]s", taches[indexToEdit - 1].description);
        printf("New Deadline (day month year): ");
        scanf("%d %d %d", &taches[indexToEdit - 1].deadline.day,
            &taches[indexToEdit - 1].deadline.month, &taches[indexToEdit - 1].deadline.year);
        printf("New Priority (1 for High, 2 for Medium, 3 for Low): ");
        scanf("%d", &taches[indexToEdit - 1].priority);

        printf("Task edited successfully!\n");
    }
}

// Function to exchange two tasks
void echange(struct Task* a, struct Task* b) {
    struct Task tmp = *a;
    *a = *b;
    *b = tmp;
}

// Function to sort tasks by date in ascending order
void triBulleCroissant() {
    int i, j;
    for (i = 0; i < numTask - 1; i++) {
        for (j = 0; j < numTask - i - 1; j++) {
            if ((taches[j].deadline.year > taches[j + 1].deadline.year) ||
                (taches[j].deadline.year == taches[j + 1].deadline.year &&
                    taches[j].deadline.month > taches[j + 1].deadline.month) ||
                (taches[j].deadline.year == taches[j + 1].deadline.year &&
                    taches[j].deadline.month == taches[j + 1].deadline.month &&
                    taches[j].deadline.day > taches[j + 1].deadline.day))
                echange(&taches[j], &taches[j + 1]);
        }
    }
}

// Function to sort tasks by date in descending order
void triBulleDecroissant() {
    int i, j;
    for (i = 0; i < numTask - 1; i++) {
        for (j = 0; j < numTask - i - 1; j++) {
            if ((taches[j].deadline.year < taches[j + 1].deadline.year) ||
                (taches[j].deadline.year == taches[j + 1].deadline.year &&
                    taches[j].deadline.month < taches[j + 1].deadline.month) ||
                (taches[j].deadline.year == taches[j + 1].deadline.year &&
                    taches[j].deadline.month == taches[j + 1].deadline.month &&
                    taches[j].deadline.day < taches[j + 1].deadline.day))
                echange(&taches[j], &taches[j + 1]);
        }
    }
}

// Function to filter tasks by priority
void filterByPriority() {
    if (numTask == 0) {
        printf("No tasks to filter.\n");
    }
    printf("\nFiltered tasks by priority: \n");

    for (int i = 0; i < numTask; i++) {
        if (taches[i].priority == filterPriority) {
            printf("Task %d:\n", i + 1);
            printf("Name: %s\n", taches[i].name);
            printf("Description: %s\n", taches[i].description);
            printf("Deadline: %d/%d/%d\n", taches[i].deadline.day, taches[i].deadline.month, taches[i].deadline.year);
            printf("Priority: %d\n", taches[i].priority);
            printf("\n");
        }
    }
}
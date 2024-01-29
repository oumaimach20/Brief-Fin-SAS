#include <stdio.h>

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

// Function to delete a task
int supprimer(struct Task taches[], int numTask) {
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
        // Shift remaining tasks to fill the gap
        for (int i = indexToDelete - 1; i < numTask - 1; i++) {
            taches[i] = taches[i + 1];
        }

        // Decrement the total number of tasks
        numTask--;

        printf("Task deleted successfully!\n");
    }

    return numTask;
}

// Function to edit a task
void modifier(struct Task taches[], int numTask) {
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
        printf("Name: ");
        scanf("%s", taches[indexToEdit - 1].name);
        printf("Description: ");
        scanf(" %[^\n]s", taches[indexToEdit - 1].description);
        printf("Deadline (day month year): ");
        scanf("%d %d %d", &taches[indexToEdit - 1].deadline.day,
            &taches[indexToEdit - 1].deadline.month, &taches[indexToEdit - 1].deadline.year);
        printf("Priority 1: High, 2: Medium, 3: Low): ");
        int priorityChoix;
        scanf("%d", &priorityChoix);

        switch (priorityChoix) {
        case 1:
            taches[indexToEdit - 1].priority = HIGH;
            break;
        case 2:
            taches[indexToEdit - 1].priority = MEDIUM;
            break;
        case 3:
            taches[indexToEdit - 1].priority = LOW;
            break;
        default:
            printf("Invalid priority choice.\n");
            break;
        }

        printf("Task edited successfully!\n");
    }
}

int main() {
    // Declare an array of tasks
    struct Task taches[100];
    int numTask = 0;

    int choix;

    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Add a task\n");
        printf("2. Display the list of tasks\n");
        printf("3. Modify a task\n");
        printf("4. Delete a task\n");
        printf("5. Sort tasks by date\n");
        printf("6. Filter tasks by priority\n");
        printf("7. Quit\n");
        printf("Choice: ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            // Add a task
            numTask = ajouter(taches, numTask);
            break;
        case 2:
            // Display the list of tasks
            afficher(taches, numTask);
            break;
        case 3:
            // Modify a task
            modifier(taches, numTask);
            break;
        case 4:
            // Delete a task
            numTask = supprimer(taches, numTask);
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
    } while (choix != 7);

    return 0;
}

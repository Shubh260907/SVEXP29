#include <stdio.h>
#include <string.h> // For strcmp()

// Define a maximum number of teams the system can hold
#define MAX_TEAMS 50

/*
 * Structure to store coach details.
 * This will be nested inside the Team structure.
 */
struct Coach {
    char name[100];
    int age;
    int experience; // in years
};

/*
 * Structure to store team details.
 * It includes a nested structure 'coach_info' of type 'struct Coach'.
 */
struct Team {
    char team_name[100];
    char sport_type[50];
    struct Coach coach_info; // Nested structure variable
};

// Global array to store all the teams and a counter
struct Team teams[MAX_TEAMS];
int team_count = 0; // Keeps track of how many teams have been added

// This function clears the input buffer (e.g., the leftover newline)
// after a scanf call, which prevents issues with subsequent string inputs.
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
 * Function to add a new team to the system.
 * It takes input for team details and the nested coach details.
 */
void add_team() {
    // Check if the array is full
    if (team_count >= MAX_TEAMS) {
        printf("Error: Maximum number of teams (%d) reached.\n", MAX_TEAMS);
        return;
    }

    printf("\n--- Add New Team ---\n");
    printf("Enter details for Team %d:\n", team_count + 1);

    // Get Team Details
    printf("  Enter Team Name: ");
    scanf("%99[^\n]", teams[team_count].team_name);
    clear_input_buffer();

    printf("  Enter Sport Type (e.g., Football, Basketball): ");
    scanf("%49[^\n]", teams[team_count].sport_type);
    clear_input_buffer();

    // Get Nested Coach Details
    printf("\n  --- Enter Coach Details ---\n");
    printf("    Enter Coach's Name: ");
    scanf("%99[^\n]", teams[team_count].coach_info.name);
    clear_input_buffer();

    printf("    Enter Coach's Age: ");
    scanf("%d", &teams[team_count].coach_info.age);
    clear_input_buffer();

    printf("    Enter Coach's Experience (in years): ");
    scanf("%d", &teams[team_count].coach_info.experience);
    clear_input_buffer();

    // Increment the team counter
    team_count++;
    printf("\nTeam added successfully!\n");
}

/*
 * Function to search for a specific team by its name
 * and display its details if found.
 */
void search_team() {
    char search_name[100];
    int found = 0; // Flag to check if team was found

    if (team_count == 0) {
        printf("\nNo teams to search. Please add a team first.\n");
        return;
    }

    printf("\n--- Search for a Team ---\n");
    printf("Enter Team Name to search: ");
    scanf("%99[^\n]", search_name);
    clear_input_buffer();

    // Loop through all added teams
    for (int i = 0; i < team_count; i++) {
        // Use strcmp to compare strings. It returns 0 if they are identical.
        if (strcmp(teams[i].team_name, search_name) == 0) {
            printf("\n--- Team Found! ---\n");
            printf("  Team Name: %s\n", teams[i].team_name);
            printf("  Sport Type: %s\n", teams[i].sport_type);
            printf("  --- Coach Info ---\n");
            printf("    Name: %s\n", teams[i].coach_info.name);
            printf("    Age: %d\n", teams[i].coach_info.age);
            printf("    Experience: %d years\n", teams[i].coach_info.experience);
            printf("-----------------------\n");
            found = 1;
            break; // Stop searching once found
        }
    }

    if (!found) {
        printf("\nSorry, team '%s' not found.\n", search_name);
    }
}

/*
 * Function to display details for all teams
 * currently stored in the system.
 */
void display_all_teams() {
    if (team_count == 0) {
        printf("\nNo teams to display. Please add a team first.\n");
        return;
    }

    printf("\n--- Displaying All Teams (%d) ---\n", team_count);
    // Loop through all added teams and print their info
    for (int i = 0; i < team_count; i++) {
        printf("\n--- Team %d ---\n", i + 1);
        printf("  Team Name: %s\n", teams[i].team_name);
        printf("  Sport Type: %s\n", teams[i].sport_type);
        printf("  --- Coach Info ---\n");
        printf("    Name: %s\n", teams[i].coach_info.name);
        printf("    Age: %d\n", teams[i].coach_info.age);
        printf("    Experience: %d years\n", teams[i].coach_info.experience);
        printf("-----------------------\n");
    }
}

/*
 * Main function with a menu-driven interface
 */
int main() {
    int choice;

    do {
        // Display the menu
        printf("\n\n--- CHARUSAT Sports Team Management System ---\n");
        printf("1. Add a New Team\n");
        printf("2. Search for a Team\n");
        printf("3. Display All Teams\n");
        printf("4. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice: ");

        // Get user's choice
        scanf("%d", &choice);
        clear_input_buffer(); // Clear newline after scanf

        // Handle the choice using a switch statement
        switch (choice) {
            case 1:
                add_team();
                break;
            case 2:
                search_team();
                break;
            case 3:
                display_all_teams();
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4); // Keep looping until user chooses to exit

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
    char diabetes[10];
    char blood_pressure[10];
} Person;

void recordData();
void displayAllPersons();
void displayOneDisease();
void menu();

int main() {
    menu();
    return 0;
}

void recordData() {
    FILE *file = fopen("ncd_data.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Person person;
    printf("Enter name: ");
    scanf("%s", person.name);
    printf("Enter age: ");
    scanf("%d", &person.age);
    printf("Diabetes result (Positive/Negative): ");
    scanf("%s", person.diabetes);
    printf("Blood pressure result (Positive/Negative): ");
    scanf("%s", person.blood_pressure);

    fprintf(file, "%s %d %s %s\n", person.name, person.age, person.diabetes, person.blood_pressure);
    fclose(file);
    printf("Data recorded successfully!\n");
}

void displayAllPersons() {
    FILE *file = fopen("ncd_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Person person;
    printf("All Persons Tested:\n");
    while (fscanf(file, "%s %d %s %s", person.name, &person.age, person.diabetes, person.blood_pressure) != EOF) {
        printf("%s, %d, Diabetes: %s, Blood Pressure: %s\n", person.name, person.age, person.diabetes, person.blood_pressure);
    }
    fclose(file);
}

void displayOneDisease() {
    FILE *file = fopen("ncd_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Person person;
    printf("Persons with Only One Disease:\n");
    while (fscanf(file, "%s %d %s %s", person.name, &person.age, person.diabetes, person.blood_pressure) != EOF) {
        if ((strcmp(person.diabetes, "Positive") == 0) != (strcmp(person.blood_pressure, "Positive") == 0)) {
            printf("%s, %d, Diabetes: %s, Blood Pressure: %s\n", person.name, person.age, person.diabetes, person.blood_pressure);
        }
    }
    fclose(file);
}

void menu() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Record Data\n");
        printf("2. Display All Persons Tested\n");
        printf("3. Display Persons with Only One Disease\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recordData();
                break;
            case 2:
                displayAllPersons();
                break;
            case 3:
                displayOneDisease();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

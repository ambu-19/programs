#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for patient
struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

struct Patient p[MAX];
int count = 0;

// Function declarations
void addPatient();
void searchPatient();
void displayAll();
void updatePatient();
void deletePatient();

int main() {
    int choice;

    while (1) {
        printf("\n===== HOSPITAL MANAGEMENT SYSTEM =====\n");
        printf("1. Add Patient\n");
        printf("2. Search Patient\n");
        printf("3. Display All Patients\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addPatient(); break;
            case 2: searchPatient(); break;
            case 3: displayAll(); break;
            case 4: updatePatient(); break;
            case 5: deletePatient(); break;
            case 6: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

// ADD PATIENT
void addPatient() {
    if (count == MAX) {
        printf("Hospital is full! Cannot add more patients.\n");
        return;
    }

    printf("\nEnter Patient ID: ");
    scanf("%d", &p[count].id);

    printf("Enter Patient Name: ");
    scanf("%s", p[count].name);

    printf("Enter Age: ");
    scanf("%d", &p[count].age);

    printf("Enter Disease: ");
    scanf("%s", p[count].disease);

    count++;
    printf("Patient added successfully!\n");
}

// SEARCH PATIENT
void searchPatient() {
    int id, found = 0;
    printf("\nEnter patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("\nPatient Found:\n");
            printf("ID: %d\n", p[i].id);
            printf("Name: %s\n", p[i].name);
            printf("Age: %d\n", p[i].age);
            printf("Disease: %s\n", p[i].disease);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Patient not found.\n");
}

// DISPLAY ALL PATIENTS
void displayAll() {
    if (count == 0) {
        printf("No patients in hospital.\n");
        return;
    }

    printf("\n---- ALL PATIENT RECORDS ----\n");
    for (int i = 0; i < count; i++) {
        printf("\nPatient %d:\n", i + 1);
        printf("ID: %d\n", p[i].id);
        printf("Name: %s\n", p[i].name);
        printf("Age: %d\n", p[i].age);
        printf("Disease: %s\n", p[i].disease);
    }
}

// UPDATE PATIENT
void updatePatient() {
    int id, found = 0;
    printf("\nEnter patient ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("Update name: ");
            scanf("%s", p[i].name);

            printf("Update age: ");
            scanf("%d", &p[i].age);

            printf("Update disease: ");
            scanf("%s", p[i].disease);

            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Patient not found.\n");
}

// DELETE PATIENT
void deletePatient() {
    int id, found = 0;
    printf("\nEnter patient ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            // shift array left
            for (int j = i; j < count - 1; j++) {
                p[j] = p[j + 1];
            }
            count--;
            printf("Patient deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Patient not found.\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char studentID[20];
    int totalMarks;
} Student;

void updateStudentRecord(Student students[], int numStudents, char studentID[], int totalMarks) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].studentID, studentID) == 0) {
            // Update the total marks of the existing student
            students[i].totalMarks = totalMarks;
            return;
        }
    }

    // Add a new student record
    strcpy(students[numStudents].studentID, studentID);
    students[numStudents].totalMarks = totalMarks;
}

int main() {
    FILE *file;
    Student students[MAX_STUDENTS];
    char studentID[20];
    int totalMarks;
    int numStudents = 0;

    // Open the file in append mode to add or update student records
    file = fopen("db.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter student ID: ");
    scanf("%s", studentID);
    printf("Enter total marks: ");
    scanf("%d", &totalMarks);

    // Read the existing student records from the file into the students array
    while (fscanf(file, "%s %d", students[numStudents].studentID, &students[numStudents].totalMarks) != EOF) {
        numStudents++;
    }

    // Update or add the new student record in the students array
    updateStudentRecord(students, numStudents, studentID, totalMarks);

    // Clear the file content
    freopen("db.txt", "w", file);

    // Write the updated student records to the file
    for (int i = 0; i < numStudents + 1; i++) {
        fprintf(file, "%s %d\n", students[i].studentID, students[i].totalMarks);
    }

    // Close the file
    fclose(file);

    printf("Student record saved successfully.\n");

    return 0;
}

#include <stdio.h>

#define MAX_STUDENTS 100

struct CT {
    char id[20];
    char name[50];
    int ct1_marks;
    int ct2_marks;
};

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct CT students[MAX_STUDENTS];

    printf("Enter Id no., name, CT-1 marks, CT-2 marks for %d students:\n", numStudents);
    for (int i = 0; i < numStudents; ++i) {
        scanf("%s %s %d %d", students[i].id, students[i].name, &students[i].ct1_marks, &students[i].ct2_marks);
    }

    printf("Maximum marks of each student:\n");
    for (int i = 0; i < numStudents; ++i) {
        int max_marks = (students[i].ct1_marks > students[i].ct2_marks) ? students[i].ct1_marks : students[i].ct2_marks;
        printf("%s: %d\n", students[i].id, max_marks);
    }

    return 0;
}

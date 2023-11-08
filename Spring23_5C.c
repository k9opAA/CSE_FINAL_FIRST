#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of students (n): ");
    scanf("%d", &n);

    FILE *file = fopen("CSE-1121.txt", "w");

    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return 1;
    }

    printf("Enter the final marks of %d students:\n", n);

    for (int i = 0; i < n; i++) {
        int marks;
        scanf("%d", &marks);
        fprintf(file, "%d\n", marks);
    }

    fclose(file);

    file = fopen("CSE-1121.txt", "r");

    if (file == NULL) {
        printf("Failed to open the file for reading.\n");
        return 1;
    }

    printf("Final marks of %d students:\n", n);

    int marks;
    while (fscanf(file, "%d", &marks) == 1) {
        printf("%d\n", marks);
    }

    fclose(file);

    return 0;
}


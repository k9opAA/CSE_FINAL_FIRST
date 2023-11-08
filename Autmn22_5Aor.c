#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of values : ");
    scanf("%d", &n);

    FILE *file = fopen("numbers.txt", "w");

    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        fprintf(file, "%d\n", num);
    }

    fclose(file);

    file = fopen("numbers.txt", "r");

    if (file == NULL) {
        printf("Failed to open the file for reading.\n");
        return 1;
    }

    printf("Numbers in reverse order:\n");
    
    int numbers[n];
    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &numbers[i]) == 1) {
        } else {
            printf("Error reading from the file.\n");
            break;
        }
    }

    fclose(file);

    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}

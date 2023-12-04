#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;
    char buffer[1000];
    int length, i;

    // Open the input file for reading
    inputFile = fopen("copy.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the output file for writing
    outputFile = fopen("clone.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Read the content of the input file into a buffer
    length = fread(buffer, sizeof(char), 1000, inputFile);

    // Write the content of the buffer in reverse order to the output file
    for (i = length - 1; i >= 0; i--) {
        fwrite(&buffer[i], sizeof(char), 1, outputFile);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("File copied and reversed successfully.\n");

    return 0;
}

#include <stdio.h>

struct BookInfo
{
    char title[100];
    char author[50];
    double price;
};

int main()
{
    int n;

    printf("Enter the number of books (n): ");
    scanf("%d", &n);

    struct BookInfo books[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter information for book %d:\n", i + 1);

        printf("Title: ");
        scanf(" %[^\n]", books[i].title);
        
        printf("Author's Name: ");
        scanf(" %[^\n]", books[i].author);

        // Input price
        printf("Price: ");
        scanf("%lf", &books[i].price);
    }

    printf("Book Information:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author's Name: %s\n", books[i].author);
        printf("Price: %.2lf\n", books[i].price);
        printf("\n");
    }

    return 0;
}


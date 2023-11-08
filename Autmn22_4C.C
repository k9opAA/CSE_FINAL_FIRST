#include <stdio.h>
#include <string.h>

struct Player
{
    char name[24];
    char country[24];
    int match_played;
    int goals;
    double pass_accuracy;
};

int H_goals(struct Player ar[], int n)
{
    int maxGoals = -1;
    int pos = -1;

    for (int i = 0; i < n; i++)
    {
        if (ar[i].goals > maxGoals)
        {
            maxGoals = ar[i].goals;
            pos = i;
        }
    }

    return pos;
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Player ar[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", ar[i].name);
        scanf("%s", ar[i].country);
        scanf("%d", &ar[i].match_played);
        scanf("%d", &ar[i].goals);
        scanf("%lf", &ar[i].pass_accuracy);
    }

    int mostGoalsPlayer = H_goals(ar, n);

    if (mostGoalsPlayer != -1)
    {
        printf("Player with the most goals:\n");
        printf("Name: %s\n", ar[mostGoalsPlayer].name);
        printf("Country: %s\n", ar[mostGoalsPlayer].country);
    }
    else
    {
        printf("No players found.\n");
    }

    return 0;
}

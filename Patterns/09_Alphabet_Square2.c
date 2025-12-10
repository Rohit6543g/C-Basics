#include <stdio.h>

int main()
{
    int n;

    printf("Enter the size of the square (max size = 26): ");
    scanf("%d", &n);

    if (n < 1 || n > 26)
    {
        printf("Invalid size. Please enter a number between 1 and 26.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", 65 + j);
        }
        printf("\n");
    }

    return 0;
}
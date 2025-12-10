#include <stdio.h>

int main()
{
    int n;

    printf("Enter the size of the triangle (max size = 52): ");
    scanf("%d", &n);

    if (n < 1 || n > 52)
    {
        printf("Invalid size. Please enter a number between 1 and 52.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i % 2 == 0)
                printf("%d ", j + 1);
            else
                printf("%c ", 65 + j);
        }
        printf("\n");
    }

    return 0;
}
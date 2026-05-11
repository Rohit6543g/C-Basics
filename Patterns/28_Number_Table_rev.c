#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter the size of the table: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%d ", j + 1);
        }
        for (int j = 0; j < (2 * i - 1); j++)
        {
            printf("  ");
        }
        for (int j = 0; j < n - i; j++)
        {
            if (i == 0 && j == 0)
                continue;
            printf("%d ", n - i - j);
        }
        printf("\n");
    }

    return 0;
}
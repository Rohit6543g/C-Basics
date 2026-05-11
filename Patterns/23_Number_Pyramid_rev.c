#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter the size of the pyramid: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            printf("  ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("%d ", j + 1);
        }
        for (int j = 0; j < i; j++)
        {
            printf("%d ", i - j);
        }
        printf("\n");
    }

    return 0;
}
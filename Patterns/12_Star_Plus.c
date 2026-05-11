#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the star: ");
    scanf("%d", &n);

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (i == n - 1 || j == n - 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}
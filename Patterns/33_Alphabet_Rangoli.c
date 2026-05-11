#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;

    printf("Enter number of size of the rangoli: ");
    scanf("%d", &n);

    int size = 2 * n - 1;
    int mid = n - 1;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (abs(i - mid) + abs(j - mid) <= mid)
                printf("%c ", 'A' + (abs(i - mid) + abs(j - mid)));
            else
                printf("  ");
        }
        printf("\n");
    }

    return 0;
}
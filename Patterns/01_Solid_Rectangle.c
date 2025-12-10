#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter the length of rectangle: ");
    scanf("%d", &m);
    printf("Enter the breadth of rectangle: ");
    scanf("%d", &n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
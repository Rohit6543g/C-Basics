#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", abs(n / 2 - i) + abs(n / 2 - j));
        }
        printf("\n");
    }

    return 0;
}

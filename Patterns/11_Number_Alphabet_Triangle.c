#include <stdio.h>

int main()
{
    int n;
    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                    'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                    'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    printf("Enter the size of the triangle (max size = 104): ");
    scanf("%d", &n);
    if (n < 1 || n > 104)
    {
        printf("Invalid size. Please enter a number between 1 and 104.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i % 2 == 0)
                printf("%d ", j + 1);
            else
                printf("%c ", alpha[j]);
        }
        printf("\n");
    }

    return 0;
}
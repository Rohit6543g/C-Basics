#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    int size = (2 * n) - 1;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int top = i, left = j;
            int bottom = size - i - 1, right = size - j - 1;
            int min = top;

            if (left < min)
                min = left;
            if (bottom < min)
                min = bottom;
            if (right < min)
                min = right;

            if (i == min || j == min || i == size - 1 - min || j == size - 1 - min)
                printf("%2d ", n - min);
            else
                printf("   ");
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter the size of the zoom: ");
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

            printf("%2d ", min);
        }
        printf("\n");
    }

    return 0;
}

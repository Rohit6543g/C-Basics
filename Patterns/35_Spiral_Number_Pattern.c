#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the spiral: ");
    scanf("%d", &n);

    int arr[n][n];
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right)
    {
        // Top row
        for (int j = left; j <= right; j++)
            arr[top][j] = num++;
        top++;

        // Right column
        for (int i = top; i <= bottom; i++)
            arr[i][right] = num++;
        right--;

        // Bottom row
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
                arr[bottom][j] = num++;
            bottom--;
        }

        // Left column
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                arr[i][left] = num++;
            left++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%3d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}

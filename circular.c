/*Given a 2D array, print it in a circular manner.*/
#include <stdio.h>
#include <stdlib.h>

void printSpiral(int rows, int cols, int matrix[rows][cols])
{
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            printf("%d ", matrix[top][i]);
        }
        top++;

        for (int j = top; j <= bottom; j++)
        {
            printf("%d ", matrix[j][right]);
        }
        right--;

        for (int k = right; k >= left; k--)
        {
            printf("%d ", matrix[bottom][k]);
        }
        bottom--;

        for (int m = bottom; m >= top; m--)
        {
            printf("%d ", matrix[m][left]);
        }
        left++;
    }
}
int **mult(int n, int m, int m1[n][m], int m2[m][n], int ans[n][n], int i, int j)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int s = 0; s < m; s++)
            {
                ans[i][j] += m1[i][s] * m2[s][j];
            }
        }
    }
}
// move all even elements to right
void move(int n, int arr[n])
{
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            pos = i;
            break;
        }
    }
    for (int j = pos + 1; j < n; j++)
    {
        if (arr[j] % 2 != 0)
        {
            int temp = arr[pos];
            arr[pos] = arr[j];
            arr[j] = temp;
            pos = j;
        }
    }
}
void consec(int n, int arr[], int tar)
{
    int cp1 = tar;
    for (int j = n - 1; j >= 0; j++)
    {

        int cp2 = arr[j];
        while (cp1 > 0 && cp2 > 0)
        {
            if (cp2 % 10 != cp1 % 10)
            {
                break;
            }
            else
            {
                cp2 = cp2 / 10;
                cp1 = cp1 / 10;
            }
        }
        if (cp1 == 0)
            break;
        if (cp2 != 0)
        {
            cp1 = tar;
        }
    }
    if (cp1 == 0)
    {
        print("found");
    }
}
int main()
{
    int n = 4, m = 4;
    int arr[n][m];

    int val = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = val++;
        }
    }

    printSpiral(n, m, arr);
}
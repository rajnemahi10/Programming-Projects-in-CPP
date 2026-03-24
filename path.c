/*Given a matrix of 0s and 1s, find if there exists a path of 1s from the left-top corner (that is, matrix[0][0]) to the
 bottom-right corner. The only moves supported are moving in the same row or same column (and not diagonally).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int printPath(char *path, int **arr, int i, int j, int pathSize, int n, int m) // right -r, down -d
{
    if (i >= n || j >= m)
        return 0;
    if ((i == n - 1 && j == m - 1) ||
        (i == n - 1 && j == m - 1))
    {
        printf("%s\n", path);

        return 1;
    }

    if (arr[i][j] == 0)
        return 0;

    path[pathSize] = 'r';
    int checkRight = printPath(path, arr, i, j + 1, pathSize + 1, n, m);
    path[pathSize] = 'd';
    int checkDown = printPath(path, arr, i + 1, j, pathSize + 1, n, m);

    if (!checkDown && !checkRight)
    {
        return 0;
    }
    return 1;
}
int main()
{
    int n = 3;
    int m = 3;
    int **arr = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = malloc(m * sizeof(int));
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = 0; // start with all zeros
        }
    }

    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[0][2] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    arr[2][1] = 1;
    arr[2][2] = 1;

    char *path = malloc(sizeof(char) * 1000);
    int a = printPath(path, arr, 0, 0, 0, n, m);
}

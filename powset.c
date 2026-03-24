#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate(char *arr, char *ans, int arrIndex, int ansIndex)
{
    if (arrIndex == 3)
    {
        ans[ansIndex] = '\0';
        printf("%s\n", ans);
        return;
    }

    // exclude
    generate(arr, ans, arrIndex + 1, ansIndex);

    // include
    ans[ansIndex] = arr[arrIndex];
    generate(arr, ans, arrIndex + 1, ansIndex + 1);
}
void gen(char *arr, int i, char *ans, int *dup)
{
    if (i == 3)
    {
        ans[3] = '\0';
        printf("%s\n", ans);
        return;
    }
    for (int j = 0; j < 3; j++)
    {
        if (dup[j] == 0)
        {
            ans[i] = arr[j];
            dup[j] = 1;
            gen(arr, i + 1, ans, dup);
            dup[j] = 0;
        }
        }
}
FILE * fp=fopen("file");
int day;
char str[10000];
for(int i=0;i<day;i++)
{
    fgets(str,10000,fp);
}
printf("%s",str);

int main()
{
    char arr[3] = "abc";
    char ans[4] = "";
    int dup[3] = {0};
    gen(arr, 0, ans, dup);
}
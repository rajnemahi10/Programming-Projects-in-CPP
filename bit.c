#include <stdio.h>
#include <stdlib.h>

void base_n(int n, int num)
{
    if (num == 0)
        return;

    base_n(n, num / n);
    printf("%d", num % n);
}
void nonrec(int n, int num)
{
    int i;
    for (i = n;; i *= n)
    {
        if (num / i == 0)
            break;
    }
    i /= n;
    while (num != 0)
    {
        if (num >= i)
        {
            int j;
            for (j = 1; j < n; j++)
            {
                if (num - j * i < 0)
                    break;
            }
            j -= 1;
            num -= j * i;
            printf("%d", j);
        }
        else
        {
            printf("%d", 0);
        }
        i /= n;
    }
}
//arr={a,b}
//ans={aaa}
void odom(int n,char arr[],char ans[])
{
    printf("%s\n",ans);
    for(int i=n-2;i>=0;i--)
    {
        if(ans[i]=='a')
        {
            ans[i]='b';
            for(int j=n-2;j>i;j--)
                ans[j]='a';
            odom(n,arr,ans);
        }
    }
    return;
}
char* covertToBinary(int n, int num)
{
    char arr[255];
    int index=0;
    int i;
    for (i = n;; i *= n)
    {
        if (num / i == 0)
            break;
    }
    i /= n;
    while (num != 0)
    {
        if (num >= i)
        {
            int j;
            for (j = 1; j < n; j++)
            {
                if (num - j * i < 0)
                    break;
            }
            j -= 1;
            num -= j * i;
            arr[index]=1;
            index++;
        }
        else
        {
            arr[index]=0;
            index++;
        }
        i /= n;
    }
    return arr;
}
//constraints - lower case and space
//unsigned long arr[255]={0};
void tut_store(int size,char *sentence,unsigned long arr[])
{
    
   
    int pad=0;//to handle 5 bits
    int ptr=0;
    for(int i=0;i<size;i++)
    {
        //handling length(each element of arr can store at max 12 letters)
        if(i!=0 && i%12==0)
        {
            ptr++;
            pad=0;
        }
        if(sentence[i]!=' '){
            arr[ptr]=arr[ptr]|((sentence[i]-'a'+1)<<pad);
            pad+=5;
        }
        //storing ' ' as 27
        else
        {
            arr[ptr]=arr[ptr]|(27<<pad);
            pad+=5;
        }
    }
    
    

}
void tut_print(unsigned long *arr, int size)
{
    int pad;
    int index = 0;
    char finalans[3000];

    for(int i = 0; i < size; i++)
    {
        pad = 0;

        while((arr[i] >> pad) != 0)
        {
            int n = (arr[i] >> pad) & 31;

            if(n > 0 && n < 27)
            {
                finalans[index++] = (char)(n + 'a' - 1);
            }
            else if(n == 27)
            {
                finalans[index++] = ' ';
            }

            pad += 5;
        }
    }

    finalans[index] = '\0';

    printf("%s\n", finalans);
}
int main()
{
    char ans[4]="aaa";
    char arr[3]="ab";
    odom(4,arr,ans);
    // base_n(2, 111);
    //nonrec(3, 5);
}
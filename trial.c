#include<stdio.h>
#include<string.h>

int main()
{
	FILE * fp=fopen("text.txt","r");
	int N=1;
	char ch=fgetc(fp);
	for(int i=0;i<N;i++)
	{
		do{
			if(ch==EOF)
			{
				printf("N is too large");
				return 0;
			}
			if(ch=='\n')
				break;
			
			ch=fgetc(fp);
		}while(ch!='\n');
	}
	ch=fgetc(fp);
	
	while(ch!='\n' && ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp);
	}
	fclose(fp);
}

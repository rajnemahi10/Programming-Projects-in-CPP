#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint64_t insert(uint64_t var,int index,int no,int K)
{
	uint64_t mask=0;
	uint64_t mult=1;
	for(int i=0;i<K;i++)
	{
		mask+=mult;
		mult*=2;
	}
	uint64_t n=mask<<(K*index);
	n=~n;
	int bitmask=no<<(index*K);
	var=(var&n)|bitmask;
	return var;
}


int search(uint64_t var,int no,int K)
{
	uint64_t bitmask=0;
	uint64_t mult=1;
	for(int i=0;i<K;i++)
	{
		bitmask+=mult;
		mult*=2;
	}
	int index=0;
	int count=0;
	while(count<64/K)//checks exactly 64/K integers
	{
		int check=var&bitmask;
		if(check==no)
		{
			printf("%d\n",index);
			return index;
		}
		index++;
		var=var>>K;
		count++;
	}
	printf("%d",-1);
	return -1;
}
void printAll(uint64_t var,int K)
{
	uint64_t bitmask=0;
	uint64_t mult=1;
	for(int i=0;i<K;i++)
	{
		bitmask+=mult;
		mult*=2;
	}
	int index=0;
	while(index<64/K)
	{
		uint64_t p=(var & bitmask);
		printf("%lu\n",p);
		var=var>>K;
		index++;
	}
}
uint64_t lShift(int K,uint64_t var,int index, int shift)
{

	uint64_t mask=0;
	uint64_t mult1=1;
	for(int i=0;i<K;i++)
	{
		mask+=mult1;
		mult1*=2;
	}
	uint64_t n=mask<<(K*index);
	uint64_t r=(var&n)>>(K*index);
	uint64_t m=r<<shift;
	uint64_t ntoinsert=0;
	uint64_t mult=1;
	for(int i=0;i<K;i++)
	{
		ntoinsert+=mult*(m&1);
		mult*=2;
		m=m>>1;
	}
	var=insert(var,index,ntoinsert,K);
	return var;
	
}

uint64_t rShift(int K,uint64_t var,int index, int shift)
{

	uint64_t mask=0;
	uint64_t mult1=1;
	for(int i=0;i<K;i++)
	{
		mask+=mult1;
		mult1*=2;
	}
	uint64_t n=mask<<(K*index);
	uint64_t r=(var&n)>>(K*index);
	uint64_t m=r>>shift;
	uint64_t ntoinsert=0;
	uint64_t mult=1;
	for(int i=0;i<K;i++)
	{
		ntoinsert+=mult*(m&1);
		mult*=2;
		m=m>>1;
	}
	var=insert(var,index,ntoinsert,K);
	return var;
	
}
uint64_t add(int K,uint64_t var,int index,int no)
{

	uint64_t mask=0;
	uint64_t mult1=1;
	for(int i=0;i<K;i++)
	{
		mask+=mult1;
		mult1*=2;
	}
	uint64_t n=mask<<(K*index);
	uint64_t r=(var&n)>>(K*index);
	r+=(uint64_t)(no);

	uint64_t ntoinsert=0;
	uint64_t mult=1;
	for(int i=0;i<K;i++)
	{
		ntoinsert+=mult*(r&1);
		mult*=2;
		r=r>>1;
	}
	var=insert(var,index,ntoinsert,K);
	return var;
}
uint64_t convertToDecimal(uint64_t no)
{
    uint64_t n=0;
    uint64_t mult=1;
    while(no!=0)
    {
        n+=mult*(no%10);
        no=no/10;
        mult*=2;
    }
    return n;
}



// uint64_t  <- data type for 64 bit int
int main() {
	uint64_t var=0;//64 bit no  
	int K;//how many bits per no 
	char query[1000];
	scanf("%d",&K);
	while(scanf("%s",query)!=-1)
	{
        
		int index;
		uint64_t no;
		int shift;

		if(strcmp(query,"insert")==0)
		{
			scanf("%d %lu",&index,&no);
            int n=convertToDecimal(no);
			var=insert(var,index,n,K);
		}
		else if(strcmp(query,"search")==0)
		{
			scanf("%lu",&no);
            int n=convertToDecimal(no);
			search(var,n,K);
		}
		else if(strcmp(query,"lShift")==0)
		{
			scanf("%d %d",&index,&shift);	
			var=lShift(K,var,index,shift);
		}
       		
		else if(strcmp(query,"rShift")==0)
		{
			scanf("%d %d",&index,&shift);	
			var=rShift(K,var,index,shift);
		}
		else if(strcmp(query,"add")==0)
		{
			scanf("%d %lu",&index,&no);	
            int n=convertToDecimal(no);
			var=add(K,var,index,n);
		}
		else if(strcmp(query,"printAll")==0)
		{
			printAll(var,K);
		}
}
}
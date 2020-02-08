#include<stdio.h>
#include<stdlib.h>

void NRZ_L(int *str1,int *str2, int n)
{
	printf("NRZ_L:\t");
	for(int i=0;i<n;i++)
	{
		str2[i]=str1[i];
		printf("%d ", str2[i]);
	}
	printf("\n");
}

void NRZ_I(int *str1,int *str2, int n)
{	
	str2[-1]=1;
	printf("NRZ_I:\t");
	for(int i=0;i<n;i++){
		if(str1[i]) str2[i]=!str2[i-1];
		else str2[i]=str2[i-1];
		printf("%d ", str2[i]);
	}
	printf("\n");
}

void RZ(int *str1,int n)
{
	int *str2 = (int *)malloc(2*n);
	printf("RZ:\t|");
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(str1[i]) str2[j]=1;
		else str2[j]=-1;
		str2[j+1]=0;
		j+=2;
	}
	for(j=0;j<2*n; j++)
	{
		printf("%d ", str2[j]);
		if(j%2!=0) printf("|");
	}
	printf("\n");
		
}

void manchester(int *str1,int *clk, int n)
{
	//int *str = (int *)malloc(2*n);
	int str[2*n];
	int j=0;
	for(int i=0;i<n;i++)
	{
		str[j]=clk[j]^str1[i];
		str[j+1]=clk[j+1]^str1[i];
		j+=2;
	}
	printf("Man:\t|");
	for(j=0;j<2*n; j++)
        {
                printf("%d ", str[j]);
                if(j%2!=0) printf("|");
        }
        printf("\n");

}


int main()
{
	int str1[100]={},str2[100]={}, n=10, len,i=0,j=0, count=0;
	printf("Enter input bit stream of 10 bits:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &str1[i]);
	}

	int clk[2*n];
	for(int i=0;i<2*n;i++)
	{
		if(i%2==0) clk[i]=1;
		else clk[i]=0;
	}

	NRZ_L(str1,str2,n);
	NRZ_I(str1,str2,n);
	RZ(str1,n);
	manchester(str1,clk,n);
	return 0;
}

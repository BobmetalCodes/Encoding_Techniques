/* to be done*/
#include<stdio.h>
#include<string.h>

int main(){
	int str[100],n=16,i=0,j=0,count=1;	//count start from 1 because logic
	printf("Enter the input bit stream one by one:\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d", &str[i]);
	}

	/************ Logic ************/

	for(i=0;i<n;i++)
	{
		if(count==5){
			count=1;
			n+=1;
			i++;
			j=i;
			for(j=n-1;j>=i;j--)
			{
				str[j]=str[j-1];
			}
			str[i]=!str[i-1];
		}
		if(str[i]==str[i+1])
		{
			count++;
		}
		else count=1;
	}

	printf("OP: \n");
	for(i=0;i<n;i++)
	{
		printf("%d  ", str[i]);
	}
	printf("\n");

}

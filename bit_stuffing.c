#include<stdio.h>
#include<string.h>

int main(){
	int str[100],n=16,i=0,j=0,count=1;	//count start from 1 because logic
	printf("Enter the input bit stream one by one:\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d", &str[i]);
	}

	for(i=1;i<n;i++){			//loop from 1 as i-1 is checked
		if(str[i]==str[i-1])
		{
			count++;		//inc count for match

			if(count==6)		//6 successive
			{	count = 1;	//reset count
				n+=1;		//inc array size
				j=i;		//save i for storing stuff bit
				for(j=n-1;j>=i;j--)	//start from last and shift ahead from 6th including 6th repeating bit
				{
					str[j]=str[j-1];
				}
				str[i]=!str[i-1];	//stuff bit at 6th position
			}
		}
		else count = 1;				//reset count
	}

	printf("OP: \n");
	for(i=0;i<n;i++)
	{
		printf("%d  ", str[i]);
	}
	printf("\n");

}

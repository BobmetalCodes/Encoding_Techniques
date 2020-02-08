/* adds 0 after five 1s and 1 after five 0s including stuff bit*/ 
#include<stdio.h>
#include<string.h>

int main(){
	int str1[100],str2[100],n=16,i=0,j=0,count=1;	//count start from 1 because logic
	printf("Enter the input bit stream one by one:\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d", &str1[i]);
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
				str1[j]=str1[j-1];
			}
			str1[i]=!str1[i-1];
		}
		if(str1[i]==str1[i+1])
		{
			count++;
		}
		else count=1;
	}

	printf("Bit stuffed OP: \n");
	for(i=0;i<n;i++)
	{
		printf("%d  ", str1[i]);
	}
	printf("\n");


	/********* Decoder ************/
        for(i=0;i<n;i++)
        {
                if(count==5){
                        count=1;
                       // n+=1;
                        i++;
                        j=i;
                        for(j=i;j<n-1;j++)
                        {
                                str1[j]=str1[j+1];
                        }
			n-=1;
                }
                if(str1[i]==str1[i+1])
                {
                        count++;
                }
                else count=1;
        }

	
	printf("Decoded stream OP: \n");
	for(i=0;i<n;i++)
	{
		printf("%d  ", str1[i]);
	}
	printf("\n");
}

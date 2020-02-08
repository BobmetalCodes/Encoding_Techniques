/* adds 0 after five 1s and 1 after five 0s including stuff bit*/ 
#include<stdio.h>
#include<string.h>

int main(){
	int str1[100],n=16,i=0,j=0,count=1;	//count start from 1 because logic
	printf("Enter the input bit stream one by one:\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d", &str1[i]);
	}

	/************ Logic ************/

	for(i=0;i<n;i++)
	{
		if(count==5){				//check for 5 repeating on entering loop
			count=1;			//reset count
			n+=1;				//make space for stuff bit
			i++;				//move to where to stuff
			j=i;				//temp variable for shifting
			for(j=n-1;j>=i;j--)
			{
				str1[j]=str1[j-1];	//shift elements ahead one by one for stuff space
			}
			str1[i]=!str1[i-1];		//Store stuff bit, !(repeating bit val)
		}
		if(str1[i]==str1[i+1])			
		{
			count++;			//inc count for repeating
		}
		else count=1;				//if repeat pattern broken, reset count
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
                if(count==5){				//count 5 repeats
                        count=1;			//reset
                       // n+=1;
                        i++;				//move to stuffed bit
                        j=i;
                        for(j=i;j<n-1;j++)
                        {
                                str1[j]=str1[j+1];	//shift array behind to overwrite stuff bit
                        }
			n-=1;				//reduce array size to original
                }
                if(str1[i]==str1[i+1])
                {
                        count++;			//check for repeat
                }
                else count=1;				//reset if pattern of repeat broken
        }

	
	printf("Decoded stream OP: \n");
	for(i=0;i<n;i++)
	{
		printf("%d  ", str1[i]);
	}
	printf("\n");
}

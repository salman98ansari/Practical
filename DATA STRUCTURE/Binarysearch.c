//IMPLEMENTATION OF BINARY SEARCH
// ANSARI MOHD SALMAN
// 16CO20


#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

int binary_search(int a[],int n,int x)
{
	int mid=n/2;
	int high=n-1,low=0;
	while(high>=low)
	{
		if(a[mid]==x)
			return mid;
			if(x>a[mid])
				low=mid+1;
			else
				high=mid-1;
			mid=(low+high)/2;
	}
	return -1;
}
int main()
{
	int i,a[MAXSIZE],no,choice,x;
	printf("ENTER THE NO OF ELEMENTS :: ");
	scanf("%d",&no);
	printf("ENTER THE ELEMENTS OF AN ARRAY IN ASCENDING ORDER :: \n");
	for(i=0;i<no;i++)
		scanf("%d",&a[i]);
	
	do
	{
		printf("\nENTER\n1.DISPLAY\n2.SEARCH\n3.EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nTHE ELEMENTS OF AN ARRAY IS ::\n");
				for(i=0;i<no;i++)
					printf("%d\n",a[i]);
				break;
			case 2:
				printf("THE NO YOU WANT TO SEARCH::");
				scanf("%d",&x);
				if(binary_search(a,no,x)!=-1)
					printf("\nELEMENT FOUND AT %dth INDEX",binary_search(a,no,x));
				else 
					printf("\nTHE ELEMENT IS NOT FOUND");
				break;
			case 3:
				exit(0);
			default:
				printf("INVALID CHOICE!!\n");
				break;		
		}
	}while(1);
}

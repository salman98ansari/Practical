#include<stdio.h>

void knapsack(int n, float profit[], float weight[], float capacity)
{
	int i;
	float tp=0,u,partialFrac[10];
	u=capacity;
	
	for(i=0;i<n;i++)
	{
		if(weight[i]>u)
			break;
		else
		{
			partialFrac[i]=1.0;
			tp=tp+profit[i];
			u=u-weight[i];
		}
	}
	
	if(i<n)
	{
		partialFrac[i]=u/weight[i];
		tp=tp+(partialFrac[i]*profit[i]);
		
		for(i=0;i<n;i++)
		{
			printf("The fraction of object %d is %f \n",i+1,partialFrac[i]);
		}
			printf("The total profit is %f\n",tp);
	}
}

int main()
{
	float weight[20],profit[20],ratio[20],temp,capacity;
	int num,i,j;
	printf("Enter no. of objects\n");
	scanf("%d",&num);
	printf("Enter available capacity\n");
	scanf("%f",&capacity);
	printf("Enter Profit and Weight of objects\n");
	for(i=0;i<num;i++)
	{
		scanf("%f%f",&profit[i], &weight[i]);
	}
	for(i=0;i<num;i++)
	{
		ratio[i]=profit[i]/weight[i];
	}
	
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(ratio[i]<ratio[j])
			{
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;
				
				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
				
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp; 
			}
		}
	}
	knapsack(num,profit,weight,capacity);
	return 0;
}

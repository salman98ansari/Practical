/*Title: Longest Common Subsequence
 * Description: To Implement LCS Algorithm usind Dynammic Programmic Technique Approach
 * Student Name: Ansari Mohd Salman
 * Roll No:16CO20
 */
#include<stdio.h>
#include<string.h>
#define MAX 10

 
int LCS(int c,int r,char *X,char *Y)
{
	int i,j,l[r+1][c+1];
	for(i=0;i<=r;i++)    
	{
		for(j=0;j<=c;j++)
		{
			if(i==0||j==0)                     
				l[i][j]=0;      //first row and column
			else
			{
				if(X[i-1]==Y[j-1])                          
					l[i][j]=l[i-1][j-1]+1; //for match
				else
					l[i][j]=max(l[i][j-1],l[i-1][j]); //for not match
			}
		}
	}
	return l[r][c];
}

int max(int x,int y)
{
  return ((x>y)?x:y);   //Checking max using Function
}


int main()
{
int c,r;
char x[MAX],y[MAX];
printf("Enter the String X : ");
scanf("%s",x);
printf("Enter the String Y : ");
scanf("%s",y);
r=strlen(x);
c=strlen(y);
int a=LCS(c,r,x,y);                               
printf("LCS= %d",a);
	
}



/*
 * OUTPUT
 * 
 * Enter the String X :BDCABA
 * Enter the String X :ABCBDAB
 * LCS= 4
 * 
 * -------------------
 * */
 


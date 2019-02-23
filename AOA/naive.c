/*
 * Name:Ansari Mohd Salman
 * Roll No:16CO20
 * Title: To implement naive String Algoritm;
 * */

#include <stdio.h>
#include <string.h>

int match(char [], char []);

int main()
{
	char a[100],b[100];
	int position;
	
	printf("Enter Text String\n");
	gets(a);
	
	printf("Enter Pattern to be found\n");
	gets(b);
	
	position=match(a,b);
	
	if(position==-1)
	{
		printf("pattern Not Found");
	}
	else
	{
		printf("\n Pattern Found at %d",position +1);
	}
	
	return 0;
	
}
			
	

int match(char text[],char pattern[])
{
	int c,d,e,text_length,pattern_length,position;
	
	text_length=strlen(text);
	pattern_length=strlen(pattern);
	
	if(pattern_length > text_length)
	{
		return -1;
	}
	
	for(c = 0; c <= text_length - pattern_length; c++)
	{
		position=e=c;
		
		for(d = 0; d < pattern_length; d++)
		{
			if (pattern[d] == text[e])
			{
				e++;
			}
			else
			{
				break;
			}
		}
		
		 if (d == pattern_length)
		  {
				
				return position;
		  }
	  }
 
  return -1;
}

/*
 * Enter Text String
Salman Ansari
Enter Pattern to be found
Ansari

 Pattern Found at 8

------------------
* 
* Enter Text String
Salman Ansari
Enter Pattern to be found
hey 
pattern Not Found

------------------

(program exited with code: 0)
Press return to continue
*/

	

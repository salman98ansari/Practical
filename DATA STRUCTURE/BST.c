#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
	int data;
	struct bst *left,*right;
}node;

void traverse_inorder(node *q)
{
	if(q!=NULL)
	{
		traverse_inorder(q->left);
		printf("%d\t",q->data);
		traverse_inorder(q->right);
	}
}
void insert(node **r,int num)
{
	node *temp,*ptr;
	temp=*r;
	if(temp==NULL)
	{
		ptr=(node*)malloc(sizeof(node));
		ptr->data=num;
		ptr->left=NULL;
		ptr->right=NULL;
		*r=ptr;
	}
	else
	{
		if(num > temp->data)
				insert(&temp->right,num);
		else
				insert(&temp->left,num);
	}
}
int search(node *q,int num)
{
	if(q==NULL)
	{
		return -1;
	}
	else
	{
		if( q->data==num)
			return 1;
		else
		{
			if(num>q->data)
				return search(q->right,num);
			else
				return search(q->left,num);
		}
	}
}

void search_node(node **x,node *root,node **parent,int num,int *f)
{
	node *temp;
	temp=root;
	if(temp==NULL)
		return;
	while(temp!=NULL)
	{	
		if(temp->data==num)
		{
			*f=1;
			*x=temp;
			return;
		}
		*parent=temp;
		if(num>temp->data)
			temp=temp->right;
		else
			temp=temp->left;
	}
}
void delete(node **q,int num)
{
	node *temp,*parent,*xsucc,*x;
	int f=0;
	parent=NULL;
	x=NULL;
	xsucc=NULL;
	temp=*q;
	search_node(&x,temp,&parent,num,&f);
	if(f==0)
	{
		printf("\n THE GIVEN NUMBER %d IS NOT FOUND",num);
		return;
	}
	//x has no child
	if((x->left==NULL) && (x->right==NULL))
	{
		if(x->data > parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
	}
	//x has left child
	else if((x->left!=NULL) && (x->right==NULL))
	{
		if(x->data > parent->data)
			parent->right=x->left;
		else
			parent->left=x->left;
	}
		//x has right child
	else if((x->right!=NULL) && (x->left==NULL))
	{
		printf("\nbefore %d\n",parent->data);
		if(x->data > parent->data)
			parent->right=x->right;
		else
			parent->left=x->right;
	}	
			//x has both left and right  child
	else if(x->left!=NULL && x->right!=NULL)
	{
		parent=x;
		xsucc=x->right;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		x->data=xsucc->data;
		x=xsucc;
		if(x->data > parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;		
	}
	
	free(x);
}
int main()
{
	node *root;
    int c,n,e,d,s,i;
	root=NULL;
	do
	{
		printf("\t\tENTER\n1.INSERT\n2.DELETE\n3.SEARCH\n4.TRAVERSE INORDER\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("\nENTER HOW MANY NO YOU WANT TO INSERT\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					scanf("%d",&e);
					insert(&root,e);
				}
				break;
			case 2:
				printf("THE NO YOU WANT TO DELETE : ");
				scanf("%d",&d);
				delete(&root,d);
				break;
			case 3:
				printf("ENTER THE NO YOU WANT TO SEARCH : ");
				scanf("%d",&s);
				if(search(root,s)==1)
					printf("\n THE NUMBER %d IS PRESENT IN THE TREE\n",s);
				else
					printf("\n THE NUMBER %d IS IS NOT FOUND\n",s);
				break;
			case 4:
				traverse_inorder(root);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("INVALID CHOICE!!");
		}
	}while(1);
	return 0;
}

//OUTPUT


/*
 * 		ENTER
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSE INORDER
1

ENTER HOW MANY NO YOU WANT TO INSERT
5
1
2
3
4
5
		ENTER
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSE INORDER
3
ENTER THE NO YOU WANT TO SEARCH : 6

 THE NUMBER 6 IS IS NOT FOUND
		ENTER
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSE INORDER
3
ENTER THE NO YOU WANT TO SEARCH : 5

 THE NUMBER 5 IS PRESENT IN THE TREE
		ENTER
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSE INORDER
2
THE NO YOU WANT TO DELETE : 3

before 2
		ENTER
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSE INORDER



*/

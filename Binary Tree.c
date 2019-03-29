#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild,*rchild;
};
struct node *root=NULL;
void leftinsert(struct node *left)
{
	int k;
	struct node *s,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	/*printf("\nEnter level where you want to insert on left:\t\t");
	scanf("%d",&level);
	*/
	printf("\nEnter data for left child:\t\t");
	scanf("%d",&k);
	ptr->data=k;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	left->lchild=ptr;
}
void rightinsert(struct node *right)
{
	int k;
	struct node *s,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	/*printf("\nEnter level where you want to insert on left:\t\t");
	scanf("%d",&level);
	*/
	printf("\nEnter data for right child:\t\t");
	scanf("%d",&k);
	ptr->data=k;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	right->rchild=ptr;
}
void enter(struct node *start)
{
	int choice;
	struct node *s;
	s=start;
	//ptr=(struct node *)malloc(sizeof(struct node));
	if(s->lchild==NULL&&s->rchild==NULL)
	{
		printf("You can enter data in both left and right child.");
		printf("\n1 to enter in left 2 to enter in right\t\t");
		scanf("%d",&choice);
		if(choice==1)
		leftinsert(s);
		else if(choice==2)
		rightinsert(s);
		else
		printf("WRONG CHOICE");
	}
	else if(s->lchild==NULL&&s->rchild!=NULL)
	{
		printf("\nYou can enter in only left child.\nPress 1 to go down a level via right child anything else to enter in left child.\t\t");
		scanf("%d",&choice);
		if(choice!=1)
		leftinsert(s);
		else
		enter(s->rchild);
	}
	else if(s->lchild!=NULL&&s->rchild==NULL)
	{
		printf("\nYou can enter in only right child.\nPress 1 to go down a level via left child anything else to enter in right child.\t\t");
		scanf("%d",&choice);
		if(choice!=1)
		rightinsert(s);
		else
		enter(s->lchild);
	}
	else
	{
		printf("\nEnter 1 to go down via left child anything else to go down via right child\t\t");
		scanf("%d",&choice);
		if(choice==1)
		enter(s->lchild);
		else
		enter(s->rchild);
	}
}
void pre(struct node *start)
{
	if(start!=NULL)
	{
		printf("%d,",start->data);
		pre(start->lchild);
		pre(start->rchild);
	}
}
void in(struct node *start)
{
	if(start!=NULL)
	{
		in(start->lchild);
		printf("%d,",start->data);
		in(start->rchild);
	}
}
void post(struct node *start)
{
	if(start!=NULL)
	{
		post(start->lchild);
		post(start->rchild);
		printf("%d,",start->data);
	}
}
void display()
{
	int choice;
	struct node *temp=root;
	printf("\nEnter the type of order you want:\n1. Pre-order\n2. In-order\n3. Post-order\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			pre(temp);
			break;
		case 2:
			in(temp);
			break;
		case 3:
			post(temp);
			break;
		default:
			printf("No such order is given here");
	}
}
int main()
{
	int input,choice,k;
	struct node *ptr;
	printf("Enter integer data for root:\t\t");
	scanf("%d",&input);
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=input;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	root=ptr;
	do{
	printf("\nEnter your choice:\n");
	printf("1. Enter data\n2. Print tree data\n3. Exit\t\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			enter(root);
			break;
		case 2:
			display();
			break;
		case 3:
			break;
		default:
			printf("\nYou entered wrong choice");
	}}while(choice!=3);
}

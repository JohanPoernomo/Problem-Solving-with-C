/* Latihan Linked List*/
/* Created by Johan Poernomo*/

/*Library used in this program*/
#include <stdlib.h>
#include <stdio.h>

/* Tipe Bentukan Node*/
struct node
{
	int data;
	struct node *next;
};

/*Variable Global*/
struct node *head;
struct node *head2;

/*=========Daftar Fungsi Pendukung===========*/
void insertfront1 (int x);
void insertfront2 (int x);
void insertnth (int x, int n);
void deletenth(int n);
void concatenate ();
void reverse ();
void print1();
void print2();
/*===========================================*/

/*Program Utama*/
int main()
{	
	int i, n, x;
	printf("Enter number counts 1st linked list : ");
	scanf("%d",&n);
	
	for (i=0;i<n;i++)
	{
		printf ("Enter the number \n");
		scanf("%d",&x);
		insertfront1(x);
		printf("1st Linked List is : "); 
		print1();
	}
	
	printf("Enter number counts 2nd linked list ");
	scanf("%d",&n);
	
	for (i=0;i<n;i++)
	{
		printf ("Enter the number \n");
		scanf("%d",&x);
		insertfront2(x);
		printf("2nd Linked List is : "); 
		print2();
	}
	
	concatenate();
	print1();
	
	return 0;
}

/*Implementasi Fungsi*/
void insertfront1 (int x)
{
	struct node *temp = (node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=head;
	head=temp;
}

void insertfront2 (int x)
{
	struct node *temp = (node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=head2;
	head2=temp;
}

void insertnth (int x, int n)
{
	int i;
	struct node *temp = (node*)malloc(sizeof(struct node));
	struct node *temp2 = (node*)malloc(sizeof(struct node));
	temp=head;
	if (n==1)
	{
		insertfront1(x);
		return;
	}
	
	for (i=1;i<n-1;i++)
	{
		temp=temp->next;
	}
	
	temp2->data=x;
	temp2->next=temp->next;
	temp->next=temp2;
}

void deletenth(int n)
{
	struct node *temp = head;
	if (n==1)
	{
		head = temp->next;
	}
	else if(n==2)
	{
		temp->next = (temp->next)->next;
	}
	else
	{
		for (int i=1;i<=n-2;i++)
		{
			temp=temp->next;
		}
		temp->next=(temp->next)->next;
	}
}

void concatenate ()
{
	if (head->next == NULL)
	{
		head->next = head2;
	}
	
	else
	{
		concatenate();
	}
}

void reverse ()
{
	struct node *tempprev = NULL;
	struct node *temp = head;
	struct node *tempnext;
	while (temp!=NULL)
	{
		tempnext = temp->next;
		temp->next = tempprev;
		tempprev=temp;
		temp=tempnext;
	}
	head=tempprev;
}

void print1()
{
	struct node *temp = head;
	while (temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void print2()
{
	struct node *temp = head2;
	while (temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

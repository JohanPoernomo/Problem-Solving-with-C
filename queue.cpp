//Queue Basic Library Using Circular Array Approach
//Ver 02 May 2018; Arranged by Johan Poernomo

/*-------Library Used-----------*/
#include <stdio.h>
#include <stdlib.h>
#define N 10
/*------------------------------*/

/*-------Global Variable--------*/
int array[N];
int rear = -1;
int front = -1;
/*------------------------------*/

/*-----Function Declaration-----*/
void enqueue(int x);
void dequeue();
int checkfront();
int isEmpty ();
int isFull ();
void print ();
/*------------------------------*/

/*----------Main Program--------*/
int main()
{
	int x;
	printf ("=======Inserting the elements======\n");
	printf ("Please input 99 if you already done\n");
	printf ("===================================\n");
	printf("Input number --> ");
	scanf("%d",&x);
	while ((x!=99) || isFull())
	{
		if (x!=99)
		{
			enqueue(x);
			print();
			printf("\n");
		}
		
		else
		{
			printf("\n");
		}
		printf("Input number --> ");
		scanf("%d",&x);	
	}
	
	return 0;
}
/*------------------------------*/

/*---Function Implementation----*/
void enqueue (int x)
{
	if (isFull()==1)
	{
		printf("Queue is already full");
		return;	
	}
	else if (isEmpty()==1)
	{
		front = rear = 0;
	}
	else
	{
		rear = (rear+1)%N;
	}
	
	array[rear]=x;			
}

void dequeue ()
{
	if (isEmpty()==1)
	{
		printf("The queue is empty");
		return;
	}
	else if (front==rear) // Only 1 element in the queue
	{
		front = rear = -1;
	}
	else 
	{
		front = (front + 1)%N;
	}
}
 
int checkfront ()
{
	return array[front];	
}
int isEmpty ()
{
	if ((rear==-1) && (front==-1))
	{
		return 1;
	}
	
	else
	{
		return 0;
	}	
}

int isFull ()
{
	if ((rear+1)%N == front)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}	
}

void print()
{
	for (int i = front; i<=rear; i++)
	{
		printf ("%d ",array[i]);
	}
}

#include <stdio.h>
#include <stdlib.h>


//struct node here
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;

//createing a queue
void create()
{
	front=rear=NULL;
}

//insertion in the queue
int ins(int data)
{

  if (rear==NULL)
  {

  	rear = (struct node *)malloc(1*sizeof(struct node));
  	rear->ptr = NULL;
  	rear->info = data;
  	front=rear;
  }
  else
  {
    
     temp=(struct node *)malloc(1*sizeof(struct node));
     rear->ptr = temp;
     temp->info = data;
     temp->ptr = NULL;
     rear = temp;
  }
}


//displaying the data in the queue
void display()
{
   front1=front;
   if ((front1==NULL)&&(rear==NULL))
   {
   	printf("Queue is empty\n");
   	return;
   }
   
   	 while (front1 != rear)
    {
        printf("%d \t", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d\t", front1->info);
}

//removing from the queue
void rmv()
{
      front1 = front;
 
     if (front1 == NULL)
     {
        printf("\n Removing elements from empty queue");
        return;
     }
     else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Removed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Removed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
}

int main()
{
	printf("Entering elements in queue\n");
ins(5);
ins(45);
ins(15);
ins(25);
ins(35);
ins(45);
printf("Printing the stored elements from the queue\n");
display();
printf("\n");
printf("Now removing the elements from the queue\n");
rmv(5);
rmv(25);
printf("\nNow the new queue is\n");
display();
printf("\n");



	return 0;
}
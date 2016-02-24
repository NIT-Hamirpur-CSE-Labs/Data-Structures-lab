#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *ptr;
} *top,*top1,*temp;

//displaying the contents of the stack
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d \t", top1->info);
        top1 = top1->ptr;

    }
 }

//create a stack
void create()
{
    top = NULL;
}

//putting data into stack
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
}


//deletiong data from stack ie. pop
void pop()
{
  top1=top;
  if (top1==NULL)
  {
  	printf("You are trying to pop from an empty stack\n");
  }
  else
  {
  	top1=top1->ptr;
  	printf("poped value is %d\n",top->info);
  	free(top);
  	top=top1;
  }
}

//displaying info of top
int topinfo()
{
	return(top->info);
}

int main()
{
	int a,b,c,d;
printf("Pushing in the stack\n");
//printf("Please enter value to insert\n");
//scanf("%d",&a);
push(5);
push(15);
push(25);
push(35);
push(45);
push(55);
display();
printf("\n");
printf("Now poping out of the stack\n");
pop(5);
pop(15);
pop(45);
printf("Now the left elements in stack are\n");
display();
printf("\n");

	return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
struct node *prev;
};

//inserting node in front
void front(struct node** head_ref, int new_data)
{
	struct node* new_node=(struct node*) malloc(sizeof(struct node));

	new_node->data=new_data;
	new_node->prev=NULL;
	new_node->next=(*head_ref);
	if((*head_ref)!=NULL)
		(*head_ref)->prev=new_node;
}

//traversing through the link list
void traverse(struct node *node)
{
	struct node *last;
	printf("Traversing through the link list from the front\n");
	
	if(node!=NULL)
	{
		printf("%d \n",node->data);
		last=node;
		node=node->next;
	}
	else{
		printf("The link list is empty\n");
		
	}

	printf("Traversal from reverse direction\n");
	if(last!=NULL)
	{
		printf("%d \n",last->data);
		last=last->prev;
	}

	else{
		printf("The link list is empty\n");
		
	}
}

//insertion of node after a given node
void aftergiven(struct node* prev_node, int new_data)
{
	if(prev_node==NULL)
	{
		printf("The node you entered is NULL\nPlease retry\n");
		
	}

	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=prev_node->next;
	prev_node->next=new_node;

	if(new_node->next!=NULL)
	{
		new_node->next->prev=new_node;
	}
}

//insertion at the end
void atend(struct node** head_ref, int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	*/
	struct node *last=*head_ref;
	new_node->data=new_data;
	new_node->next=NULL;
	if(head_ref==NULL)
	{
		new_node->prev=NULL;
		*head_ref=new_node;
		return;
	}
	while(last->next!=NULL)
		last=last->next;
	last->next=new_node;
	new_node->prev=last;
	return;

}

int main()
{

 struct node* head=NULL;
//atend(&head,3);
front(&head,30);


 
 traverse(head);

	return 0;
}

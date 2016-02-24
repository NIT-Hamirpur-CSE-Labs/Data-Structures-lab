#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

void push(struct node** head_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if((*head_ref) != NULL)
	(*head_ref)->prev = new_node ;
	(*head_ref) = new_node;
}


void insertAfter(struct node* prev_node, int new_data)
{

	if (prev_node == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;
	}

	struct node* new_node =(struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	new_node->prev = prev_node;
	if (new_node->next != NULL)
	new_node->next->prev = new_node;
}

void append(struct node** head_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	struct node *last = *head_ref; /* used in step 5*/
	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		new_node->prev = NULL; 
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
 	last->next = new_node;
	new_node->prev = last;

	return;
}

void printList(struct node *node)
{
	struct node *last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL)
	{
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}

	printf("\nTraversal in reverse direction \n");
	while (last != NULL)
	{
		printf(" %d ", last->data);
		last = last->prev;
	}
}

int main()
{

	struct node* head = NULL;
	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insertAfter(head->next, 8);
	printf("\n Created DLL is: ");
	printList(head);

	getchar();
	return 0;
}

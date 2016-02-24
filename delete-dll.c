#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
//insert at begining
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

//remove from begining *working correctly
void dlt(struct node** head_ref, int key)
{
	 	struct node* temp = *head_ref, *prev;
		if (temp != NULL && temp->data == key)
	 {
		*head_ref = temp->next; 
		free(temp);			 
		return;
	 }
     while (temp != NULL && temp->data != key)
	 {
		prev = temp;
		temp = temp->next;
	 }

	
	 if (temp == NULL) return;
    	prev->next = temp->next;
	 free(temp); 
}



//inserting at last
void append(struct node** head_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	struct node *last = *head_ref; 
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

//deleting from end
void dltend(struct node** head_ref, int key)
{
	 	struct node* temp = *head_ref, *prev;
		if (temp != NULL && temp->next ==NULL)
	 {
		*head_ref = temp->next; 
		free(temp);			 
		return;
	 }
     while (temp != NULL && temp->next != NULL)
	 {
		prev = temp;
		temp = temp->next;
	 }

	
	 if (temp == NULL) return;
    	prev->next = temp->next;
	 free(temp); 
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

	/*printf("\nTraversal in reverse direction \n");
	while (last != NULL)
	{
		printf(" %d ", last->data);
		last = last->prev;
	}
	*/
}

int main()
{

	struct node* head = NULL;

	push(&head,1);
	push(&head,2);
	push(&head,6);
	push(&head,7);
	push(&head,9);
	append(&head,88);
	printf("\n Created DLL is: \n");
	printList(head);

    printf("\n \nNow deleting 1, 7 & 88");
	
	//these are deleting these elements
	dlt(&head, 1);
	dlt(&head, 7);
	//dlt(&head, 88);

	//this is deleting from end 
	dltend(&head,88);
	printList(head);
	//append(&head, 4);
	
	getchar();
	return 0;
}

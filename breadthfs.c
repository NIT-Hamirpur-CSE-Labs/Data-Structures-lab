//BFS algo
#include<stdio.h>
#include<stdlib.h>

//defining macros so as to assign them a fixed value
#define MAX 20
#define initial 1
#define waiting 2
#define visited 3

int n;    
int adj[MAX][MAX];
int state[MAX]; 

//now some functions which'll be used in the program
int queue[MAX], front = -1,rear = -1;
//int count,max_edge,origin,destin;
void traversal();
void bfs();
void insert_queue();
int delete_queue();
void create_graph();
int isEmpty_queue();

int main()
{
    create_graph();
    traversal();
    return 0;
}

//used for traversal
void traversal()
{
	int v;
	
	for (v = 0; v < n; v++)
	{
		state[v]=initial;
	}
	printf("Enter start vertex\n");
	scanf("%d",&v);
	bfs(v);

}

//applying bfs here
void bfs(int v)
{
	  int i;
    
     insert_queue(v);
     state[v] = waiting;
    
     while(!isEmpty_queue())
     {
        v = delete_queue( );
        printf("%d ",v);
        state[v] = visited;
        
        for(i=0; i<n; i++)
        {
            if(adj[v][i] == 1 && state[i] == initial) 
            {
                insert_queue(i);
                state[i] = waiting;
            }
        }
     }
    printf("\n");
}

//if queue is empty
int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

//insertion in queue
void insert_queue(int vertex)
{
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1) 
            front = 0;
        rear = rear+1;
        queue[rear] = vertex ;
    }
}

//deletion from queue
int delete_queue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    
    delete_item = queue[front];
    front = front+1;
    return delete_item;
}

//creating a graph
void create_graph()
{
    int count,max_edge,origin,destin;

    printf("Enter number of vertices : ");
    scanf("%d",&n);
    max_edge = n*(n-1);
 
    for(count=1; count<=max_edge; count++)
    {
        printf("Enter edge %d(0 0 to quit ) : ",count);
        scanf("%d %d",&origin,&destin);
 
        if((origin == 0) && (destin == 0))
            break;            
 
        if(origin>=n || destin>=n || origin<0 || destin<0)
        {
            printf("Invalid edge!\n");
            count--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}

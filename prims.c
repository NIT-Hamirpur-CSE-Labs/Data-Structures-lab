//prims
#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int visited[10]={0},min,mindist=0,distance[10][10];
int main()
{
        printf("\nEnter the no. of vertices:");
    	scanf("%d",&n);
    	printf("\nEnter the adjacency matrix according to weight:\n");
    	for(i=1;i<=n;i++)
    	{
    		for(j=1;j<=n;j++)
    		{
    			scanf("%d",&distance[i][j]);
    			if(distance[i][j]==0)
    				distance[i][j]=999;
    		}

    		visited[1]=1;

    		while(ne < n)
    	    {
    	    		for(i=1,min=999;i<=n;i++)
    		{
    			for(j=1;j <= n;j++)
    			{
    				if(distance[i][j] < min)
    				{
    					min=distance[i][j];
    					a=u=i;
    					b=v=j;
    				}

      if(visited[u]==0 || visited[v]==0)
 
		{
			if(u!=v)
			{
 
			printf("\n Edge :(%d , %d) distance:%d",a,b,min);
			printf("\n");
 
			mindist+=min;
 
			visited[b]=1;
		}
		else{
			printf("an error\n");
		}
 
		}

    		distance[a][b]=distance[b][a]=999;
    	}

}
    	}
    }




	return 0;
}

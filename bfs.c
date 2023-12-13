#include<stdio.h>
#define MAX 4
void bfs(int adj[][MAX],int visited[],int start)
{
    int queue[MAX],i,front=-1,rear=-1;
    queue[++rear]=start;
    visited[start]=1;
    while(rear!=front)
    {
        start=queue[++front];
        if(start==4)
        {
            printf("5 \t");
        }
        else
        {
            printf("%c \t",start+65);
        }
    for(i=0;i<MAX;i++)
    {
        if(adj[start][i]==1 && visited[i]==0)
        {
            queue[++rear]=i;
            visited[i]=1;
        }
    }
    }
}
    int main()
    {
        int visited[MAX]={0};
        int adj[MAX][MAX],i,j;
        printf("Enter adjacency matrix:");
        for(i=0;i<MAX;i++)
        {
            for(j=0;j<MAX;j++)
            {
                scanf("%d",&adj[i][j]);

            }
        }
         int startVertex=0;

    printf("BFS Traversal starting from vertex %c:\n",startVertex+ 65);
    bfs(adj, visited, startVertex);

    return 0;
    }
    
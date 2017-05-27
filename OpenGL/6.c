#include <stdio.h>

void dij(int n, int v, int cm[20][20], int dist[20])
{
	int i,j,u,w,n,c=2;

	int flag[20];

	for(i=1;i<=n;i++)
	{
		flag[i] = 0;
		dist[i] = cm[v][i];
	}

	c = 2;
	int min = 99;

	while(c<=n)
	{
		min = 99;
		for(w=1;w<=n;w++)
		{
			if(!flag[w] && min>dist[w] )
			{
				min = dist[w];
				u = w;
				flag[u] = 1;
				c++;
			}
		}

		for(w=1;w<=n;w++)
		{
			if(dist[w] > dist[u] + cm[u][w]  && !flag[w])
				dist[w] = dist[u] + cm[u][w];
		}
	}

}


int main()
{
	int i,j,n,v;
	printf("Number of nodes\n");
	scanf("%d",&n);
	printf("Start node\n");
	scanf("%d",&v);
	printf("Matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",cm[i][j]);
			if(cm[i][j] == 0)
				cm[i][j] = 99;
		}
	}

	int dist[20];
	dij(n,v,cm,dist);
	for(i=1;i<=n;i++)
	{
		if(i!=v)
		{
			printf("%d->%d:Cost%d\n",v,i,dist[i] );
		}
	}
}
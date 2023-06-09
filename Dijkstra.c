#include<stdio.h>
#define MAX 50
#define INF 999999

int dist[MAX], cost[MAX][MAX], pre[MAX];

void dijkstra(int n,int v){
	int i, c, w, u, min, status[MAX];
	
	for(i = 1; i <= n; i++){
		status[i] = 0;
		dist[i] = cost[v][i];
		pre[i] = v;
	}
	
	dist[v] = 0;
	status[v] = 1;
	pre[v] = 0;
	
	for(c = 2; c <= n; c++){
		min = INF;
		for(w = 1; w <= n; w++){
			if((dist[w] < min) && (status[w] != 1)){
				min = dist[w];
				u = w;
			}
		}
		
		status[u] = 1;
		
		for(w = 1; w <= n; w++){
			if(((dist[u] + cost[u][w]) < dist[w]) && status[w] == 0){
				dist[w] = dist[u] + cost[u][w];
				pre[w] = u;
			}
		}
	}
}

int main(){
	int i, j, v, n;
	
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	
	printf("\nEnter value of matrix:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &cost[i][j]);
			if(cost[i][j] == 0){
				cost[i][j] = INF;
			}
		}
	}
	
	printf("\nEnter source vertex: ");
	scanf("%d", &v);
	
	dijkstra(n, v);
	
	printf("\nPredecessor Array: ");
	for(i = 1; i <= n; i++){
		printf("%d\t", pre[i]);
	}
	
	printf("\n\nDistance Array:\n");
	for(i = 1; i <= n; i++){
		if(i != v){
			printf("%d --> %d = %d\n", v, i, dist[i]);
		}
	}
	
	for(i = 1; i <= n; i++){
		if(i != v){
			printf("\nPath %d", i);
			j = i;
			while(j != v){
				j = pre[j];
				printf(" --> %d", j);
			}
			printf("\n");
		}
	}
	
	return 0;
}

/*
0 10 0 0 5
0 0 1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0
*/

/*
0 1 2 1 0
0 0 0 0 0
0 1 0 9 3
0 5 0 0 0
6 0 0 4 0
*/

/*
0 5 2 10 6
5 0 13 5 0
2 13 0 9 3
10 5 9 0 4
6 0 3 4 0
*/
#include<stdio.h>
#define MAX 50
#define INF 999999

int bellman_ford(int g[MAX][MAX], int s, int n){
	int d[MAX][MAX], i, u, w;
	
	for(i = 1; i <= n; i++){
		d[1][i] = INF;
		d[2][i] = 0;
	}
	
	d[1][s] = 0;
	
	for(i = 1; i < n; i++){
		for(u = 1; u <= n; u++){
			for(w = 1; w <= n; w++){
				if(d[1][w] > d[1][u] + g[u][w]){
					d[1][w] = d[1][u] + g[u][w];
					d[2][w] = u;
				}
			}
		}
		
		printf("\nIteration: %d\n", i);
		for(u = 1; u <= 2; u++){
			for(w = 1; w <= n; w++){
				printf("%d ", d[u][w]);
			}
			printf("\n");
		}
	}
	
	for(u = 1; u <= n; u++){
		for(w = 1; w <= n; w++){
			if(d[1][w] > d[1][u] + g[u][w]){
				return 0;
			}
		}
	}
	
	return 1;
}

int main(){
	int g[MAX][MAX], i, j, n, s, x;
	
	printf("Enter the no. of vertices: ");
	scanf("%d", &n);
	
	printf("\nEnter the matrix elements:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &g[i][j]);
			if(g[i][j] == 0){
				g[i][j] = INF;
			}
		}
	}
	
	printf("\nEnter the source vertex: ");
	scanf("%d", &s);
	
	x = bellman_ford(g, s, n);
	if(x == 1){
		printf("\nThere is no negative weight cycle");
	}
	else{
		printf("\nThere is a negative weight cycle");
	}
	
	return 0;
}

/*
0 6 0 7 0
0 0 5 8 -4
0 -2 0 0 0
0 0 -3 0 9
2 0 7 0 0
*/
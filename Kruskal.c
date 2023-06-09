#include<stdio.h>
#define INF 999999
#define MAX 50

int min, mincost = 0, cost[MAX][MAX], parent[MAX];

int find(int i){
	while(parent[i]){
		i = parent[i];
	}

	return i;
}

int uni(int i, int j){
	if(i != j){
		parent[j] = i;
		return 1;
	}
	
	return 0;
}

int main(){
	int i, j, a, b, u, v, n, k;
	
	printf("Enter the no. of vertices: ");
	scanf("%d", &n);
	
	printf("\nEnter the cost adjacency matrix:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &cost[i][j]);
			if(cost[i][j] == 0)
				cost[i][j] = INF;
		}
	}
	
	printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
	for(k = 1; k < n; k++){
		min = INF;
		
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				if(cost[i][j] < min){
					min = cost[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		
		u = find(u);
		v = find(v);
		
		if(uni(u, v)){
			printf("Edge[%d] = (%d --> %d) Weight = %d\n", k, a, b, min);
			mincost += min;
		}
		cost[a][b] = cost[b][a] = INF;
	}
	
	printf("\nMinimum cost = %d\n", mincost);
	
	return 0;
}

/*
0 6 0 8 2 0
6 0 4 7 3 3
0 4 0 0 7 3
8 7 0 0 2 0
2 3 7 2 0 6
0 3 3 0 6 0
*/
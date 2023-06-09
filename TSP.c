#include<stdio.h>
#define MAX 50
#define INF 999999

int g[MAX][MAX], visited[MAX], n, cost = 0;

int least(int c){
	int i, nc = INF, min = INF, kmin;
	
	for(i = 1; i <= n; i++){
		if((g[c][i] != 0) && (visited[i] == 0)){
			if(g[c][i] + g[i][c] < min){
				min = g[i][c] + g[c][i];
				kmin = g[c][i];
				nc = i;
			}
		}
	}
	
	if(min != INF){
		cost += kmin;
	}
	
	return nc;
}

void mincost(int city){
	int i, ncity;
	
	visited[city] = 1;
	printf("%d --> ", city);
	ncity = least(city);
	
	if(ncity == INF){
		ncity = 1;
		printf("%d", ncity);
		cost += g[city][ncity];
		return;
	}
	
	mincost(ncity);
}

int main(){
	int i, j, s;
	
	printf("Enter the no. of cities: ");
	scanf("%d", &n);
	
	printf("\nEnter the distance matrix:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &g[i][j]);
			visited[i] = 0;
		}
	}
	
	printf("\nEnter the starting city: ");
	scanf("%d", &s);
	
	printf("\nThe Path is: ");
	
	mincost(s);
	printf("\n\nMinimum cost = %d", cost);
	
	return 0;
}

/*
0 4 1 3
4 0 2 1
1 2 0 5
3 1 5 0
*/
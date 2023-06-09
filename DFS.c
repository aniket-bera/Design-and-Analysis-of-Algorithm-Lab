#include<stdio.h>
#define MAX 50

int g[MAX][MAX], visited[MAX], n;

int DFS(int v){
	int j;
	
	printf("%d ", v);
	
	visited[v] = 1;
	
	for(j = 1; j <= n; j++){
		if(visited[j] != 1 && g[v][j] == 1){
			DFS(j);
		}
	}
}

int main(){
	int i, j, s;
	
	printf("Enter no. of nodes: ");
	scanf("%d", &n);
	
	printf("\nEnter the value of graph:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &g[i][j]);
		}
	}
	
	printf("\nThe Graph: ");
	for(i = 1; i <= n; i++){
		printf("\n");
		for(j = 1; j <= n; j++){
			printf("%d ", g[i][j]);
		}
	}
	
	for(i = 1; i <= n; i++){
		visited[i] = 0;
	}
	
	printf("\n\nEnter source: ");
	scanf("%d", &s);
	
	DFS(s);
	
	return 0;
}

/*
0 1 1 0 0 0 0
1 0 0 1 1 0 0
1 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0
0 0 1 0 0 0 0
*/
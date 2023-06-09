#include<stdio.h>
#define MAX 50

int g[MAX][MAX], visited[MAX], n, q[MAX], f = 0, r = -1;

int BFS(int v){
	int j, k;
	
	for(j = 1; j <= n; j++){
		if(visited[j] != 1 && g[v][j] == 1){
			q[++r] = j;
		}
		if(f <= r){
			visited[q[f]] = 1;
			BFS(q[f++]);
		}
	}
}

int main(){
	int i, j, s;
	
	printf("Enter no. of nodes: ");
	scanf("%d", &n);
	
	printf("\nEnter the value of graph: ");
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
		q[i] = 0;
		visited[i] = 0;
	}
	
	printf("\n\nEnter source: ");
	scanf("%d", &s);
	
	BFS(s);
	for(i = 1; i <= n; i++){
		if(visited[i] == 1){
			printf("%d ", i);
		}
	}
	
	return 0;
}
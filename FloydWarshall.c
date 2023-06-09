#include<stdio.h>
#define MAX 50
#define INF 999999

int d[MAX][MAX], p[MAX][MAX];

void fw(int n){
	int i, j, k;
	
	for(k = 1; k <= n; k++){
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				if(d[i][j] > (d[i][k] + d[k][j])){
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = k;
				}
			}
		}
	}
}

void path(int a, int b){
	if(p[a][b] == 0){
		printf(" --> %d", b);
	}
	else{
		path(a, p[a][b]);
		path(p[a][b], b);
	}
}

int main(){
	int i, j, n;
	
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	
	printf("\nEnter value of matrix:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &d[i][j]);
			if(i != j && d[i][j] == 0){
				d[i][j] = INF;
			}
		}
	}
	
	fw(n);
	
	printf("\nDistance Matrix:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(d[i][j] == INF){
				printf("INF\t");
			}
			else{
				printf("%d\t", d[i][j]);
			}
		}
		printf("\n");
	}
	
	printf("\nPath Matrix:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(p[i][j] != 0){
				printf("%d\t", p[i][j]);
			}
			else{
				printf("INF\t");
			}
		}
		printf("\n");
	}
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			printf("\n\nPath from %d to %d: %d", i, j, i);
			path(i, j);
			if(d[i][j] == INF){
				printf("\nCost[%d][%d] = INF", i, j);;
			}
			else{
				printf("\nCost[%d][%d] = %d", i, j, d[i][j]);
			}
		}
	}
	
	return 0;
}

/*
0 1 0 6 7 0
0 0 1 4 0 0
0 0 0 2 0 1
0 0 0 0 3 2
0 0 0 0 0 2
0 0 0 0 0 0
*/

/*
0 8 0 1
0 0 1 0
4 0 0 0
0 2 9 0
*/

/*
0 2 3 0 0
5 0 0 7 4
7 3 0 6 0
0 0 1 0 5
0 0 0 3 0
*/
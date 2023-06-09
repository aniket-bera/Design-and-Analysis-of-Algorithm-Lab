#include<stdio.h>
#define MAX 50

int g[MAX][MAX], x[MAX], m;

void nextValue(int k, int n){
	int j, c;
	
	while(1){
		x[k] = (x[k] + 1) % (m + 1);
		if(x[k] == 0){
			return;
		}
		for(j = 1; j <= n; j++){
			if(g[k][j] != 0 && x[k] == x[j]){
				break;
			}
		}
		if(j == (n + 1)){
			return;
		}
	}
}

void mColouring(int k, int n){
	int i;
	
	while(1){
		nextValue(k, n);
		if(x[k] == 0){
			return;
		}
		else if(k == n){
			for(i = 1; i <= n; i++){
				printf("%d ", x[i]);
			}
			printf("\n");
		}
		else{
			mColouring(k + 1, n);
		}
	}
}

int main(){
	int n, i, j;
	
	printf("Enter the no. of vertices: ");
	scanf("%d", &n);
	
	printf("\nEnter the no.of colours: ");
	scanf("%d", &m);
	
	printf("\nEnter the adjacency matrix:\n"); 
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &g[i][j]);
		}
	}
	
	printf("\nThe possible solution vectors:\n"); 
	mColouring(1, n);
	
	return 0;
}

/*
0 1 1 0 0
1 0 1 1 1
1 1 0 0 1
0 1 0 0 1
0 1 1 1 0
*/
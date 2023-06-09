#include<stdio.h>
#define MAX 10

int g[MAX][MAX];
int p[MAX];

void displayCycle(int n){
	int i;
	
	printf("\nThe Hamiltonian Cycle:\n");
	for(i = 0; i < n; i++){
		printf("%d --> ", p[i]);
	}
	printf("%d", p[0]);
}

int isValid(int v, int k){
	int i;
	
	if(g[p[k - 1]][v] == 0){
		return 0;
	}
	
	for(i = 0; i < k; i++){
		if(p[i] == v){
			return 0;
		}
	}
	
	return 1;
}

int cycleFound(int k, int n){
	int v;
	
	if(k == n){
		if(g[p[k - 1]][p[0]] == 1){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	for(v = 1; v < n; v++){
		if(isValid(v, k)){
			p[k] = v;
			if(cycleFound(k + 1, n) == 1){
				return 1;
			}
			p[k] = -1;
		}
	}
	
	return 0;
}

int hamiltonianCycle(int n){
	int i;
	
	for(i = 0; i < n; i++){
		p[i] = -1;
		p[0] = 0;
		if(cycleFound(1, n) == 0){
			printf("\nSolution does not exist");
			return 0;
		}
	}
	
	displayCycle(n);
	
	return 1;
}

int main(){
	int i, j, n;
	
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	
	printf("\nEnter the Graph:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &g[i][j]);
		}
	}

	hamiltonianCycle(n);
	
	return 0;
}

/*
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0
*/
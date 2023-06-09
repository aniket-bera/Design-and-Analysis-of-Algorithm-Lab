#include<stdio.h>
#define INF 99999999

int m[20][20], s[20][20];

void matrixChainOrder(int p[], int n){
	int i, j, k, l, q;
	
	for(i = 1; i <= n; i++){
		m[i][i] = 0;
	}
	
	for(l = 2; l <= n; l++){
		for(i = 1; i <= n - l + 1; i++){
			j = i + l - 1;
			m[i][j] = INF;
			
			for(k = i; k <= j - 1; k++){
				q = m[i][k] + m[k+1][j] + (p[i - 1] * p[k] * p[j]);
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void printOP(int i, int j){
	int ch = 64;
	
	if(i == j){
		printf(" %c ", ch + i);
	}
	else{
		printf(" ( ");
		printOP(i, s[i][j]);
		printOP((s[i][j]) + 1, j);
		printf(" ) ");
	}
}

void costM(int n){
	int i, j;
	
	printf("\n\nCost Matrix:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(j < i){
				printf("\t");
			}
			else{
				printf("%d\t", m[i][j]);
			}
		}
		printf("\n");
	}
}

void sequenceM(int n){
	int i, j;
	
	printf("\n\nSequence Matrix:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(j > i){
				printf("%d\t", s[i][j]);
			}
			else{
				printf("\t");
			}
		}
		printf("\n");
	}
}

int main(){
	int n, d, i, p[20], j, ch = 65;
	
	printf("Enter the no. of dimensions: ");
	scanf("%d", &n);
	
	printf("\nEnter the dimensions: ");
	for(i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	
	printf("\nDimensions: <");
	for(i = 0; i < n; i++){
		printf(" %d ", p[i]);
	}
	printf(">");
	
	d = n - 1;
	for(i = 0; i < d; i++){
		printf("\nMatrix[%c]: %d x %d", ch++, p[i], p[i + 1]);
	}
	
	matrixChainOrder(p, d);
	printf("\n\nOptimal Parenthesis Sequence: ");
	
	printOP(1, d);
	printf("\nTotal Cost = %d", m[1][d]);
	
	costM(d);
	sequenceM(d);
	
	return 0;
}
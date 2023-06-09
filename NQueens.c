#include<stdio.h>
#include<math.h>
#define MAX 50

int x[MAX], c = 0;

int place(int k, int i){
	int j;
	
	for(j = 1; j <= k - 1; j++){
		if((x[j] == i) || (abs(x[j] - i) == abs(j - k))){
			return 0;
		}
	}
	
	return 1;
}

void NQueens(int k, int n){
	int i, j;
	
	for(i = 1; i <= n; i++){
		if(place(k, i)){
			x[k] = i;
			
			if(k == n){
				c++;
				
				printf("\nSolution vector: ");
				for(j = 1; j <= n; j++){
					printf(" %d", x[j]);
				}
				
				printf("\nChess Board: %d\n", c);
				for(i = 1; i <= n; i++){
					for(j = 1; j <= n; j++){
						if(x[i] == j){
							printf(" |Q%d|", i);
						}
						else{
							printf(" |__|");
						}
					}
					printf("\n");
				}
			}
			else{
				NQueens(k + 1, n);
			}
		}
	}
}

int main(){
	int n;
	
	printf("Enter no. of queens: ");
	scanf("%d", &n);
	
	NQueens(1, n);
	printf("\nTotal no. of solutions: %d", c);
	
	return 0;
}
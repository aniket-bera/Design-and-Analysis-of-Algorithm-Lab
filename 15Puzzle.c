#include<stdio.h>
#define MAX 50
#define INF 999999

int cal(int temp[MAX][MAX], int t[MAX][MAX], int n){
	int i, j, m = 0;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(temp[i][j] != t[i][j]){
				m++;
			}
		}
	}
	
	return m;
}

int check(int a[MAX][MAX], int t[MAX][MAX], int n){
	int i, j, f = 1;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(a[i][j] != t[i][j]){
				f = 0;
			}
		}
	}
	
	return f;
}


int main(){
	int p, i, j, n, a[MAX][MAX], t[MAX][MAX], temp[MAX][MAX], r[MAX][MAX], m = 0, x = 0, y = 0, d = INF, dmin = 0, l = 0;

	printf("Enter size of matrix: ");
	scanf("%d", &n);
	
	printf("\nEnter the matrix to be solved, space with zero:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	printf("\nEnter the target matrix, space with zero:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &t[i][j]);
		}
	}

	while(!(check(a, t, n))){
		l++;
		d = INF;
		
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(a[i][j] == 0){
					x=i;
					y=j;
				}
			}
		}
		
		for(i = 0; i < n; i++){			//To move upwards
			for(j = 0; j < n; j++){
				temp[i][j] = a[i][j];
			}
		}

		if(x != 0){
			p = temp[x][y];
			temp[x][y] = temp[x - 1][y];
			temp[x - 1][y] = p;
		}
		
		m = cal(temp, t, n);
		dmin = l + m;
		
		if(dmin < d){
			d = dmin;
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					r[i][j] = temp[i][j];
				}
			}
		}

		for(i = 0; i < n; i++){			//To move downwards
			for(j = 0; j < n; j++){
				temp[i][j] = a[i][j];
			}
		}
		
		if(x != n - 1){
			p = temp[x][y];
			temp[x][y] = temp[x + 1][y];
			temp[x + 1][y] = p;
		}
		
		m = cal(temp, t, n);
		dmin = l + m;
		
		if(dmin < d){
			d = dmin;
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					r[i][j] = temp[i][j];
				}
			}
		}

		for(i = 0; i < n; i++){			//To move right side
			for(j = 0; j < n; j++){
				temp[i][j] = a[i][j];
			}
		}
		
		if(y != n - 1){
			p = temp[x][y];
			temp[x][y] = temp[x][y + 1];
			temp[x][y + 1] = p;
		}
		
		m = cal(temp, t, n);
		dmin = l + m;
		
		if(dmin < d){
			d = dmin;
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					r[i][j] = temp[i][j];
				}
			}
		}

		for(i = 0; i < n; i++){			//To move left
			for(j = 0; j < n; j++){
				temp[i][j] = a[i][j];
			}
		}
		
		if(y != 0){
			p = temp[x][y];
			temp[x][y] = temp[x][y - 1];
			temp[x][y - 1] = p;
		}
		
		m = cal(temp, t, n);
		dmin = l + m;
		
		if(dmin < d){
			d = dmin;
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					r[i][j] = temp[i][j];
				}
			}
		}

		printf("\nCalculated Intermediate Matrix Value:\n");
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
			  printf("%d\t", r[i][j]);
			}
			printf("\n");
		}
		
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
			  a[i][j] = r[i][j];
			  temp[i][j] = 0;
			}
		}
		
		printf("\nMinimum cost : %d\n", d);
	}
	
	return 0;
}

/*Initial Matrix
1 2 3 4
5 6 0 8
9 10 7 11
13 14 15 12
*/

/*Target Matrix
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 0
*/
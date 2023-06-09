#include<stdio.h>

float w[20], p[20];

void minW(int n){	//sorting according to min. weight
	int i, j;
	float temp;
	
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if(w[j] > w[j + 1]){
				temp = w[j];
				w[j] = w[j + 1];
				w[j + 1] = temp;
				
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void maxP(int n){	//sorting according to max. profit
	int i, j;
	float temp;
	
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if(p[j] < p[j + 1]){
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				
				temp = w[j];
				w[j] = w[j + 1];
				w[j + 1] = temp;
			}
		}
	}
}

void maxR(int n){	//sorting according to max. ratio
	int i, j;
	float r[20], temp;
	
	for(i = 0; i < n; i++){
		r[i] = p[i] / w[i];
	}
	
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if(r[j] < r[j + 1]){
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
				
				temp = w[j];
				w[j] = w[j + 1];
				w[j + 1] = temp;
				
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

int gk(float m, int n){
	int i, j, u;
	float x[20], TotalP = 0.0;
	
	u = m;
	
	for(i = 0; i < n; i++){
		x[i] = 0.0;
	}
	
	for(i = 0; i < n; i++){
		if(w[i] > u){
			break;
		}
		else{
			x[i] = 1.0;
			u = u - w[i];
		}
	}
	
	if(i <= n){
		x[i] = u / w[i];
	}
	
	for(i = 0; i < n; i++){
		TotalP += (x[i] * p[i]);
	}
	
	printf("\nSolution Vectors:\n");
	for(i = 0; i < n; i++){
		printf("X[%d] --> %0.1f\n", i+1, x[i]);
	}
	
	printf("\nTotal Profit: %0.1f", TotalP);
	printf("\n__________________________________________\n");
}

int main(){
	int num, i, e, f, g;
	float c;
	
	printf("Enter no. of objects: ");
	scanf("%d", &num);
	
	printf("\nEnter the capacity: ");
	scanf("%f", &c);
	
	printf("\nEnter %d weights & profits of each object: ", num);
	for(i = 0; i < num; i++){
		printf("\nWeight[%d] --> ", i+1);
		scanf("%f", &w[i]);
		printf("Profit[%d] --> ", i+1);
		scanf("%f", &p[i]);
	}
	
	printf("\nAccording to Minimum Weight:");
	minW(num);
	e = gk(c, num);
	
	printf("\nAccording to Maximum Profit:");
	maxP(num);
	f = gk(c, num);
	
	printf("\nAccording to Maximum Profit-Weight ratio:");
	maxR(num);
	g = gk(c, num);
	
	//compare best total profit
	if(e > f && e > g){
		printf("\nMinimum weight through get best total profit.");
	}
	else if(f > e && f > g){
		printf("\nMaximum profit through get best total profit.");
	}
	else{
		printf("\nMaximum profit-weight ratio through get best total profit.");
	}
					
	return 0;
}
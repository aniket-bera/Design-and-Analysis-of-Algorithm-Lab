#include<stdio.h>

float w[20], p[20];

void maxP(int n){	//sorting according to max. profit
	int i, j;
	float temp;
	
	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			if(p[i] < p[j]){
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
				
				temp = w[j];
				w[j] = w[i];
				w[i] = temp;
			}
		}
	}
}

void gk(float m, int n){
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
	
	printf("\nTotal profit: %0.1f", TotalP);
}

int main(){
	int num, i;
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
	
	maxP(num);
	gk(c, num);
	
	return 0;
}
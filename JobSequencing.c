#include<stdio.h>

int dmax, slot[50];

void order(int num, int id[], int p[], int d[]){
	int i, j, temp;
	
	for(i = 0; i < num - 1; i++){
		for(j = 0; j < num - i - 1; j++){
			if(p[j] < p[j + 1]){
				temp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = temp;
				
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				
				temp = id[j];
				id[j] = id[j + 1];
				id[j + 1] = temp;
			}
		}
	}
}

int js(int num, int id[], int p[], int d[]){
	int c, i, k, sum = 0;
	
	c = 0;
	dmax = d[0];
	
	for(i = 1; i < num; i++){
		if(d[i] > dmax){
			dmax = d[i];
		}
	}
	
	for(i = 1; i <= dmax; i++){
		slot[i] = -1;
	}
	
	for(i = 0; i < num; i++){
		k = d[i];
		
		while(k > 0){
			if(slot[k] == -1){
				slot[k] = i;
				c++;
				sum += p[i];
				break;	//break from while
			}
			k--;
		}	//end while
		
		if(c == dmax){
			break;	//break from for
		}
	}

	return sum;
}

int main(){
	int i, n, job[50], pr[50], de[50], k;
	
	printf("Enter no. of jobs: ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		printf("\nJob ID --> ");
		scanf("%d", &job[i]);
		printf("Profit[%d] --> ", job[i]);
		scanf("%d", &pr[i]);
		printf("Deadline[%d] --> ", job[i]);
		scanf("%d", &de[i]);
	}
	
	order(n, job, pr, de);
	
	k = js(n, job, pr, de);
	
	printf("\nTotal Profit: %d", k);
	printf("\nSolution vector --> ");
	for(i = 1; i <= dmax; i++){
		printf("%d ", job[slot[i]]);
	}
	
	return 0;
}
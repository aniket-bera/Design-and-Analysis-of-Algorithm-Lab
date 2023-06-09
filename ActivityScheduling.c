#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void order(int *a, int *s, int *f, int n){
	int i, j;
	
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if(*(f + j) > *(f + j + 1)){
				swap((f + j), (f + j + 1));
				swap((s + j), (s + j + 1));
				swap((a + j), (a + j + 1));
			}
		}
	}
}

void as(int *a, int *s, int *f, int n){
	int i, k, *alist, pre;
	
	alist = (int *)malloc(n *sizeof(int));
	
	*alist = *a;
	k = 1;
	pre = 0;
	
	for(i = 1; i < n; i++){
		if(*(s + i) >= *(f + pre)){
			*(alist + k) = *(a + i);
			k++;
			pre = i;
		}
	}
	
	printf("\nThe optimal schedule activities are --> ");
	for(i = 0; i < k; i++){
		printf("A%d ", *(alist + i));
	}
}

int main(){
	int *act, *st, *ft, i, n;
	
	printf("Enter no. of activities: ");
	scanf("%d", &n);
	
	act = (int *)malloc(n *sizeof(int));
	st = (int *)malloc(n *sizeof(int));
	ft = (int *)malloc(n *sizeof(int));
	
	printf("\nEnter %d staring & finishing time of each activity:", n);
	for(i = 0; i < n; i++){
		*(act + i) = i + 1;
		printf("\nActivity no. --> %d", *(act + i));
		printf("\nStart[%d] --> ", *(act + i));
		scanf("%d", (st + i));
		printf("Finished[%d] --> ", *(act + i));
		scanf("%d", (ft + i));
	}
	
	order(act, st, ft, n);
	as(act, st, ft, n);
	
	return 0;
}
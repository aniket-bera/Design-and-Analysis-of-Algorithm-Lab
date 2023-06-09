#include<stdio.h>

int maxmin(int b[], int num){
	int max, min, i;
	
	max = min = b[0];
	
	for(i = 1; i < num; i++){
		if(b[i] > max){
			max = b[i];
		}
		if(b[i] < min){
			min = b[i];
		}
	}
	
	printf("\nMax element of given array: %d", max);
	printf("\nMin element of given array: %d", min);
}

int main(){
	int a[50], n, i;
	
	printf("Enter no. of element: ");
	scanf("%d", &n);
	
	printf("\nEnter %d elements: ", n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	maxmin(a, n);
	
	return 0;
}
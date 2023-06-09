#include<stdio.h>

//int max, min;

void maxmin(int a[], int i, int j, int *max, int *min){
	int max1, min1, mid, k;
	
	if(i == j){		//array consist of single element
		*max = *min = a[i];
	}
	else if(i == j - 1){	//array consist of 2 element
		if(a[i] < a[j]){
			*max = a[j];
			*min = a[i];
		}
		else{
			*max = a[i];
			*min = a[j];
		}
	}
	else{
		mid = (i + j) / 2;
		maxmin(a, i, mid, max, min);
		max1 = *max;
		min1 = *min;
		
		printf("\nFirst half: ");
		for(k = i; k <= mid; k++){
			printf("%d ", a[k]);
		}
		printf("\nMax: %d", *max);
		printf("\nMin: %d", *min);
		
		maxmin(a, mid + 1, j, max, min);
		printf("\nSecond half: ");
		for(k = mid + 1; k <= j; k++){
			printf("%d ", a[k]);
		}
		printf("\nMax: %d", *max);
		printf("\nMin: %d", *min);
		
		if(max1 > *max){
			*max = max1;
		}
		if(min1 < *min){
			*min = min1;
		}
	}
}

int main(){
	int ar[20], n, i, max, min;
	
	printf("Enter no. of element: ");
	scanf("%d", &n);
	
	printf("\nEnter %d elements: ", n);
	for(i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	maxmin(ar, 0, n - 1, &max, &min);
	printf("\nMax element of given array: %d", max);
	printf("\nMin element of given array: %d", min);
	
	return 0;
}

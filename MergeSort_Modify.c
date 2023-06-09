#include<stdio.h>

void merge(int a[], int lb, int mid, int ub){
	int i, j, k, b[10];
	
	i = lb;
	j = mid + 1;
	k = lb;
	
	while(i <= mid && j <= ub){
		if(a[i] <= a[j]){
			b[k] = a[i];
			i++;
		}
		else{
			b[k] = a[j];
			j++;
		}
		k++;
	}
	
	while(j <= ub){
		b[k] = a[j];
		j++;
		k++;
	}
	while(i <= mid){
		b[k] = a[i];
		i++;
		k++;
	}
	
	for(k = lb; k <= ub; k++){
		a[k] = b[k];
		printf("\nIteration --> %d", a[k]);
	}
}

void mergeSort(int a[], int lb, int ub){
	int mid;
	
	if(lb < ub){
		mid = (lb + ub) / 2;
		mergeSort(a, lb, mid);
		mergeSort(a, mid + 1, ub);
		merge(a, lb, mid, ub);
	}
}

int main(){
	int ar[10], n, i;
	
	printf("Enter no. element: ");
	scanf("%d", &n);
	
	printf("\nEnter %d elements: ", n);
	for(i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	printf("\nInitial array: ");
	for(i = 0; i < n; i++){
		printf("%d ", ar[i]);
	}
	
	mergeSort(ar, 0, n - 1);
	printf("\n\nSorted array: ");
	for(i = 0; i < n; i++){
		printf("%d ", ar[i]);
	}
	
	return 0;
}

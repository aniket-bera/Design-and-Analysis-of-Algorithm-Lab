#include<stdio.h>

int partition(int a[], int lb, int ub){
	int pivot, start, end, temp;
	pivot = lb;
	start = lb;
	end = ub;
	
	while(start < end){
		while(a[start] <= a[pivot] && end < ub){
			start++;
		}
		while(a[end] > a[pivot]){
			end--;
		}
		
		if(start < end){
			temp = a[start];
			a[start] = a[end];
			a[end] = temp;
		}
	}
	
	temp = a[pivot];
	a[pivot] = a[end];
	a[end] = temp;
	
	return end;
}

void quickSort(int a[], int lb, int ub){
	int loc;
	
	if(lb < ub){
		loc = partition(a, lb, ub);
		quickSort(a, lb, loc - 1);
		quickSort(a, loc + 1, ub);
	}
}

int main(){
	int ar[20], n, i;
	
	printf("Enter no. of elements: ");
	scanf("%d", &n);
	
	printf("\nEnter %d elements: ", n);
	for(i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	printf("\nInitial array: ");
	for(i = 0; i < n; i++){
		printf("%d ", ar[i]);
	}
	
	quickSort(ar, 0, n - 1);
	printf("\n\nSorted array: ");
	for(i = 0; i < n; i++){
		printf("%d ", ar[i]);
	}
	
	return 0;
}

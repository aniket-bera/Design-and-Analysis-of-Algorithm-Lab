#include<stdio.h>

void merge(int ar[], int lb, int mid, int ub){
	int i, j, k, sub[20];
	i = lb;
	j = mid + 1;
	k = lb;
	
	while(i <= mid && j <= ub){
		if(ar[i] <= ar[j]){
			sub[k] = ar[i];
			i++;
		}
		else{
			sub[k] = ar[j];
			j++;
		}
		k++;
	}
	
	while(j <= ub){
		sub[k] = ar[j];
		j++;
		k++;
	}
	while(i <= mid){
		sub[k] = ar[i];
		i++;
		k++;
	}
	
	for(k = lb; k <= ub; k++){
		ar[k] = sub[k];
	}
}

void mergeSort(int ar[], int lb, int ub){
	int mid;
	
	if(lb < ub){
		mid = (lb + ub) / 2;
		mergeSort(ar, lb, mid);
		mergeSort(ar, mid + 1, ub);
		merge(ar, lb, mid, ub);
	}
}

int main(){
	int arr[10], num, i, c;

    printf("Enter size of array: ");
    scanf("%d", &num);
    
    printf("\nEnter %d elements in the array: ", num);
    for(i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nInitial array: ");
    for(i = 0; i < num; i++){
        printf("%d  ", arr[i]);
    }
    
    mergeSort(arr, 0, num - 1);
    printf("\n\nSorted order: ");
    for(i = 0; i < num; i++){
        printf("%d ", arr[i]);
	}
	
	return 0;
}
#include<stdio.h>

int max, min, a[20];

void maxmin(int i, int j){
	int max1, min1, mid;
	
	if(i == j){		//array consist of single element
		max = min = a[i];
	}
	else if(i == j - 1){	//array consist of 2 element
		if(a[i] < a[j]){
			max = a[j];
			min = a[i];
		}
		else{
			max = a[i];
			min = a[j];
		}
	}
	else{
		mid = (i + j) / 2;
		maxmin(i, mid);
		max1 = max;
		min1 = min;
		maxmin(mid + 1, j);
		if(max1 > max){
			max = max1;
		}
		if(min1 < min){
			min = min1;
		}
	}
}

int main(){
	int n, i;
	
	printf("Enter no. of elements: ");
	scanf("%d", &n);
	
	printf("\nEnter %d elements: ", n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	maxmin(0, n - 1);
	printf("\nMax element of given array: %d", max);
	printf("\nMin element of given array: %d", min);
	
	return 0;
}

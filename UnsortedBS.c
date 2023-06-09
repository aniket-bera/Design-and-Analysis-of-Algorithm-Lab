#include<stdio.h>
#include<stdlib.h>

int check(int ar[], int num){
    if(num == 1 || num == 0){
    	return 1;	
	}
    if(ar[num - 1] < ar[num - 2]){
        return 0;
	}

    return check(ar, num - 1);
}

void bubble(int ar[], int num){  
	int i, j, temp;  
	
	for(i = 0; i < num; i++){    
      	for(j = i + 1; j < num; j++){    
        	if(ar[j] < ar[i]){    
                temp = ar[i];    
                ar[i] = ar[j];    
                ar[j] = temp;     
			}     
		}     
	}    
}

int binarysearchI(int b[], int first, int last, int e){
    int mid;

    while(first <= last){
        mid = (first + last) / 2;
        
        if(b[mid] == e){
			return mid;
		}	
        else if(b[mid] < e){
            first = mid + 1;
        }
        else{
            last = mid - 1;
        }   
    }
    
    return -1;
}

int binarysearchR(int b[], int first, int last, int e){
    int mid;

    if(first <= last){
        mid = (first + last) / 2;
        
        if(b[mid] == e){
			return mid;
        }
        else if(b[mid] < e){
            return binarysearchR(b, mid + 1, last, e);
        }
        
        return binarysearchR(b, first, mid - 1, e); 
    }
    
    return -1;
}

/*int multiOccur(int c[], int n, int e){
	int t, count, first, last;
	
	t = binarysearchR(c, 0, n - 1, e);
	count = 1;
	first = t - 1;
	last = t + 1;
	
	if(t == -1){
		return 0;
	}
	
	while(first >= 0 && c[first] == e){
		count++;
		first--;
	}
	while(last < n && c[last] == e){
		count++;
		last++;
	}
	
	return count;
}*/

int main(){
    int a[10], n, i, s, f, c;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter %d integers: ", n);
    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    printf("\nGiven array: ");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    
    if(check(a, n)){
        printf("\nArray is already in ascending order");
	}
    else{
        bubble(a, n);
        printf("\n\nAfter sorting: ");
	    for (i = 0; i < n; i++){
	        printf("%d ", a[i]);
	    }
    }
    
    while(1){
    	printf("\n\n1 --> Iterative");
	    printf("\n2 --> Recursive");
	    printf("\n3 --> Exit");
	    printf("\n\nEnter your choice: ");
	    scanf("%d", &c);
	    
	    switch(c){
	    	case 1:	printf("\nEnter value to find: ");
				    scanf("%d", &s);
				    
				    f = binarysearchI(a, 0, n - 1, s);
				    
				    if(f == -1){
				    	printf("\n%d is not found!!!\n", s);
					}
					else{
						printf("\n%d found at location: %d", s, f + 1);
					}
			break;
			
			case 2:	printf("\nEnter value to find: ");
				    scanf("%d", &s);
				    
				    f = binarysearchR(a, 0, n - 1, s);
				    /*f = multiOccur(a, n, s);
					printf(" ",f);*/
									    
				    if(f == -1){
				    	printf("\n%d is not found!!!\n", s);
					}
					else{
						printf("\n%d found at location: %d", s, f + 1);
					}
			break;
			
			case 3:	exit(0);
			break;
			
			default:printf("\nInvalid input!!!");
		}
	}
    
    return 0;
}
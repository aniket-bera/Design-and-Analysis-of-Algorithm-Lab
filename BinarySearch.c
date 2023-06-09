#include<stdio.h>
#include<stdlib.h>

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

int main(){
    int a[10], n, i, s, f, c;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter %d integers in ascending order: ", n);
    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
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
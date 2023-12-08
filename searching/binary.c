#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int binary_search(char* arr,int n, char ch){
	if (n==0){
		return INT_MIN;
	}
	int start=0;
	int end=n-1;
	int mid;
	while (start<=end){
		mid=(start+(end-start)/2);
		if (ch==arr[mid]){
			return mid;
		}
		else if(ch>arr[mid]){
			start=mid+1;
		}
		else{
			end=mid-1;
		}
	}
	return INT_MIN;
}


int main(){
        int n;
        printf("Enter dimension for array : ");
        scanf("%d",&n);

        char* arr=(char *)malloc(sizeof(char)*n);
        for (int i = 0; i < n; ++i) {
                printf("Enter character %d: ", i + 1);
                scanf(" %c", &arr[i]);
    }
        printf("------\n");

        printf("The elements of the array created : \n");
        for (int i=0;i<n;i++){
                printf("%c ",arr[i]);
        }
        printf("\n");

        printf("-----\n");

        char ch;
        printf("Enter the character to be searched : ");
        scanf(" %c",&ch);

        printf("Index of %c in the array(zero indexing) : %d\n",ch,binary_search(arr,n,ch));


        return 0;
}


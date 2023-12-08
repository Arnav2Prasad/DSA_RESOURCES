#include <stdio.h>
#include <stdlib.h>

void insertion_sort(char* arr,int n){
	if (n==0 || n==1){
		return;
	}
	for (int i=0;i<n;i++){
		char curr=arr[i];
		int j=i-1;
		while (arr[j]>curr && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=curr;
	}
	return;
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

        insertion_sort(arr,n);

        printf("The elements of the Sorted array : \n");
        for (int i=0;i<n;i++){
                printf("%c ",arr[i]);
        }
        printf("\n");

        return 0;
}


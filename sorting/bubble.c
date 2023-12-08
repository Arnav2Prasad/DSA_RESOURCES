#include <stdio.h>
#include <stdlib.h>

//bubble_sort
void bubble_sort(char* arr,int n){
	if (n==0 || n==1){
		return;
	}

	for (int i=0;i<n-1;i++){
		for (int j=0;j<n-i-1;j++){
			if (arr[j]>arr[j+1]){
				char temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
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

	bubble_sort(arr,n);

	printf("The elements of the Sorted array : \n");
        for (int i=0;i<n;i++){
                printf("%c ",arr[i]);
        }       
        printf("\n");

	return 0;
}

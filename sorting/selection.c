#include <stdio.h>
#include <stdlib.h>

void selection_sort(char* arr,int n){
	if (n==0 || n==1){
		return;
	}

	int i=1;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (arr[i]>arr[j]){
				char temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	return;
}



int main(){
	int n;
	printf("Enter dimension for the character array : ");
	scanf("%d",&n);

	char* arr=(char *)malloc(sizeof(char)*n);
	for (int i=0;i<n;i++){
		printf("Enter element %d for the character array : ",i);
		scanf(" %c",&arr[i]);
	}

	printf("------\n");

        printf("The elements of the array created : \n");
        for (int i=0;i<n;i++){
                printf("%c ",arr[i]);
        }
        printf("\n");

        printf("-----\n");

        selection_sort(arr,n);

        printf("The elements of the Sorted array : \n");
        for (int i=0;i<n;i++){
                printf("%c ",arr[i]);
        }
        printf("\n");

        return 0;
}



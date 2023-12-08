#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int linear_search(char* arr,int n,char data){
	if (n==0){
		return INT_MIN;
	}
	for (int i=0;i<n;i++){
		if (arr[i]==data){
			return i;
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

        printf("Index of %c in the array(zero indexing) : %d\n",ch,linear_search(arr,n,ch));


	return 0;
}


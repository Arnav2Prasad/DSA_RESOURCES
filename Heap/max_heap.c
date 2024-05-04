#include <stdio.h>
#include <stdlib.h>


/*
    *------------------------------------------------------------------------------------  
    *                 HEAP
    *
    * ARRAY REPRESENTATION OF BINARY TREE
    *   if node is at index 'i' :
    *           its left child : 2i + 1
    *           its right child : 2i + 2
    *           parent : (i-1)/2
    * 
    * 
    * HEAP is a Complete Binary Tree!
    * A Complete binary tree of height 'h' is a full binary tree
    * upto height 'h-1' and then elements starts filling from left to right
    * 
    *               OR
	* 
    * We can define it in the array , there should not be any empty gaps (gaps 
    * in between elements) 
    * 
    * Height of a Complete Binary Tree is : ln n
    * 
    *           &
    *          / \
    *         &   &
    *        /  \
    *       &    & 
    * 
    * This is a Complete Binary Tree
    * 
    * 
    *           &
    *          /  \
    *         &    &
    *             /  \
    *            &    &
    * 
    * This is not a Complete Binary Tree
    * 
    * 
    * Heap is further classified to 1. Minimum heap
    *                               2. Maximum heap
    * 
    * Duplicates are allowed in heap!
    * height = O(ln n)
    * 
    * 
    * 
    * INSERTION IN HEAP
    * Insert the newly added element at the end of the array , and
    * start comparing it with its parent [ (i-1)/2 ] , if needed
    * swap it
    * The size of the array is incresed by size 1.
    * Time Complexity : O(n ln n)
    * 
    * DELETION IN HEAP
    * We can delete only the 1st element in the heap.
    * For max heap : 1st element refers to the highest priority element!
    * We have to swap this element with the last element
    * of the array and so start performing swapping with
    * its parent if needed.
    * The size of the array is decreased by size 1.
    * Time Complexity : O(n ln n)
    * 
    * 
    * 
    * HEAPSORT
    * For sorting the array we follow the "while" procedure
    * of the deleting the 1st element , swapping it with the last element 
    * and decreasing the length of the array visibility by 1 ,  
    * the swapped element at position 1st will be compared with its child and 
    * so necessary swapping will take place.
    * We will loop this till the array length , So that we get the decreasing array of elements.
    * 
    * Time Complexity : O( n ln n)
    * 
    * 
    * NOTE : direction of adjustment is UPWARDS in both insertion and deletion case
    * 
    * 
    * We used MAXHEAP in 1. subclass_maxheap
    *                    2.  query_maxheap
    *                    3.  search_maxheap
    * 
    * We used maxheap to get the priority of the dataset we will be storing
    * So that user will get the most weighted information(valueable information)
    * of what he is looking for:)
    * -----------------------------------------------------------------------------------------------------
    
*/

typedef struct heap{
	int* arr;
	int size;
	int len;
}heap;

heap* init(int size){
	heap* nn = (heap *)malloc(sizeof(heap));
	if (nn){
		nn->size=size;
		nn->len=0;
		nn->arr = (int *)malloc(sizeof(int)*size);
	}
	return nn;
}

void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}

//max heap
void insert(heap* hp,int data){
	if (hp->size==hp->len){
		return;
	}
	int i = hp->len;
	hp->arr[i] = data ;
	while (i>0 && hp->arr[i] > hp->arr[(i-1)/2]){
		swap(&hp->arr[i],&hp->arr[(i-1)/2]);
		i = (i-1)/2;
	}
	hp->len++;
}

void print(heap* h){
	if (h->size==0){
		return;
	}
	for (int i=0;i<h->size;i++){
		printf("%d ",h->arr[i]);
	}
	printf("\n");
	return;
}

void delete_max(heap* hp){
	if (hp->len==0){
		return;
	}
	int i = hp->len-1;	
	//int data = hp->arr[i];
	swap(&hp->arr[0],&hp->arr[i]);
	int j=0;
	while ( (2*j) + 1 < i){
		int largest = (2*j) + 1;	
		if (((2*j) + 2 < i) && hp->arr[largest] < hp->arr[ (2*j) + 2]){
			largest = (2*j)+2;
		}
		if (hp->arr[j] < hp->arr[largest]){
			swap(&hp->arr[j],&hp->arr[largest]);
		}
		j=largest;
	}
	hp->len--;
}

void heapify(heap* hp,int n){
	for (int i=(n/2)-1;i>=0;i--){
		int j = (2*i)+1;

		while (j<n-1){
			if (hp->arr[j]<hp->arr[j+1]){
				j=j+1;
			}

			if (hp->arr[i] < hp->arr[j]){
				swap(&hp->arr[i],&hp->arr[j]);
				i=j;
				j = (2*i) + 1;
			} else{
				break;
			}
		}
	}
}

int is_heap(heap* hp){
	if (hp->len==0){
		return 1;
	}
	for (int i=0;i<hp->len;i++){
		if ( (2*i)+1 < hp->len && hp->arr[i] < hp->arr[(2*i)+1]){
			return 0;
		}
		if ( (2*i)+2 < hp->len && hp->arr[i] < hp->arr[(2*i)+2]){
                        return 0;
                }
	}
	return 1;
}




int main(){
	heap* hp = init(10);
	
	insert(hp,10);
	insert(hp,20);
	insert(hp,30);
	insert(hp,2);

	print(hp);

	//delete_max(hp);
	
	for (int i=0;i<10;i++){
		delete_max(hp);
		print(hp);
	}
	printf("----\n");
	print(hp);


	heapify(hp,10);
	print(hp);

	printf("%d\n",is_heap(hp));
	return 0;
}
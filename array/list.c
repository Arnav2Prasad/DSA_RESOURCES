#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"

void init(struct array* arnav,int size){
	arnav->arr=(char *)malloc(sizeof(char)*size);
	arnav->size=size;
	arnav->count=0;
	return;
}

int isEmpty(struct array arnav){
	if (arnav.count==0){
		return 1;
	}
	return 0;
}

int isFull(struct array arnav){
	if (arnav.count==arnav.size){
		return 1;
	}
	return 0;
}

void push(struct array* arnav,char data){
	if (isFull(*arnav)){
		return;
	}
	arnav->arr[arnav->count++]=data;
	return;
}
char top(struct array arnav){
	if (isEmpty(arnav)){
		return 'x';
	}
	return arnav.arr[arnav.count-1];
}

void display(struct array arnav){
	if (isEmpty(arnav)){
		return;
	}
	for (int i=0;i<arnav.count;i++){
		printf("%c ",arnav.arr[i]);
	}
	printf("\n");
	return;
}

int length(struct array arnav){
	return arnav.count;
}

void del_end(struct array* arnav){
	if (isEmpty(*arnav)){
		return;
	}
	arnav->count--;
	return;
}

void del_beg(struct array* arnav){
	if (isEmpty(*arnav)){
		return;
	}
	for (int i=0;i<arnav->count-1;i++){
		arnav->arr[i]=arnav->arr[i+1];
	}
	arnav->count--;
	return;
}

void insert_beg(struct array* arnav,char data){
	if (isFull(*arnav)){
		return;
	}
	for (int i=arnav->count;i>0;i--){
		arnav->arr[i]=arnav->arr[i-1];
	}
	arnav->arr[0]=data;
	arnav->count++;
	return;
}





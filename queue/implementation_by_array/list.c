#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init(struct queue* q,int size){
	q->size=size;
	q->count=0;
	q->arr=(char *)malloc(sizeof(char)*size);
	q->start=0;
	return;
}

int isEmpty(struct queue q){
	if (q.count==0){
		return 1;
	}
	return 0;
}

int isFull(struct queue q){
	if (q.size==q.count){
		return 1;
	}
	return 0;
}

void enqueue(struct queue* q,char data){
	if (isFull(*q)){
		return;
	}
	q->arr[q->count++]=data;
	return;
}
char dequeue(struct queue* q){
	if (isEmpty(*q)){
		return 'x';
	}
	char ch=q->arr[q->start++];
	q->count--;
	return ch;
}

void display(struct queue q){
	if (isEmpty(q)){
		return;
	}
	for (int i=q.start;i<q.start+q.count;i++){
		printf("%c ",q.arr[i]);
	}
	printf("\n");
	return;
}

int length(struct queue q){
	return q.count;
}

char peek(struct queue q){
	if (isEmpty(q)){
		return 'x';
	}
	return q.arr[q.start];
}




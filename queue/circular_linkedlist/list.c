#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"

void init(struct queue* q,int size){
	q->arr=(char *)malloc(sizeof(char)*size);
	q->size=size;
	q->count=0;
	q->start=0;
	q->end=0;
}

int length(struct queue q){
	return q.count;
}

int isFull(struct queue q){
	if (q.count==q.size){
		return 1;
	}
	return 0;
}

int isEmpty(struct queue q){
	if (q.count==0){
		return 1;
	}
	return 0;
}

void enqueue(struct queue* q,char data){
	if (isFull(*q)){
		return;
	}
	q->arr[q->end]=data;
	q->end=(q->end+1)%q->size;
	q->count++;
	return;
}

char dequeue(struct queue* q){
	if (isEmpty(*q)){
		return 'x';
	}
	char ch=q->arr[q->start];
	//q->start++;
	q->count--;
	q->start=(q->start+1)%q->size;
	
	
	q->end;
	return ch;
}

void display(struct queue q){
	if (isEmpty(q)){
		return;
	}
	int i=q.start;
	int counter=0;
	while (counter!=q.count){
		printf("%c ",q.arr[i]);
		i=(i+1)%q.size;
		counter++;
	}
	printf("\n");
	return;
}

char peek(struct queue q){
	if (isEmpty(q)){
		return 'x';
	}
	return q.arr[q.start];
}





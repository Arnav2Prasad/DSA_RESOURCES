#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"

void init(struct queue* q){
	q->front=NULL;
	q->tail=NULL;
	q->count=0;
	return;
}

int isEmpty(struct queue q){
	if (q.count==0){
		return 1;
	}
	return 0;
}

void enqueue(struct queue* q,char data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if (temp){
		temp->data=data;
		temp->next=NULL;
	}
	else{
		return;
	}
	if (isEmpty(*q)){
		q->front=temp;
		q->tail=temp;
		q->count++;
		return;
	}
	struct node* curr=q->front;
	while (curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=temp;
	q->tail=temp;
	q->count++;
	return;
}

int size(struct queue q){
	return q.count;
}

char dequeue(struct queue* q){
	if(isEmpty(*q)){
		return 'x';
	}
	if (q->count==1){
		struct node* temp=q->front;
		char ch=temp->data;
		q->front=NULL;
		q->tail=NULL;
		free(temp);
		q->count--;
		return ch;
	}
	struct node* temp=q->front;
	char ch=temp->data;
	q->front=q->front->next;
	free(temp);
	q->count--;
	return ch;
}

void display(struct queue q){
	if (isEmpty(q)){
		return;
	}
	struct node* curr=q.front;
	while (curr!=NULL){
		printf("%c ",curr->data);
		curr=curr->next;
	}
	printf("NULL\n");
	return;
}

int search(struct queue q,char data){
	if (isEmpty(q)){
		return INT_MIN;
	}
	int i=0;
	struct node* curr=q.front;
	while (curr->next!=NULL){
		if (curr->data==data){
			return i;
		}
	}
	return INT_MIN;
}

char peek(struct queue q){
	if (isEmpty(q)){
		return 'x';
	}
	return (q.front)->data;
}

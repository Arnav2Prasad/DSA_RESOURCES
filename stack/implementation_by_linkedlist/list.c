#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"

void init(struct stack* st){
	st->front=NULL;
	st->tail=NULL;
	return;
}

int isEmpty(struct stack st){
	if (st.count==0){
		return 1;
	}
	return 0;
}
void push(struct stack* st,char data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if (temp){
		temp->next=NULL;
		temp->data=data;
	}
	else{
		return;
	}
	if (isEmpty(*st)){
		st->front=temp;
		st->tail=temp;
		st->count++;
		return;
	}
	struct node* curr=st->front;
	while (curr->next!=NULL){
		curr=curr->next;
	}
	st->count++;
	curr->next=temp;
	st->tail=temp;
	return;
}

void display(struct stack st){
	if (isEmpty(st)){
		return;
	}
	struct node* curr=st.front;
	while (curr!=NULL){
		printf("%c ->",curr->data);
		curr=curr->next;
	}
	printf("NULL\n");
	return;
}

char top(struct stack st){
	if (isEmpty(st)){
		return 'x';
	}
	return (st.tail)->data;
}


void pop(struct stack* st){
	if (isEmpty(*st)){
		return;
	}
	if (st->count==1){
		struct node* temp=st->front;
		st->front=NULL;
		st->tail=NULL;
		free(temp);
		return;
	}
	struct node* curr=st->front;
	while (curr->next!=st->tail){
		curr=curr->next;
	}
	struct node* del=st->tail;
	st->tail=curr;
	curr->next=NULL;
	free(del);
	st->count--;
	return;
}

int length(struct stack st){
	return st.count;
}

int search(struct stack st,char data){
	if (isEmpty(st)){
		return INT_MIN;
	}
	struct node* curr=st.front;
	int i=0;
	while (curr->next != NULL){
		if (curr->data==data){
			return i;
		}
		i++;
		curr=curr->next;
	}
	return INT_MAX;
}

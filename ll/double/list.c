#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"

void init(struct list* head){
	head->front=NULL;
	head->tail=NULL;
	return;
}

int isEmpty(struct list head){
	if (head.front==head.tail && head.front==NULL){
		return 1;
	}
	return 0;
}

int size(struct list head){
	if (isEmpty(head)){
		return 0;
	}
	struct node* curr=head.front;
	int i=0;
	while (curr!=NULL){
		i++;
		curr=curr->next;
	}
	return i;
}

void insert_beg(struct list* head,char data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if (temp){
		temp->data=data;
		temp->next=NULL;
		temp->prev=NULL;
	}
	else{
		return;
	}
	if (isEmpty(*head)){
		head->front=temp;
		head->tail=temp;
		return;
	}
	temp->next=head->front;
	head->front->prev=temp;
	(head->front)=temp;
	return;
}

void insert_end(struct list* head,char data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if (temp){
		temp->data=data;
		temp->next=NULL;
		temp->prev=NULL;
	}
	else{
		return;
	}
	if (isEmpty(*head)){
		head->front=temp;
		head->tail=temp;
		return;
	}
	head->tail->next=temp;
	temp->prev=head->tail;
	head->tail=temp;
	return;
}

void del_beg(list* head){
	if (isEmpty(*head)){
		return;
	}
	if (size(*head)==1){
		(head)->front=NULL;
		(head)->tail=NULL;
		return;
	}
	struct node* del=head->front;
	head->front=head->front->next;
	head->front->prev=NULL;
	free(del);
	return;
}

void del_end(struct list* head){
	if (isEmpty(*head)){
		return;
	}
	if (size(*head)==1){
                (head)->front=NULL;
                (head)->tail=NULL;
                return;
        }
	struct node* del=head->tail;
	head->tail=head->tail->prev;
	head->tail->next=NULL;
	free(del);
	return;
}

int search(struct list head,char data){
	if (isEmpty(head)){
		return INT_MIN;
	}
	struct node* curr=head.front;
	int i=0;
	while (curr!=NULL){
		if (curr->data==data){
			return i;
		}
		i++;
		curr=curr->next;
	}
	return INT_MAX;
}

void destroy(struct list* head){
	if (isEmpty(*head)){
		return;
	}
	struct node* curr=head->front;
	while (curr->next!=NULL){
		struct node* del=curr;
		curr=curr->next;
		del->next=NULL;
		del->prev=NULL;
		free(del);
	}
	return;
}


void display(struct list head){
	if (isEmpty(head)){
		return;
	}
	struct node* curr=head.front;
	while (curr!=NULL){
		printf("%c ->",curr->data);
		curr=curr->next;
	}
	printf("NULL\n");
	return;
}

struct list cutmiddle(struct list head){
	struct list p;
	init(&p);
	if (isEmpty(head)){
		return p;
	}
	int i=0;
	if (size(head)%2==0){
		i=size(head)/2;
	}
	else{
		i=(int)size(head)/2;
	}
	struct node* curr=head.front;
	while(i>0){
		curr=curr->next;
		i--;
	}

	while (curr!= NULL){
		insert_end(&p,curr->data);
		curr=curr->next;
	}
	return p;
}





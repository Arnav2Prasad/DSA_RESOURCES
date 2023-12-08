#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "list.h"

void init(struct node** head){
	(*head)=NULL;
	//(*head)->count=0;
	return;
}

int isEmpty(struct node* head){
	if (head==NULL){
		return 1;
	}
	return 0;
}

int size(struct node* head){
	if (isEmpty(head)){
		return 0;
	}
	struct node* curr=head;
	int i=0;
	while (curr!=NULL){
		curr=curr->next;
		i++;
	}
	return i;
}

int search(struct node* head,char data){
	if (isEmpty(head)){
		return INT_MIN;
	}
	struct node* curr=head;
	int i=0;
	while (curr->next!=NULL){
		if (curr->data==data){
			return i;
		}
		i++;
		curr=curr->next;
	}
	return INT_MAX;
}

void del_end(struct node** head){
	if (isEmpty(*head)){
		return;
	}
	if (size(*head)==1){
		(*head)=NULL;
		//(*head)->count=0;
		return;
	}
	struct node* curr=(*head);
	while (curr->next->next != NULL){
		curr=curr->next;
	}
	struct node* del=curr->next;
	curr->next=NULL;
	free(del);
	//(*head)->count--;
	return;
}

void del_beg(struct node** head){
	if (isEmpty(*head)){
		return;
	}
	if (size(*head)==1){
		(*head)=NULL;
		//(*head)->count=0;
		return;
	}
	struct node* del=(*head);
	(*head)=(*head)->next;
	free(del);
	//(*head)->count--;
	return;
}

void insert_beg(struct node** head,char data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if (temp){
		temp->next=NULL;
		temp->data=data;
	}
	else{
		return;
	}
	if (isEmpty(*head)){
		(*head)=temp;
		//(*head)->count++;
		return;
	}
	temp->next=(*head);
	(*head)=temp;
	//(*head)->count++;
	return;
}

void insert_end(struct node** head,char data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if (temp){
		temp->next=NULL;
		temp->data=data;
	}
	else{
		return;
	}
	if (isEmpty(*head)){
                (*head)=temp;
                //(*head)->count++;
                return;
        }
	struct node* curr=(*head);
	while (curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=temp;
	//(*head)->count++;
	return;
}

void display(struct node* head){
	if (isEmpty(head)){
		return;
	}
	struct node* curr=head;
	while (curr!=NULL){
		printf("%c ",curr->data);
		curr=curr->next;
	}
	printf("NULL\n");
	return;
}

void destroy(struct node** head){
	if (isEmpty(*head)){
		return;
	}
	struct node* curr=(*head);
	while (curr->next!=NULL){
		struct node* del=curr;
		curr=curr->next;
		free(del);
	}
	//(*head)->count=0;
	(*head)=NULL;
	return;
}



	
void odd_after_even(struct node* head){
	if (head==NULL){
		return;
	}
	struct node* even=NULL;
	struct node* odd=NULL;
	int i=0;
	//int len=size(head);
	struct node* curr=head;
	while (curr != NULL){
		if (i%2==0){
			insert_end(&even,curr->data);
		}
		else{
			insert_end(&odd,curr->data);
		}
		i++;
		curr=curr->next;
	}

	printf("EVEN : ");
	display(even);

	printf("ODD : ");
	display(odd);

	return;

}









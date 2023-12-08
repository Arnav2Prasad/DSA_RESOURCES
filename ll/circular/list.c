#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
        do{
		i++;
		curr=curr->next;
	}while (curr!=head);
        return i;
}

int search(struct node* head,char data){
        if (isEmpty(head)){
                return INT_MIN;
        }
        struct node* curr=head;
        int i=0;
        do{
		if (curr->data==data){
			return i;
		}
                i++;
                curr=curr->next;
        }while (curr!=head);
        return INT_MAX;
}

void del_end(struct node** head){
        if (isEmpty(*head)){
                return;
        }
        if (size((*head))==1){
                (*head)=NULL;
                //(*head)->count=0;
                return;
        }
        struct node* curr=(*head);
        while (curr->next->next != (*head)){
                curr=curr->next;
        }
        struct node* del=curr->next;
        curr->next=(*head);
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
        struct node* curr=(*head);
	while (curr->next!=(*head)){
		curr=curr->next;
	}
	//struct node* del=curr->next;
	curr->next=(*head)->next;
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
		temp->next=(*head);
                //(*head)->count++;
                return;
        }
	struct node* curr=(*head);
	do{
		curr=curr->next;
	}while (curr!=(*head));
	curr->next=temp;
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
		temp->next=(*head);
                //(*head)->count++;
                return;
        }
        struct node* curr=(*head);
	while (curr->next!=(*head)){
		curr=curr->next;
	}
        curr->next=temp;
	temp->next=(*head);
        //(*head)->count++;
        return;
}
	
void display(struct node* head){
        if (isEmpty(head)){
                return;
        }
        struct node* curr=head;
        do{
                printf("%c ",curr->data);
                curr=curr->next;
        }while (curr!=head);
        printf("NULL\n");
        return;
}

void destroy(struct node** head){
        if (isEmpty(*head)){
                return;
        }
        struct node* curr=(*head);
        do{
                struct node* del=curr;
                curr=curr->next;
                free(del);
        }while (curr!=*head);
        //(*head)->count=0;
        (*head)=NULL;
        return;
}


#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int r;
	int c;
	int n;
	struct node* next;
}node;

void init(struct node** head);
int isEmpty(struct node* head);
void append(struct node** head,int n,int c,int v);
void display(struct node* head);


void init(struct node** head){
	(*head)=NULL;
}

int isEmpty(struct node* head){
	if (head==NULL){
		return 1;
	}
	return 0;
}


void append(struct node** head,int r,int c,int v){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if (temp){
		temp->r=r;
		temp->c=c;
		temp->n=v;
	}
	else{
		return;
	}
	if (isEmpty(*head)){
		(*head)=temp;
		return;
	}
	struct node* curr=(*head);
	while (curr->next != NULL){
		curr=curr->next;
	}
	curr->next=temp;
	return;
}

void display(struct node* head){
	if (isEmpty(head)){
		return;
	}
	struct node* curr=head;
	while (curr != NULL){
		printf(" ( %d %d %d ) -> ",curr->r,curr->c,curr->n);
		curr=curr->next;
	}
	printf("NULL\n");
	return;
}

struct node* add(struct node* h11,struct node* h22){
	struct node* h1=h11;
        struct node* h2=h22;
        struct node* ans;
        init(&ans);
	
	if (h1==NULL && h2==NULL){
		return NULL;
	}
	if (h1==NULL){
		return h2;
	}
	if (h2==NULL){
		return h1;
	}

	
	while (h1 && h2){
	if (h1->r==h2->r){
		if (h1->c==h2->c){
			append(&ans,h1->r,h1->c,h1->n+h2->n);
			h1=h1->next;
			h2=h2->next;
		}
		else if(h1->c > h2-> c){
			append(&ans,h2->r,h2->c,h2->n);
			h2=h2->next;
		}
		else{
			append(&ans,h1->r,h1->c,h1->n);
			h1=h1->next;
		}
	}
	else{
		if(h1->r > h2-> r){
                        append(&ans,h2->r,h2->c,h2->n);
			h2=h2->next;
                }
                else{
                        append(&ans,h1->r,h1->c,h1->n);
			h1=h1->next;
                }
	}
	}
	while (h1){
		append(&ans,h1->r,h1->c,h1->n);
		h1=h1->next;
	}

	while (h2){
		append(&ans,h2->r,h2->c,h2->n);
		h2=h2->next;
	}
	return ans;
}





struct node* sub(struct node* h11,struct node* h22){
        struct node* h1=h11;
        struct node* h2=h22;
        struct node* ans;
        init(&ans);
	
	if (h1==NULL && h2==NULL){
                return NULL;
        }

        if (h1==NULL){
                struct node* h1=h11;
		while (h1){
			append(&ans,h1->r,h1->c,-(h1->n));
			h1=h1->next;
		}
        }
        if (h2==NULL){
                return h1;
        }

        
        while (h1 && h2){
        if (h1->r==h2->r){
                if (h1->c==h2->c){
                        append(&ans,h1->r,h1->c,h1->n-h2->n);
			h1=h1->next;
                        h2=h2->next;
                }
                else if(h1->c > h2-> c){
                        append(&ans,h2->r,h2->c,-(h2->n));
                        h2=h2->next;
                }
                else{
                        append(&ans,h1->r,h1->c,h1->n);
			h1=h1->next;
                }
        }
        else{
                if(h1->r > h2-> r){
                        append(&ans,h2->r,h2->c,-(h2->n));
                        h2=h2->next;
                }
                else{
                        append(&ans,h1->r,h1->c,h1->n);
			h1=h1->next;
                }
        }
        }
        while (h1){
                append(&ans,h1->r,h1->c,h1->n);
                h1=h1->next;
        }

        while (h2){
                append(&ans,h2->r,h2->c,-(h2->n));
                h2=h2->next;
        }
        return ans;
}




int main(){
	int** a=(int **)malloc(sizeof(int)*3);
	for (int i=0;i<3;i++){
		a[i]=(int *)malloc(sizeof(int)*3);
	}

	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}

	int** b=(int **)malloc(sizeof(int)*3);
        for (int i=0;i<3;i++){
                b[i]=(int *)malloc(sizeof(int)*3);
        }

	for (int i=0;i<3;i++){
                for (int j=0;j<3;j++){
                        scanf("%d",&b[i][j]);
                }
        }


	struct node* h1;
	init(&h1);
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			if (a[i][j] != 0){
				append(&h1,i,j,a[i][j]);
			}
		}
	}

	struct node* h2;
        init(&h2);
        for (int i=0;i<3;i++){
                for (int j=0;j<3;j++){
                        if (b[i][j] != 0){
                                append(&h2,i,j,b[i][j]);
                        }
                }
        }

	display(h1);
	printf("---\n");
	display(h2);
	printf("----\n");

	display(add(h1,h2));
	printf("-\n");
	display(sub(h1,h2));
	printf("-------\n");

	return 0;
}



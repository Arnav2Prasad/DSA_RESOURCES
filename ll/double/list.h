typedef struct node{
	char data;
	struct node* next;
	struct node* prev;
}node;

typedef struct list{
	struct node* front;
	struct node* tail;
}list;

void init(struct list* head);
int isEmpty(struct list head);
int size(struct list head);
void insert_beg(struct list* head,char data);
void insert_end(struct list* head,char data);
void del_beg(struct list* head);
void del_end(struct list* head);
int search(struct list head,char data);
void display(struct list head);
void destroy(struct list* head);

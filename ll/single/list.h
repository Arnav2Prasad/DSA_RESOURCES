typedef struct node{
	char data;
	struct node* next;
}node;

void init(struct node** head);
int isEmpty(struct node* head);
int size(struct node* head);
int search(struct node* head,char data);
void del_end(struct node** head);
void del_beg(struct node** head);
void insert_end(struct node** head,char data);
void insert_beg(struct node** head,char data);
void display(struct node* head);
void destroy(struct node** head);


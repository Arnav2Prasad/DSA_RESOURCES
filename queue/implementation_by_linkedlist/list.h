typedef struct node{
	char data;
	struct node* next;
}node;

typedef struct queue{
	struct node* front;
	struct node* tail;
	int count;
}queue;

void init(struct queue* q);
int isEmpty(struct queue q);
void enqueue(struct queue* q,char data);
int size(struct queue q);
char dequeue(struct queue* q);
void display(struct queue q);
int search(struct queue q,char data);


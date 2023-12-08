typedef struct queue{
	char* arr;
	int size;
	int count;
	int start;
}queue;

void init(struct queue* q,int size);
int isEmpty(struct queue q);
int isFull(struct queue q);
void enqueue(struct queue* q,char data);
char dequeue(struct queue* q);
void display(struct queue q);
int length(struct queue q);
char peek(struct queue q);



typedef struct queue{
	char* arr;
	int start;
	int count;
	int size;
	int end;
}queue;

void init(struct queue* q,int size);
int length(struct queue q);
int isFull(struct queue q);
int isEmpty(struct queue q);
void enqueue(struct queue* q,char data);
char dequeue(struct queue* q);
void display(struct queue q);
char peek(struct queue q);


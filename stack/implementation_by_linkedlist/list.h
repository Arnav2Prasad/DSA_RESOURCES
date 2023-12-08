typedef struct node{
	char data;
	struct node* next;
}node;

typedef struct stack{
	struct node* front;
	struct node* tail;
	int count;
}stack;

void init(struct stack* st);
int isEmpty(struct stack st);
void push(struct stack* st,char data);
void display(struct stack st);
char top(struct stack st);
void pop(struct stack* st);
int length(struct stack st);
int search(struct stack st,char data);


typedef struct stack{
	char* arr;
	int size;
	int count;
}stack;

void init(struct stack* st,int size);
int isEmpty(struct stack st);
int isFull(struct stack st);
void push(struct stack* st,char data);
void pop(struct stack* st);
void insert_beg(struct stack* st,char data);
void del_end(struct stack* st);
void del_beg(struct stack *st);
char top(struct stack st);
int length(struct stack st);
int search(struct stack st,char data);
void display(struct stack st);


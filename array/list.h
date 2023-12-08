typedef struct array{
	char* arr;
	int size;
	int count;
}array;

void init(struct array* arnav,int size);
int isEmpty(struct array arnav);
int isFull(struct array arnav);
void push(struct array* arnav,char data);
void pop(struct array* arnav);
char top(struct array arnav);
void display(struct array arnav);
int length(struct array arnav);
void del_end(struct array* arnav);
void del_end(struct array* arnav);
void insert_beg(struct array* arnav,char data);


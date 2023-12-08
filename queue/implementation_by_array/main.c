#include "list.c"

int main(){
	struct queue q;
	init(&q,5);
	enqueue(&q,'a');
	enqueue(&q,'e');
	enqueue(&q,'i');
	enqueue(&q,'o');
	enqueue(&q,'u');
	//enqueue(&q,'w');

	display(q);

	printf("Length : %d\n",length(q));
	printf("Empty : %d\n",isEmpty(q));
	printf("Full : %d\n",isFull(q));

	printf("Peek : %c\n",peek(q));

	printf("Dequeue : %c\n",dequeue(&q));
	printf("Dequeue : %c\n",dequeue(&q));

	display(q);

	printf("Length : %d\n",length(q));
        printf("Empty : %d\n",isEmpty(q));
        printf("Full : %d\n",isFull(q));

	return 0;
}



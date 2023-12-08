#include "list.c"

int main(){
	struct stack st;
	init(&st);
	printf("Empty : %d\n",isEmpty(st));
	push(&st,'a');
	push(&st,'e');
	push(&st,'i');
	push(&st,'o');
	push(&st,'u');

	display(st);

	printf("Top : %c\n",top(st));
	printf("Length : %d\n",length(st));

	pop(&st);
	pop(&st);

	display(st);

	printf("Length : %d\n",length(st));
	printf("Empty : %d\n",isEmpty(st));
	printf("Search : %d\n",search(st,'e'));

	return 0;
}




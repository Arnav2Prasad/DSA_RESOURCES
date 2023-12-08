#include "list.c"

int main(){
	struct array arnav;

	init(&arnav,6);
	printf("Empty : %d\n",isEmpty(arnav));
	printf("Full : %d\n",isFull(arnav));

	insert_beg(&arnav,'a');
	push(&arnav,'e');
	push(&arnav,'i');
	push(&arnav,'o');
	push(&arnav,'u');
	insert_beg(&arnav,'w');

	display(arnav);
	
	printf("Top : %c\n",top(arnav));
        printf("Full : %d\n",isFull(arnav));


	printf("Empty : %d\n",isEmpty(arnav));
        printf("Full : %d\n",isFull(arnav));


	del_end(&arnav);
	del_beg(&arnav);
	
        display(arnav);

        printf("Empty : %d\n",isEmpty(arnav));
        printf("Full : %d\n",isFull(arnav));


	return 0;
}


#include "list.c"

int main(){
	printf("-------\n");
	struct node* head;
	init(&head);
	printf("Empty : %d\n",isEmpty(head));
	printf("Size : %d\n",size(head));

	insert_beg(&head,'e');
	insert_beg(&head,'a');
	insert_end(&head,'k');
	insert_end(&head,'o');
	insert_end(&head,'u');
	insert_end(&head,'v');
	//insert_beg(&head,'a');
	//insert_beg(&head,'a');
	
	display(head);
	printf("Empty : %d\n",isEmpty(head));
        printf("Size : %d\n",size(head));
	printf("Search : %d\n",search(head,'k'));

	del_end(&head);
	del_beg(&head);

	insert_end(&head,'p');
        insert_end(&head,'q');
        insert_end(&head,'r');


	display(head);
        printf("Empty : %d\n",isEmpty(head));
        printf("Size : %d\n",size(head));


	odd_after_even(head);

	return 0;
}

	


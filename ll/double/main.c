#include "list.c"

int main(){
        printf("-------\n");
        struct list head;
        init(&head);
        printf("Empty : %d\n",isEmpty(head));
        printf("Size : %d\n",size(head));

        insert_beg(&head,'e');
        insert_beg(&head,'i');
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

        display(head);
        printf("Empty : %d\n",isEmpty(head));
        printf("Size : %d\n",size(head));

	printf("---\n");
	struct list ans;
	init(&ans);
	ans=cutmiddle(head);
	display(ans);

        return 0;
}



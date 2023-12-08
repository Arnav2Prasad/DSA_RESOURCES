#include "list.c"

int main(){
        struct stack st;
        init(&st,5);

        insert_beg(&st,'a');
        push(&st,'e');
        push(&st,'i');
        push(&st,'o');
        push(&st,'u');

        display(st);

        printf("Search : %d\n",search(st,'i'));

        printf("Full : %d\n",isFull(st));
        printf("Empty : %d\n",isEmpty(st));

        del_end(&st);
        display(st);

        del_beg(&st);
        display(st);

        printf("Full : %d\n",isFull(st));
        printf("Empty : %d\n",isEmpty(st));


        printf("Length  %d\n",length(st));

        return 0;
}


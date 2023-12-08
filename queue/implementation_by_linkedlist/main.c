#include "list.c"

int main(){
        struct queue q;
        init(&q);
        enqueue(&q,'a');
        enqueue(&q,'e');
        enqueue(&q,'i');
        enqueue(&q,'o');
        enqueue(&q,'u');
        //enqueue(&q,'w');

        display(q);

        printf("size : %d\n",size(q));
        printf("Empty : %d\n",isEmpty(q));
        //printf("Full : %d\n",isFull(q));

        printf("Peek : %c\n",peek(q));

        printf("Dequeue : %c\n",dequeue(&q));
        printf("Dequeue : %c\n",dequeue(&q));

        display(q);

        printf("size : %d\n",size(q));
        printf("Empty : %d\n",isEmpty(q));
        //printf("Full : %d\n",isFull(q));

        return 0;
}


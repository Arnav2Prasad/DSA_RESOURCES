#include "list.c"

int main(){
        struct queue q;
        init(&q,5);
        enqueue(&q,'a');
        enqueue(&q,'e');
        enqueue(&q,'i');
        enqueue(&q,'o');
        enqueue(&q,'u');
        display(q);
        printf("SIZE : %d\n",length(q));
        printf("Empty : %d\n",isEmpty(q));
        printf("FULL : %d\n",isFull(q));
        printf("DEQUEUE : %c\n",dequeue(&q));
        printf("DEQUEUE : %c\n",dequeue(&q));

        enqueue(&q,'g');
        enqueue(&q,'h');

        display(q);

        printf("DEQUEUE : %c\n",dequeue(&q));
        printf("DEQUEUE : %c\n",dequeue(&q));
        display(q);

        printf("SIZE : %d\n",length(q));
        printf("Empty : %d\n",isEmpty(q));
        printf("FULL : %d\n",isFull(q));

        printf("PEEK %c\n",peek(q));

        return 0;
}


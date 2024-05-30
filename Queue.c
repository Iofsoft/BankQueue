#include "BankQueue.h"

t_queue createQueue(){
    t_queue queue;
    queue.start=0;
    queue.end=0;
    return queue;
}

void in(t_queue* queue, char* element){
    queue->items[queue->end] = strdup(element);
    queue->end = (queue->end + 1) % MAX_SIZE;
}

char* out(t_queue* queue){
    char* item = queue->items[queue->start];
    queue->start = (queue->start + 1) % MAX_SIZE;
    return item;
}

int is_empty(t_queue *queue){
    if(queue->start == queue->end) return 1;
    return 0;
}

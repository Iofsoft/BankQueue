#include "BankQueue.h"

t_queue createQueue(){
    t_queue queue;
    queue.start=0;
    queue.end=0;
    queue.size=0;
    return queue;
}

void in(t_queue* queue, char* element){
    if(is_full(queue)){
        queue->start = (queue->start+1) % MAX_SIZE;
        queue->size--;
    }
    queue->items[queue->end] = strdup(element);
    queue->end = (queue->end + 1) % MAX_SIZE;
    queue->size++;
}

char* out(t_queue* queue){
    char* item = strdup(queue->items[queue->start]);
    queue->start = (queue->start + 1) % MAX_SIZE;
    queue->size--;
    return item;
}

int is_empty(t_queue *queue){
    return queue->size == 0;
}

int is_full(t_queue* queue) {
    return queue->size == MAX_SIZE;
}

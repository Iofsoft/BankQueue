#include "BankQueue.h"

void append(t_list *list, char* element){
    list->items[list->size] = element;
    list->size++;
}

void print_list(t_list list){
    for(int i = 0; i<list.size; i++) printf("%s", list.items[i]);
}
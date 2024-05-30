
#ifndef BANKQUEUE_H
#define BANKQUEUE_H

    #include<stdio.h>
    #include<stdlib.h>
	#include<string.h>

	#define MAX_SIZE 5

    typedef struct t_queue{
        int start;
        int end;
    	int size;
        char* items[MAX_SIZE];
    }t_queue;

	typedef struct t_list{
		int size;
		char* items[MAX_SIZE*2];
	}t_list;

	t_queue createQueue();
	void in(t_queue* queue, char* element);
	char* out(t_queue* queue);
	int is_empty(t_queue* queue);
	int is_full(t_queue* queue);

	void append(t_list *list, char* element);
	void print_list(t_list list);

	t_list bank_queue();
	char* call_next (t_queue* priority_queue, t_queue* general_queue, int* priority_customers_served);



#endif //BANKQUEUE_H

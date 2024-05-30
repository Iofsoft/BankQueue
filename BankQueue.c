
#include "BankQueue.h"

t_list bank_queue (){
    t_queue priority_queue = createQueue();
    t_queue general_queue = createQueue();
    t_list served_customers;
    served_customers.size = 0;
    char input[40];
    int total_customers_served = 0;
    int priority_customers_served = 0;

    while(input[0] != 'f'){
        fgets(input, sizeof(input), stdin);
        switch(input[0]){
            case 's':
                if(!is_empty(&priority_queue) || !is_empty(&general_queue)){
                    call_next(&priority_queue, &general_queue, &served_customers, &priority_customers_served);
                }
                break;

            case 'p':
                in(&priority_queue, input + 2);
                break;

            case 'g':
                in(&general_queue, input + 2);
                break;

            case 'f' : break;
        }
    }
    return served_customers;
}

void call_next (t_queue* priority_queue, t_queue* general_queue, t_list* served_customers, int* priority_customers_served){
    if(*priority_customers_served >= 3) {
        if(is_empty(general_queue)){
            append(served_customers, out(priority_queue));
            (*priority_customers_served)++;
        }
        else{
            append(served_customers, out(general_queue));
            *priority_customers_served = 0;
        }
        return;
    }

    if(is_empty(priority_queue)){
        append(served_customers, out(general_queue));
        *priority_customers_served = 0;
        return;
    }

    append(served_customers, out(priority_queue));
    (*priority_customers_served)++;
    return;
}


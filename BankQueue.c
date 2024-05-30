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
            case 'p':
                in(&priority_queue, input + 2);
                break;

            case 'g':
                in(&general_queue, input + 2);
                break;

            case 's':
                if(!is_empty(&priority_queue) || !is_empty(&general_queue)){
                    char* next_customer = call_next(&priority_queue, &general_queue, &priority_customers_served);
                    append(&served_customers, next_customer);
                }
                break;

            case 'f' : break;
        }
    }
    return served_customers;
}

char* call_next (t_queue* priority_queue, t_queue* general_queue, int* priority_customers_served){
    if(*priority_customers_served >= 3) {
        if(is_empty(general_queue)){
            (*priority_customers_served)++;
            return out(priority_queue);
        }
        else{
            *priority_customers_served = 0;
            return out(general_queue);
        }
    }

    if(is_empty(priority_queue)){
        *priority_customers_served = 0;
        return out(general_queue);
    }

    (*priority_customers_served)++;
    return out(priority_queue);
}
#include "BankQueue.h"

int main(void){
    t_list served_customers = bank_queue();
    print_list(served_customers);
    return 0;
}

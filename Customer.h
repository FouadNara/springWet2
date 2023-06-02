#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <stdbool.h>


class Customer
{
    
    public:
        Customer(int customer_id, int phone_number)
        :customer_id(customer_id), phone_number(phone_number), expenses(0), undeserved_prize(0), is_member(false){}
        ~Customer();

    
    private:
    int customer_id;
    int phone_number;
    int expenses;
    int undeserved_prize;
    bool is_member;



    
};


#endif // CUSTOMER_H_
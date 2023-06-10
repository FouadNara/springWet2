#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <stdbool.h>

class Customer
{
    
    public:
    Customer(int customer_id, int phone_number)
    :customer_id(customer_id), phone_number(phone_number), expenses(0), undeserved_prize(0), is_member(false){}
    ~Customer() = default;

    int getCustomerID() const;
    int getPhoneNumber() const;
    double getExpenses() const;
    double getUndeservedPrize() const;
    bool isMember() const;

    void setUndeservedPrize(double amount);
    void makeMember();
    void addMonthlyExpenses(double toAdd);
    void resetMember();

    
    private:
    int customer_id;
    int phone_number;
    double expenses;
    double undeserved_prize;
    bool is_member;
};


#endif // CUSTOMER_H_
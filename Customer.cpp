#include "Customer.h"

int Customer::getCustomerID() const
{
    return customer_id;
}

int Customer::getExpenses() const
{
    return expenses;
}

int Customer::getPhoneNumber() const
{
    return phone_number;
}

int Customer::getUndeservedPrize() const
{
    return undeserved_prize;
}

bool Customer::isMember() const
{
    return is_member;
}

void Customer::makeMember()
{
    is_member = true;
}

void Customer::setUndeservedPrize(double amount)
{
    undeserved_prize = amount;
}

void Customer::addMonthlyExpenses(int toAdd)
{
    expenses += toAdd;
}

void Customer :: resetMember()
{
    if(is_member)
    {
        expenses = 0;
        undeserved_prize = 0;
    }
    else
    {
        //ERROR
    }

}
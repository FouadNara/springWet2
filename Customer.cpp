#include "Customer.h"

int Customer::getCustomerID() const
{
    return customer_id;
}

double Customer::getExpenses() const
{
    return expenses;
}

int Customer::getPhoneNumber() const
{
    return phone_number;
}

double Customer::getUndeservedPrize() const
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

void Customer::addMonthlyExpenses(double toAdd)
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
}
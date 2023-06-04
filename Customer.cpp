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
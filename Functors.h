#ifndef FUNCTORS_H_
#define FUNCTORS_H_
//#include "Team.h"
#include "Customer.h"

class CustomerID
{
    public:
    int operator()(const Customer* customer1, const Customer* customer2) const
    {
        if(customer1->getCustomerID() < customer2->getCustomerID())
        {
            return -1;
        }
        if(customer1->getCustomerID() > customer2->getCustomerID())
        {
            return 1;
        }
        return 0;
    }
};


// class PointlessAbility
// {
//     public:
//     int operator()(const Team* team1, const Team* team2) const
//     {
//         if(team1->getTeamSigma() < team2->getTeamSigma())
//         {
//             return -1;
//         }
//         if(team1->getTeamSigma() > team2->getTeamSigma())
//         {
//             return 1;
//         }
//         TeamID temp;
//         int res = temp(team1,team2);
//         return res;
//     }
// };

#endif
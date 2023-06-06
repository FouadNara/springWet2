#ifndef RECORDS_COMPANY_H
#define RECORDS_COMPANY_H

#include "utilesWet2.h"
#include "AVLtree.h"
#include "hashtable.h"
#include "Functors.h"
#include "Node.h"


class RecordsCompany {
  private:
    AVLtree<CustomerID> club_members_tree;
    HashTable customers;
    invertedNode** recordNodesArr;
    int different_records_num;

    // Functor for remove_group
  struct ResetClubMembers
  {
    public:
    void operator()(AVLNode *root)
    {
      if (root)
      {
        Customer *member = root->data;
        member->resetMember();
      }
    }
  };


  public:
    RecordsCompany();
    ~RecordsCompany();
    StatusType newMonth(int *records_stocks, int number_of_records);
    StatusType addCostumer(int c_id, int phone);
    Output_t<int> getPhone(int c_id);
    StatusType makeMember(int c_id);
    Output_t<bool> isMember(int c_id);
    StatusType buyRecord(int c_id, int r_id);
    StatusType addPrize(int c_id1, int c_id2, double  amount);
    Output_t<double> getExpenses(int c_id);
    StatusType putOnTop(int r_id1, int r_id2);
    StatusType getPlace(int r_id, int *column, int *hight);
};

#endif
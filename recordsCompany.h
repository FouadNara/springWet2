#ifndef RECORDS_COMPANY_H
#define RECORDS_COMPANY_H

#include "utilesWet2.h"
// #include "AVLtree.h"
#include "HashTable.h"
// #include "Functors.h"
#include "Node.h"


class RecordsCompany {
  private:
    AVLtree<CustomerID> club_members_tree;
    HashTable customers;
    invertedNode** recordNodesArr;
    int different_records_num;

    struct ResetClubMembers
    {
      public:
      void operator()(AVLNode *root)
      {
        if (root)
        {
          Customer *member = root->data;
          member->resetMember();
          root->extra = 0;
        }
      }
    };
    
    void deleteRecordsArray()
    {
      for(int i=0;i<different_records_num;i++)
      {
          invertedNode* curNode = recordNodesArr[i];
          Record* curRecord = curNode->getRecord();
          delete curRecord;
          delete curNode;
      }
      delete[] recordNodesArr;
    }
    
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
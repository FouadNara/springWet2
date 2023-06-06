#ifndef NODE_H_
#define NODE_H_

//I THINK IT IS BETTER TO WRITE IT AGAIN...

//#include "HashTable.h"
#include "Record.h"
//class Team;

//Node for inverted tree
class invertedNode
{
    public:
    invertedNode(Record* record):record(record),parent(nullptr),height(1),column(record->getRecordID())
    {}
    
    bool isRoot() const;
    Record* getRecord();
    invertedNode* findRoot();
    invertedNode* getParent();

    private:
    Record* record;
    invertedNode* parent;
    int height;
    int column; //column is the r_id with minimum height!,
    // height and column bkono updated bs bel root s7?
};

#endif // NODE_H_
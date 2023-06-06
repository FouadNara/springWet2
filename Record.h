#ifndef RECORD_H_
#define RECORD_H_

#include "Node.h"

class Record{
    public:
    Record(int r_id, int copies): record_id(r_id), copies(copies), numBuyers(0), recordNode(nullptr) {}
    ~Record() = default;
    // ymkn n7taj c'tor bo5d value l copies, 3shan newmonth
    int getRecordID() const;
    int getNumBuyers() const;
    invertedNode* getRecordNode();
    const invertedNode* getRecordNode() const;
    int getRecordHeight() const;
    int getRecordColumn() const;
    
    void buy(); 
    void setRecordNode(invertedNode* recNode);




    private:
    int record_id;
    int copies; // i think we need it for height, not sure  
    int numBuyers;
    invertedNode* recordNode;
};

#endif
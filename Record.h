#ifndef RECORD_H_
#define RECORD_H_

#include "Node.h"

class Record{
    public:
    Record(int r_id): record_id(r_id), numBuyers(0),recordNode(nullptr) {}
    ~Record() = default;

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
    int numBuyers;
    invertedNode* recordNode;
};

#endif
#ifndef RECORD_H_
#define RECORD_H_

class invertedNode;

#include "Node.h"

class Record{
    public:
    Record(int r_id, int copies): record_id(r_id), copies(copies), numBuyers(0), recordNode(nullptr) {}
    ~Record() = default;

    int getRecordID() const;
    int getNumBuyers() const;
    invertedNode* getRecordNode();
    const invertedNode* getRecordNode() const;
    // int getRecordHeight() const;
    // int getRecordColumn() const;
    
    void buy(); 
    void setRecordNode(invertedNode* recNode);




    private:
    int record_id;
    int copies;
    int numBuyers;
    invertedNode* recordNode;
};

#endif
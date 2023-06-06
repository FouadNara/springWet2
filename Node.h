#ifndef NODE_H_
#define NODE_H_

#include "Record.h"

//Node for inverted tree
class invertedNode
{
    public:
    invertedNode(Record* record):record(record),parent(nullptr),height(1),column(record->getRecordID())
    {}
    ///////////// GETTERS ////////////
    bool isRoot() const;
    int getTotalNodes() const;
    int getMinHeightID() const;
    int getTotalRecords() const;
    int getHeight() const;
    Record* getRecord();
    invertedNode* findRoot();
    invertedNode* getParent();

    ///////////// SETTERS ////////////
    void setMinHeightID(int value);
    void setHeight(int value);

    private:
    Record* record;
    invertedNode* parent;
    int height;
    int column; //column is the r_id with minimum height!,
    int min_height_id; // updated just in root
    int total_records;
    int total_nodes;


};

#endif // NODE_H_
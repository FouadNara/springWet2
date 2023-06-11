#ifndef NODE_H_
#define NODE_H_

class Record;

#include "Record.h"

//Node for inverted tree
class invertedNode
{
    public:
    invertedNode(Record* record);
    ///////////// GETTERS ////////////
    bool isRoot() const;
    int getTotalNodes() const;
    int getTotalRecords() const;
    int getHeight() const;
    int getColumn() const;
    Record* getRecord();
    invertedNode* findRoot();
    invertedNode* getParent();

    ///////////// SETTERS ////////////
    void setHeight(int value);
    void setColumn(int value);
    void setParent(invertedNode* newParent);
    void setTotalNodes(int totalNodes);
    void setTotalRecords(int totalRecords);
    void increaseHeight(int extra);
    void decreaseNodes(int num);
    void decreaseRecords(int num);

    private:
    Record* record;
    invertedNode* parent;
    int height;
    int column;
    int total_records;
    int total_nodes;
};

#endif // NODE_H_
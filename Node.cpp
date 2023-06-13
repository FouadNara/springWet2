#include "Node.h"

invertedNode::invertedNode(Record* record)
:record(record),parent(nullptr),height(0),column(record->getRecordID()), 
total_records(record->getRecordCopies()), total_nodes(1) {}

bool invertedNode::isRoot() const
{
    return (parent == nullptr);
}

Record* invertedNode::getRecord()
{
    return record;
}

invertedNode* invertedNode :: getParent()
{
    return parent;
}

invertedNode* invertedNode :: findRoot()
{
    if(isRoot())
    {
        return this;
    }

    invertedNode* temp = this;
    int sumHeights = 0;

    // reaching root 
    while(temp->getParent())
    {
        sumHeights += temp->getHeight();
        temp = temp->getParent();        
    }

    invertedNode* root = temp;

    temp = this;

    while(temp!=root)
    {
        int cur = temp->getHeight();
        temp->setHeight(sumHeights);
        sumHeights -= cur;

        // int cur_nodes = temp->getTotalNodes();
        // int cur_records = temp->getTotalRecords();

        invertedNode* tempParent = temp->getParent();
        temp->setParent(root);
        
        // tempParent->decreaseNodes(cur_nodes);
        // tempParent->decreaseRecords(cur_records);
        
        temp = tempParent;
    }

    return root;
}

int invertedNode :: getTotalNodes() const
{
    return total_nodes;
}

int invertedNode :: getTotalRecords() const
{
    return total_records;
}

void invertedNode :: setHeight(int value) 
{
    height = value;
}

void invertedNode::setParent(invertedNode* newParent)
{
    parent = newParent;
}

void invertedNode::setTotalNodes(int totalNodes)
{
    total_nodes = totalNodes;
}

void invertedNode::setTotalRecords(int totalRecords)
{
    total_records = totalRecords;
}

int invertedNode :: getHeight() const
{
    return height;
}

int invertedNode :: getColumn() const
{
    return column;
}

void invertedNode :: increaseHeight(int extra)
{
    height += extra;
}

void invertedNode :: decreaseNodes(int num)
{
    total_nodes -= num;
}

void invertedNode :: decreaseRecords(int num)
{
    total_records -= num;
}

void invertedNode :: setColumn(int value)
{
    column = value;
}

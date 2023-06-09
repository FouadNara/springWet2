#include "Node.h"

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
    if(!isRoot())
    {
        return parent;
    }
    return nullptr;
}

invertedNode* invertedNode :: findRoot()
{
    if(isRoot())
    {
        return this;
    }

    invertedNode* temp = this;
    int sumHeights = temp->getHeight();

    // reaching root 
    while(temp->getParent())
    {
        temp = temp->getParent();        
    }
    invertedNode* root = temp;

    int cur_height = this->getHeight();

    temp = this->getParent();

    while(temp!=root)
    {
        cur_height += temp->getHeight();

        sumHeights -= temp->getHeight();
        temp->setHeight(temp->getHeight() + sumHeights);
        invertedNode* tempParent = temp->getParent();
        temp->setParent(root);
        temp = tempParent;
    }

    return root;
}

int invertedNode :: getTotalNodes() const
{
    return total_nodes;
}

int invertedNode :: getMinHeightID() const
{
    return min_height_id;
}

void invertedNode :: setMinHeightID(int value)
{
    min_height_id = value;
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

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
    if(!this->isRoot())
    {
        return this->parent;
    }
    //return ??
}
invertedNode* invertedNode :: findRoot()
{
    invertedNode* temp = this;
    if(!(temp->isRoot()))
    {
        return this;
    }

    // reaching root 
    while(temp->getParent())
    {
        temp = temp->getParent();        
    }
    // msh mt2kde sho lazim n3'yer bel kivots
    return temp;

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

int invertedNode :: getHeight() const
{
    return height;
}
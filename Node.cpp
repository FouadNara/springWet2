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
        sumHeights += temp->getHeight();
    }
    invertedNode* root = temp;
    temp = this;

    // msh mt2kde sho lazim n3'yer bel kivots
    //lazm nsir ntr7 el heights 7sb el sumHeights zy bltgrul
    int rootHeight = root->getHeight();
    sumHeights -= rootHeight;
    while(temp!=root)
    {
        sumHeights -= temp->getHeight();
        temp->setHeight(temp->getHeight() + sumHeights);
        invertedNode* tempParent = temp->getParent();
        temp->setParent(root);
        temp = tempParent;
        //la bttlt mt2kd 💀💀💀
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

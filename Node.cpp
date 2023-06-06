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
    return 

}

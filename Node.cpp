#include "Node.h"

bool invertedNode::isRoot() const
{
    return (parent == nullptr);
}

Record* invertedNode::getRecord()
{
    return record;
}

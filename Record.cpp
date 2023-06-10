#include "Record.h"

int Record::getRecordID() const
{
    return record_id;
}

int Record::getNumBuyers() const
{
    return numBuyers;
}

invertedNode* Record::getRecordNode()
{
    return recordNode;
}

const invertedNode* Record::getRecordNode() const
{
    return recordNode;
}

void Record::buy()
{
    numBuyers += 1;
}

void Record::setRecordNode(invertedNode* recNode)
{
    recordNode = recNode;
}

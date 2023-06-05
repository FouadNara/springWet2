#include "HashTable.h"
#include "Node.h"


int HashTable::getSize() const
{
    return size;
}

bool HashTable::isCompressed() const
{
    return numOfPlayers == size;
}

Customer* HashTable::search(int customerID) const
{
    int index = hash(customerID);
    if(table[index]->isEmpty())
    {
        return nullptr;
    }

    AVLNode* customerNode_ptr = table[index]->find_by_id(customerID);
    if(customerNode_ptr)
    {
        return (customerNode_ptr->data);
    }

    return nullptr;
}

double HashTable::getLoadFactor() const
{
    return numOfPlayers/size;
}

void HashTable::insert(int customerID, Customer* customer)
{
    int index = hash(customerID);
    table[index]->insert(customer);
    numOfPlayers += 1;
    if(isCompressed())
    {
        resize(); //should delete old linkedlists
    }
}

void HashTable::deleteHash()
{
    for(int i=0;i<getSize();i++)
    {
        AVLtree<CustomerID>* tree = table[i];
        if(tree)
        {
            tree->deleteDataClear();
            table[i] = nullptr;
            delete tree;
        }
    }
    delete[] table;
}


HashTable::~HashTable()
{
    deleteHash();
}
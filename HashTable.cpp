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
    // Node<Customer*>* temp = table[index]->getHead();
    // while(temp)
    // {
    //     if(temp->data->getCustomerID() == customerID)
    //     {
    //         return temp->data;
    //     }
    //     temp=temp->next;
    // }
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
        LinkedList<Player*>* list = table[i];
        if(list)
        {
            Node<Player*>* temp = list->getHead();
            while(temp)
            {
                Player* player_ptr = temp->data;
                invertedNode* playerNode = player_ptr->getPlayerNode();
                playerNode->setParent(nullptr);
                playerNode->nullifyPlayer();
                player_ptr->setPlayerNode(nullptr);
                delete playerNode;
                delete player_ptr;
                temp = temp->next;
            }
            table[i] = nullptr;
            list->clearList();
            delete list;
        }
    }
    delete[] table;
}


HashTable::~HashTable()
{
    deleteHash();
}
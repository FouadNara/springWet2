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

Player* HashTable::search(int playerID) const
{
    int index = hash(playerID);
    if(table[index]->isEmpty())
    {
        return nullptr;
    }
    Node<Player*>* temp = table[index]->getHead();
    while(temp)
    {
        if(temp->data->getPlayerID() == playerID)
        {
            return temp->data;
        }
        temp=temp->next;
    }
    return nullptr;
}

double HashTable::getLoadFactor() const
{
    return numOfPlayers/size;
}

void HashTable::insert(int playerID, Player* player)
{
    int index = hash(playerID);
    table[index]->insert(player);
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
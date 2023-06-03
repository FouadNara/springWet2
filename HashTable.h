#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include "Player.h"
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class invertedNode;

#define PRIME 11

//Chain Hashing Dynamic hashTable
class HashTable 
{
    public:
    HashTable():size(PRIME),numOfPlayers(0)
    {
        table = new LinkedList<Player*>*[size];
        for(int i=0;i<size;i++)
        {
            LinkedList<Player*>* tempList = new LinkedList<Player*>();
            table[i] = tempList;
        }
    }
    ~HashTable();

    void deleteHash();

    void insert(int playerID, Player* player);
    int getSize() const;
    double getLoadFactor() const;


    bool isCompressed() const;
    Player* search(int playerID) const;

    private:
    int size;
    int numOfPlayers;
    LinkedList<Player*>** table;

    //hash function
    int hash(int playerID) const
    {
        return playerID % size;
    }

    //resize hashTable by 2
    void resize()
    {
        int newSize = 2*size;

        LinkedList<Player*>** tempTable;
        tempTable = new LinkedList<Player*>*[newSize];
        for(int i=0;i<newSize;i++)
        {
            tempTable[i] = new LinkedList<Player*>();
        }

        for(int i=0;i<size;++i)
        {
            LinkedList<Player*>* list_ptr = table[i];
            if(table[i]->isEmpty())
            {
                table[i] = nullptr;
                delete list_ptr;
                continue;
            }
            Node<Player*>* tempHead = list_ptr->getHead();
            while(tempHead)
            {
                Player* curPlayer_ptr = tempHead->data;
                tempHead->data = nullptr;
                int newIndex = curPlayer_ptr->getPlayerID() % newSize;
                tempTable[newIndex]->insert(curPlayer_ptr);
                tempHead=tempHead->next;
            }
            table[i] = nullptr;
            list_ptr->clearList();
            delete list_ptr;
        }

        delete[] table;
        table = new LinkedList<Player*>*[newSize];
        for(int i=0;i<newSize;++i)
        {
            table[i] = tempTable[i];
            tempTable[i] = nullptr;
        }

        size = newSize;
        delete[] tempTable;
    }
};


#endif
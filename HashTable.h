#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "AVLtree.h"
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
        table = new AVLtree<Customer*>*[size];
        for(int i=0;i<size;i++)
        {
            AVLtree<Customer*>* tempTree = new AVLtree<Customer*>();
            table[i] = tempTree;
        }
    }
    ~HashTable();

    void deleteHash();

    void insert(int customerID, Customer* customer);
    int getSize() const;
    double getLoadFactor() const;


    bool isCompressed() const;
    Customer* search(int customerID) const;

    private:
    int size;
    int numOfPlayers;
    AVLtree<Customer*>** table;

    //hash function
    int hash(int playerID) const
    {
        return playerID % size;
    }

    //resize hashTable by 2
    void resize()
    {
        int newSize = 2*size;

        AVLtree<Customer*>** tempTable;
        tempTable = new AVLtree<Customer*>*[newSize];
        for(int i=0;i<newSize;i++)
        {
            tempTable[i] = new AVLtree<Customer*>*();
        }

        for(int i=0;i<size;++i)
        {
            AVLtree<Customer*>* list_ptr = table[i];
            if(table[i]->isEmpty())
            {
                table[i] = nullptr;
                delete list_ptr;
                continue;
            }
            Node<Customer*>* tempHead = list_ptr->getHead();
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
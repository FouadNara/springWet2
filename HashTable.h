#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "Functors.h"
// #include <stdio.h>
// #include <iostream>
using std::cout;
using std::endl;

#define PRIME 11

//Chain Hashing Dynamic hashTable
class HashTable 
{
    public:
    HashTable():size(PRIME),numOfPlayers(0)
    {
        table = new AVLtree<CustomerID>*[size];
        for(int i=0;i<size;i++)
        {
            AVLtree<CustomerID>* tempTree = new AVLtree<CustomerID>();
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

    class RehashTreeFunctor
    {
        public:
        RehashTreeFunctor(int newSize, AVLtree<CustomerID>** tempTable):newSize(newSize), tempTable(tempTable)
        {}
        
        void operator()(AVLNode* customer)
        {
            int newIndex = calcNewIndex(customer->data);
            tempTable[newIndex]->insert(customer->data);
        }

        int calcNewIndex(Customer* customer)
        {
            return customer->getCustomerID() % newSize;
        }
        private:
        int newSize;
        AVLtree<CustomerID>** tempTable;
    };

    private:
    int size;
    int numOfPlayers;
    AVLtree<CustomerID>** table;

    //hash function
    int hash(int playerID) const
    {
        return playerID % size;
    }

    //resize hashTable by 2
    void resize()
    {
        int newSize = 2*size;

        AVLtree<CustomerID>** tempTable;
        tempTable = new AVLtree<CustomerID>*[newSize];
        for(int i=0;i<newSize;i++)
        {
            tempTable[i] = new AVLtree<CustomerID>();
        }

        for(int i=0;i<size;++i)
        {
            AVLtree<CustomerID>* tree_ptr = table[i];
            if(table[i]->isEmpty())
            {
                table[i] = nullptr;
                delete tree_ptr;
                continue;
            }

            RehashTreeFunctor func(newSize, tempTable);
            table[i]->inOrder(func);
            
            table[i]->treeClear();
            table[i] = nullptr;
            delete tree_ptr;
        }

        delete[] table;
        table = new AVLtree<CustomerID>*[newSize];
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
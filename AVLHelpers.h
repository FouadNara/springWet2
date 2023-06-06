#ifndef AVLHELPERS_H_
#define AVLHELPERS_H_

#include <assert.h>
#include "Customer.h"
//#include "Functors.h"

int maxNum(int a, int b);

int absNum(int num);

    struct AVLNode
    {
        Customer* data;
        AVLNode *left_son;
        AVLNode *right_son;
        AVLNode *father;
        int height;
        int id;
        double extra;
        explicit AVLNode(Customer* customer, int id) : data(customer), left_son(nullptr), right_son(nullptr), father(nullptr), height(0), id(id), extra(0) {}
        int getID() const
        {
            return id;
        }
        ~AVLNode()=default;
    };

    int getHeightAux(AVLNode *node);

    AVLNode *newAVLNode(Customer* data);

    AVLNode *rightRotateAux(AVLNode *root);

    AVLNode *leftRotateAux(AVLNode *root);


    void minDiffUtil(AVLNode* ptr, int key, int& min_diff, int& min_diff_key, bool Min);
    
    //returns balance for node (left - right)
    int getBalanceFactorAux(AVLNode *node);

    AVLNode *rebalanceAux(AVLNode *node);


    AVLNode *getMinNodeAux(AVLNode *tree);


    AVLNode *getMaxNodeAux(AVLNode *tree);

    void swapFatherSonsAux(AVLNode *father, AVLNode *son);

    bool swapNodesAux(AVLNode *node1, AVLNode *node2);

    AVLNode * overtakeAux(AVLNode *root);
  
    AVLNode *updatePathAux(AVLNode *node);
    
    void updateHeightAux(AVLNode *node);


    AVLNode *find_by_idAux(AVLNode *tree, int id) ;

    template <typename FO>
    void postOrderAux(AVLNode *root, FO doSomething);

    class DeleteFunctor
    {
        public:
        void operator()(AVLNode *root)
        {
            if(root)
            {
                delete (root);
            }
            root = nullptr;
        }
    };

    class DeleteDataFunctor
    {
        public:
        void operator()(AVLNode *root)
        {
            if(root)
            {
                delete (root->data);
                delete (root);
            }
            root = nullptr;
        }
    };

    //clears tree post order
    void destroyAux(AVLNode *root);

    void deleteDataAux(AVLNode *root);


    AVLNode* cloneAux(AVLNode* to_clone, AVLNode* father = nullptr);

    AVLNode *createTreeFromSortedArrayAux(Customer* arr[],int start, int end);

#endif
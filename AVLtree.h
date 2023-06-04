#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;
#include "AVLHelpers.h"


    //insert new node recursively
    // return root
    template <typename Compare>
    AVLNode *insertAux(AVLNode *root, Customer* data)
    {

        Compare comp;
        if (root == nullptr)
            return (newAVLNode(data));

        root->extra += 1;
        if (comp(data, root->data) < 0)
        {
            root->left_son = insertAux<Compare>(root->left_son, data);
            // Set father of root of left subtree
            root->left_son->father = root;
        }
        else if (comp(data, root->data) > 0)
        {
            root->right_son = insertAux<Compare>(root->right_son, data);
            // Set father of root of right subtree
            root->right_son->father = root;
        }

        root->height = 1 + maxNum(getHeightAux(root->left_son), getHeightAux(root->right_son));

        //return root after balance
        return rebalanceAux(root);
    }
    


    template <typename Compare>
    AVLNode *deleteNodeAux(AVLNode *root, const Customer* toDelete)
    {
        if (root == nullptr)
        {
            return root;
        }

        Compare comp;
        AVLNode * overtake_res =nullptr;
        while(root && comp(toDelete, root->data) != 0)
        {
            root->extra -= 1;
            if (comp(toDelete, root->data) < 0)
            {
                root=root->left_son;
            }
            else if (comp(toDelete, root->data) > 0)
            {
                root= root->right_son;
            }
        }

        // node with only one child or no child
        if ((root->left_son == nullptr) || (root->right_son == nullptr))
        {
            overtake_res=overtakeAux(root);
        }
        else
        {
            AVLNode *temp = getMinNodeAux(root->right_son);
            swapNodesAux(root,temp);   
            overtake_res=overtakeAux(root);
        }
        AVLNode *father=root->father;
        delete (root);
        if(overtake_res)
        {
            return updatePathAux(overtake_res);
        } 
        return updatePathAux(father);
    }
    

    
    template <typename Compare>
    AVLNode *findAux(AVLNode *tree, const Customer* data)
    {
        Compare comp;
        if (tree == nullptr || comp(data, tree->data) == 0)
        {
            return tree;
        }
        if (comp(data, tree->data) < 0)
        {
            return findAux<Compare>(tree->left_son, data);
        }
        return findAux<Compare>(tree->right_son, data);
    }

  


    template <typename FO>
    void inOrderAux(AVLNode *root, FO& doSomething)
    {
        if (root != nullptr)
        {
            inOrderAux(root->left_son, doSomething);
            doSomething(root);
            inOrderAux(root->right_son, doSomething);
        }
    }


    template <typename Compare>
    class AVLtree
    {
        private:
        AVLNode* findParentAux(AVLNode* root, const Customer* child)
        {
            if(root->left_son == nullptr && root->right_son == nullptr)
            {
                return root;
            }

            Compare comp;
            int res = comp(root->data, child);
            if(res < 0)
            {
                return findParentAux(root->right_son, child);
            }
            //cannot be equal
            return findParentAux(root->left_son, child);
        }

        public:
        AVLNode *root;
        AVLNode *max;
        int size;

        AVLtree() : root(nullptr),max(nullptr),size(0) {}

        ~AVLtree()
        {
            destroyAux(root);
            root = nullptr;
            max=nullptr;
        }        
        
        AVLtree(const AVLtree& to_copy) : root(nullptr),max(nullptr),size(to_copy.size)
        {
            root= cloneAux(to_copy.root);
            max=getMaxNodeAux(root);
        }
        
        AVLtree& operator=(const AVLtree& tree)
        {
            if(this == &tree)
                return *this;
            AVLNode* clone = nullptr;
            try
            {
                clone = cloneAux(tree.root);
            }
            catch(std::bad_alloc& e)
            {
                destroyAux(clone);
                return *this;
            }
            destroyAux(root);
            root=clone;
            max=getMaxNodeAux(root);
            size=tree.size;
            return *this;
        }

        int getHeight()
        {
            return getHeightAux(root);
        }

        void rightRotateAt(const Customer* data)
        {
            root = rightRotateAux(findAux<Compare>(root, data));
        }

        void leftRotateAt(const Customer* data)
        {
            root = leftRotateAux(findAux<Compare>(root, data));
        }

        int getBalanceFactorAt(const Customer* data)
        {
            return getBalanceFactorAux(findAux<Compare>(root, data));
        }

        void rebalanceAt(const Customer* data)
        {
            root = rebalanceAux(findAux<Compare>(root, data));
        }

        AVLNode *getMinNode()
        {
            return getMinNodeAux(root);
        }

        AVLNode *getMaxNode()
        {
            return max;
        }
        
        AVLNode *find(const Customer* data) 
        {
            return findAux<Compare>(root, data);
        }

        AVLNode *find_by_id(int id)
        {
            return find_by_idAux(root, id);
        }

        void insert(Customer* data)
        {
            if(!find(data))
            {
                size++;
            }  
            root = insertAux<Compare>(root, data);
            max=getMaxNodeAux(root);
        }

        void remove(const Customer* toDelete)
        {
            if(find(toDelete))
            {
                size--;
                root = deleteNodeAux<Compare>(root, toDelete);
                max = getMaxNodeAux(root);
            }  
        }
           


        template <typename FO>
        void inOrder(FO doSomething)
        {
            inOrderAux(root, doSomething);
        }

        template <typename FO>
        void postOrder(FO doSomething)
        {
            postOrderAux(root, doSomething);
        }
        
        AVLNode *getRoot()
        {
            return this->root;
        }
        
        bool isEmpty()
        {
            return size==0;
        }

        int getSize()
        {
            return size;
        }
        
        void treeClear()
        {
            destroyAux(root);
            root=nullptr;
            max=nullptr;
            size=0;
        }

        void deleteDataClear()
        {
            deleteDataAux(root);
            root=nullptr;
            max=nullptr;
            size=0;
        }

        int get_ith_position(int i) const
        {
            AVLNode* temp = root;
            return get_ith_positionAux(temp, i);
        }

        int get_ith_positionAux(AVLNode* root, int i) const
        {            
            int current_index = 0;
            if(root->left_son)
            {
                current_index = root->left_son->extra;
            }
            if(current_index > i-1)
            {
                return get_ith_positionAux(root->left_son, i);
            }
            if(current_index == i-1)
            {
                return root->data->getCustomerID();
            }
            if(current_index < i-1)
            {
                if(root->right_son)
                {
                    return get_ith_positionAux(root->right_son, i - current_index - 1);
                }

            }
            return -1;
        }
    };
    
#endif //AVL_TREE_H_
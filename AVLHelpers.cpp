#include "AVLHelpers.h"
// using std::cout;
// using std::endl;

int getHeightAux(AVLNode *node)
{
    if (node == nullptr)
        return -1;
    return node->height;
}

int maxNum(int a, int b)
{
    return a > b ? a : b;
}

int absNum(int num)
{
    return num >= 0 ? num : (-1) * num;
}

    AVLNode *newAVLNode(Customer* data)
    {
        AVLNode *node = new AVLNode(data, data->getCustomerID());
        return (node);
    }

    AVLNode *rightRotateAux(AVLNode *root)
    {
        AVLNode *new_root = root->left_son;

        AVLNode *rootRight = root->right_son;
        AVLNode *newRight = new_root->right_son;
        AVLNode *newLeft = new_root->left_son;
        int rootRightExtra = 0, newRightExtra = 0, newLeftExtra = 0;

        if(rootRight)
        {
            rootRightExtra = rootRight->extra;
        }
        if(newRight)
        {
            newRightExtra = newRight->extra;
        }
        if(newLeft)
        {
            newLeftExtra = newLeft->extra;
        }
        root->extra = rootRightExtra + newRightExtra + 1;
        new_root->extra = root->extra + newLeftExtra + 1;

        root->left_son = new_root->right_son;

        if (new_root->right_son != nullptr)
        {
            new_root->right_son->father = root;
        }
        new_root->father = root->father;
        if (root->father != nullptr)
        {
            if (root == root->father->right_son)
            {
                root->father->right_son = new_root;
            }
            else
            {
                root->father->left_son = new_root;
            }
        }
        new_root->right_son = root;
        root->father = new_root;

        // Update heights
        root->height = maxNum(getHeightAux(root->left_son),
                           getHeightAux(root->right_son)) + 1;
        new_root->height = maxNum(getHeightAux(new_root->left_son),
                               getHeightAux(new_root->right_son)) + 1;

        return new_root;
    }
    
    AVLNode *leftRotateAux(AVLNode *root)
    {
        AVLNode *new_root = root->right_son;

        AVLNode *rootLeft = root->left_son;
        AVLNode *newRight = new_root->right_son;
        AVLNode *newLeft = new_root->left_son;
        int rootLeftExtra = 0, newRightExtra = 0, newLeftExtra = 0;

        if(rootLeft)
        {
            rootLeftExtra = rootLeft->extra;
        }
        if(newRight)
        {
            newRightExtra = newRight->extra;
        }
        if(newLeft)
        {
            newLeftExtra = newLeft->extra;
        }
        root->extra = rootLeftExtra + newLeftExtra+ 1;
        new_root->extra = root->extra + newRightExtra + 1;


        root->right_son = new_root->left_son;
        if (new_root->left_son != nullptr)
        {
            new_root->left_son->father = root;
        }
        new_root->father = root->father;
        if (root->father != nullptr)
        {
            if (root == root->father->left_son)
            {
                root->father->left_son = new_root;
            }
            else
            {
                root->father->right_son = new_root;
            }
        }
        new_root->left_son = root;
        root->father = new_root;

        // Update heights
        root->height = maxNum(getHeightAux(root->left_son),
                           getHeightAux(root->right_son)) + 1;
        new_root->height = maxNum(getHeightAux(new_root->left_son),
                               getHeightAux(new_root->right_son)) + 1;
        
        return new_root;
    }

    
    //returns balance for node (left - right)
    int getBalanceFactorAux(AVLNode *node) 
    {
        if (node == nullptr)
            return 0;
        return getHeightAux(node->left_son) - getHeightAux(node->right_son);
    }

    AVLNode *rebalanceAux(AVLNode *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        int balance = getBalanceFactorAux(node);
        int left_son_balance = getBalanceFactorAux(node->left_son);
        int right_son_balance = getBalanceFactorAux(node->right_son);

        // there are 4 cases
        // LL
        if ((balance > 1) && (left_son_balance >= 0))
        {
            return rightRotateAux(node);
        }

        // LR
        if ((balance > 1) && (left_son_balance == -1))
        {
            node->left_son = leftRotateAux(node->left_son);
            return rightRotateAux(node);
        }

        // RR
        if ((balance < -1) && (right_son_balance <= 0))
        {
            return leftRotateAux(node);
        }

        // RL
        if ((balance < -1) && (right_son_balance == 1))
        {
            node->right_son = rightRotateAux(node->right_son);
            return leftRotateAux(node);
        }
        return node;
    }

    AVLNode *getMinNodeAux(AVLNode *tree)
    {
        if (tree == nullptr)
        {
            return nullptr;
        }
        AVLNode *current = tree;

        while (current->left_son != nullptr)
        {
            current = current->left_son;
        }
        return current;
    }


    AVLNode *getMaxNodeAux(AVLNode *tree)
    {
        if (tree == nullptr)
            return nullptr;
        AVLNode *current = tree;

        while (current->right_son != nullptr)
        {
            current = current->right_son;
        }
        return current;
    }

    void swapFatherSonsAux(AVLNode *father, AVLNode *son)
    {
        if (father == nullptr || son == nullptr)
        {
            return;
        }

        AVLNode* father_father=father->father;
        AVLNode* son_father=son->father;

        AVLNode* father_left_son=father->left_son;
        AVLNode* son_left_son=son->left_son;

        AVLNode* father_right_son=father->right_son;
        AVLNode* son_right_son=son->right_son;
        
        if(father==son_father)
        {   
            if (father_father)
            {
                //father is a right son
                if (father_father->right_son==father)
                {
                    father_father->right_son=son;
                }
                else //father is a left son
                {
                    father_father->left_son=son;
                }
            }           
                
            if (son_father->right_son==son)
            {
                son->right_son=father;
                son->left_son=father_left_son;
                if(father->left_son)
                {
                    father->left_son->father=son;
                } 
            }
            else //son is a left son
            {

                son->right_son=father_right_son;
                son->left_son=father;
                if(father->right_son)
                {
                    father->right_son->father=son;
                } 
            }        
            father->father=son;
            father->right_son=son_right_son;
            if(son_right_son)
            {
                son_right_son->father=father;
            } 
            father->left_son=son_left_son;
            if(son_left_son)
            {
                son_left_son->father=father;
            } 
            son->father=father_father;
        }
    }

    bool swapNodesAux(AVLNode *node1, AVLNode *node2)
    {
        if (node1 == nullptr || node2 == nullptr)
        {
            return false;
        }

        AVLNode* node1_father=node1->father; 
        AVLNode* node2_father=node2->father; 

        AVLNode* node1_left_son=node1->left_son; 
        AVLNode* node2_left_son=node2->left_son; 

        AVLNode* node1_right_son=node1->right_son; 
        AVLNode* node2_right_son=node2->right_son; 

        int node1_height=node1->height;
        int node2_height=node2->height;
        int node1_extra=node1->extra;
        int node2_extra=node2->extra;

        node1->height=node2_height;
        node2->height=node1_height;
        node1->extra=node2_extra;
        node2->extra=node1_extra;

        //node1 is node2's father
        if(node1==node2_father)
        {
            swapFatherSonsAux(node1, node2);
            return true;
        }
        //node2 is node1's father
        else if(node2==node1_father)
        {
            swapFatherSonsAux(node2, node1);
            return true;
        }
        //otherwise
        else
        {

             if (node1_father) //node1 is a son
            {
                //node1 is a right son
                if (node1_father->right_son==node1)
                {
                    node1_father->right_son=node2;
                }
                else //father is a left son
                {
                    node1_father->left_son=node2;
                }
            }
            if (node2_father) //node2 is a son
            {
                //node2 is a right son
                if (node2_father->right_son==node2)
                {
                    node2_father->right_son=node1;
                }
                else //node2 is a left son
                {
                    node2_father->left_son=node1;
                }
            }
            node1->right_son=node2_right_son;
            if(node2_right_son)
            {
                node2_right_son->father=node1;
            } 
            node1->left_son=node2_left_son;
            if(node2_left_son)
            {
                node2_left_son->father=node1;
            } 
            node1->father=node2_father;

            node2->right_son=node1_right_son;
            if(node1_right_son)
            {
                node1_right_son->father=node2;
            } 
            node2->left_son=node1_left_son;
            if(node1_left_son)
            {
                node1_left_son->father=node2;
            } 
            node2->father=node1_father;
        
           return true; 
        }
    }


    AVLNode * overtakeAux(AVLNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        
        if ((root->left_son == nullptr) || (root->right_son == nullptr))
            {
                AVLNode *temp = root->left_son ? root->left_son : root->right_son;
                if (temp)
                {             
                    temp->father=root->father;
                }
                if(root->father)
                {
                    if(root->father->right_son == root)
                    {
                        root->father->right_son= temp;
                    }
                    else
                    {
                        root->father->left_son= temp;
                    }
                }
                else
                {
                    return temp;
                }     
            }
        return nullptr;
    }
  
    AVLNode *updatePathAux(AVLNode *node)
    {
        AVLNode * prev = node;
        while (node)
        {
            // cout<<node->extra<<endl;
            prev=node;
            node->height = 1 +maxNum(getHeightAux(node->left_son),getHeightAux(node->right_son));
            int leftExtra=0,rightExtra=0;
            if(node->left_son)
            {
                leftExtra = node->left_son->extra;
            }
            if(node->right_son)
            {
                rightExtra = node->right_son->extra;
            }
            node->extra = leftExtra + rightExtra + 1;
            rebalanceAux(node);
            node=node->father;
        }
        return prev;
    }

    void updateHeightAux(AVLNode *node)
    {
        if(node)
        {
            node->height = 1 +maxNum(getHeightAux(node->left_son), getHeightAux(node->right_son));
        }
    }


    AVLNode *find_by_idAux(AVLNode *tree, int id) 
    {
        if (tree == nullptr || id == tree->getID())
        {
            return tree;
        }
        int curr_id = tree->getID();
        if (id < curr_id)
        {
            return find_by_idAux(tree->left_son, id);
        }
        return find_by_idAux(tree->right_son, id);
    }

    template <typename FO>
    void postOrderAux(AVLNode *root, FO doSomething)
    {
        if (root != nullptr)
        {
            postOrderAux(root->left_son, doSomething);
            postOrderAux(root->right_son, doSomething);
            doSomething(root);
        }
    }

    void destroyAux(AVLNode *root)
    {
        DeleteFunctor del;
        postOrderAux(root, del);
        root = nullptr;
    }

    void deleteDataAux(AVLNode *root)
    {
        DeleteDataFunctor del;
        postOrderAux(root, del);
        root = nullptr;
    }


    AVLNode* cloneAux(AVLNode* to_clone, AVLNode* father)
    {
        if (!to_clone)
        {
            return to_clone;
        }
        AVLNode* root = newAVLNode(to_clone->data);
        root->father = father;
        root->height = to_clone->height;
        root->left_son = cloneAux(to_clone->left_son, root);
        root->right_son = cloneAux(to_clone->right_son, root);
        return root;
    }



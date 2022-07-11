/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
BinaryTreeNode<int>* inorderSuccessor(BinaryTreeNode<int>* root,
int p)
{
    BinaryTreeNode<int>* successor=NULL;
    while(root!=NULL)
    {
        if(root->data<=p)
        {
            root=root->right;
        }
        else
        {
            successor=root;
            root=root->left;
        }
    }
    return successor;
}

BinaryTreeNode<int>* inorderPredecessor(BinaryTreeNode<int>* root,
int p)
{
    BinaryTreeNode<int>* predecessor=NULL;
    while(root!=NULL)
    {
        if(root->data>=p)
        {
            root=root->left;
        }
        else
        {
            predecessor=root;
            root=root->right;
        }
    }
    return predecessor;
}


pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    BinaryTreeNode<int>* pred=inorderPredecessor(root, key);
    BinaryTreeNode<int>* suc=inorderSuccessor(root, key);
    pair<int, int> p=make_pair(-1, -1);
    if(pred) p.first=pred->data;
    if(suc) p.second=suc->data;
    return p;
}

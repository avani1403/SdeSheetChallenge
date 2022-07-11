/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
class BSTiterator
{
    public:
    stack<TreeNode<int>* > myStack;
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushAll(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int>* temp = myStack.top();
        myStack.pop();
        pushAll(temp -> right);
        return temp -> data;
    }

    bool hasNext()
    {
        // write your code here
        return !myStack.empty();
    }
    
    void pushAll(TreeNode<int>* root)
    {
       
        //for(; root != NULL; myStack.push(root), root = root -> left);
        while(root)
        {
            myStack.push(root);
            root = root -> left;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/

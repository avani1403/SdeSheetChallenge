/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>
class BSTIterator{
  stack<BinaryTreeNode<int>*> myStack;
    //reverse -> true means -> before
    //reverse -> false means -> next
    bool reverse = true;
    public:
    BSTIterator(BinaryTreeNode<int>* root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
    
    int next()
    {
        BinaryTreeNode<int>* temp = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(temp -> right);
        else pushAll(temp -> left);
        return temp -> data;
    }
    
    void pushAll(BinaryTreeNode<int>* root)
    {
        while(root)
        {
            myStack.push(root);
            if(reverse == true)
            {
                root = root -> right;
            }
            else root = root -> left;
        }
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
       if(root == NULL) return false;
        //for next
        BSTIterator l(root, false);
        //for before
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        
        while(i < j)
        {
            if(i+j == k) return true;
            if(i+j < k) i = l.next();
            else j = r.next();
        }
        
        return false;
}

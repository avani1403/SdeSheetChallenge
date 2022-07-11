/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/
#include<bits/stdc++.h>
 bool valid(BinaryTreeNode<int>* root, long minVal, long maxVal) {
     if(root == NULL) return true;
     if(root -> data > maxVal || root -> data < minVal) return false;
     return valid(root -> left, minVal, root -> data) && valid(root -> right, root->data, maxVal);
    }
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
     return valid(root, LONG_MIN, LONG_MAX);
}

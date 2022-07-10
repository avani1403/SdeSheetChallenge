/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
       
    if(root == NULL)return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        for(int i=1;i<=s;i++){
            BinaryTreeNode<int>* temp=q.front();
            q.pop();
            if(i<s)temp->next=q.front();
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
    
    
   
    //NOT PASSING ALL TESTCASES
    
    
//     if(root == NULL) return ;
  
//     if(root->left != NULL and root -> right != NULL) root->left->next = root->right;
//     if(root->left != NULL and root -> right == NULL) 
//     //here as it's not perfect binary tree like leetcode qn we need to take care while  writing code
    
//     if(root->right != NULL && root->next != NULL && root -> next -> left != NULL) root->right->next = root->next->left;
//     if(root->right != NULL && root->next != NULL && root -> next -> left == NULL) root ->right -> next = root -> next -> right;
    
//     //recursive calls for left and right subtrees.
//     connectNodes(root->left);
//     connectNodes(root->right);
 
}

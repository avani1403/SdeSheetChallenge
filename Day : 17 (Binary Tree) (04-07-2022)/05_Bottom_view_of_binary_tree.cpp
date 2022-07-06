/*************************************************************
 
    Following is the Binary Tree node structure.

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
vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
     vector<int> res;
        if(root == NULL) return res;
        
        //map to store column value and it's bottom value
        map<int, int> bottom;
        
        queue<pair<int, BinaryTreeNode<int>*>> q;
        //column and node
        q.push({0, root});
        
        while(!q.empty()) {
            pair<int, BinaryTreeNode<int>*> temp = q.front();
            q.pop();
            
            bottom[temp.first] = temp.second -> data;
            if(temp.second -> left ) {
                q.push({temp.first - 1, temp.second->left });
            }
            if(temp.second -> right) {
                q.push({temp.first + 1, temp.second -> right});
            }
        }
        
        for(auto it: bottom) {
            res.push_back(it.second);
        }
        return res;
        
    
}

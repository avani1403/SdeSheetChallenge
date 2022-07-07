/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>

TreeNode<int>* build(vector<int> postorder, int postStart, int postEnd,       vector<int> inorder, int inStart, int inEnd, map<int, int> &inMap)
    {
        if(postStart > postEnd || inStart > inEnd ) return NULL;
        
        //creating new node
        TreeNode<int>* root = new TreeNode<int> (postorder[postEnd]);
        
        int inRoot = inMap[root -> data];
        int leftCnt = inRoot - inStart;
        
        root -> left = build(postorder, postStart, postStart+leftCnt - 1, inorder, inStart, inRoot - 1, inMap);
        
        root -> right = build(postorder, postStart+leftCnt, postEnd-1, inorder, inRoot + 1, inEnd, inMap);
        
        return root;
        
    }

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	    map<int, int> inMap;
        for(int i = 0; i<inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }
        
        TreeNode<int>* root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
}

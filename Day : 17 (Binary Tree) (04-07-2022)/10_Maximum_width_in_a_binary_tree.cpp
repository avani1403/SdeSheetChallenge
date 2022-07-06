/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
     if(root == NULL) return 0;
        int width = 0;
        queue<TreeNode<int>*> q;
        q.push(root);
        int len;
        while(!q.empty())
        {
             len = q.size();
            
            for(int i = 0; i<len; i++){
           
                TreeNode<int>* temp = q.front();
                q.pop();               
      
                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
            }
            width = max(width, len);
        }
        return width;
}

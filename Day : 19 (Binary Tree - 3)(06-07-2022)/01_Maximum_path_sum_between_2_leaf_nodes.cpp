/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

int cnt;
   long long int findSum(TreeNode<int> *root, long long int &maxi)
     {
        if(root == NULL) return 0;
       
        if(root -> left == NULL && root -> right == NULL) cnt++;
       
         //in case if we get -ve sum then we consider 0 
        long long int leftSum = findSum(root -> left, maxi);
        long long int rightSum = findSum(root -> right, maxi);
        
        maxi = max(maxi, root -> val + leftSum + rightSum);
        
        return root -> val + max(leftSum, rightSum);
     }
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
      
        if(root == NULL) return -1;
        cnt = 0;
    
        long long int maxi = 0;
        findSum(root, maxi);
        if(cnt == 1) return -1;
    
        return maxi;
}

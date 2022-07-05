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
int height(BinaryTreeNode<int>* root) {
        if(root == NULL) return 0;
        
        int left = height(root -> left);
        int right = height(root -> right);
        
        //these two statements state that it's not a balanced binary tree
          
         if(left == -1 || right == -1) return -1;
         if(abs(left-right) > 1) return -1;
          
        int maxi = max(left, right) + 1;
        
        return maxi;
    }
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    
        if(root == NULL) return true;
        int ans = height(root);
        if(ans == -1) return false;
        return true;
        
}

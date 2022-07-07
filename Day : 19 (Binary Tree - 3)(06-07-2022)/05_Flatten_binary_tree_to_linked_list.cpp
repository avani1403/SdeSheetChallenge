/************************************************************

    Following is the TreeNode class structure.

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
TreeNode<int> *p = NULL; 
void flatten(TreeNode<int>* root)
{
     
        if(root == NULL) return;
        
        //first we will go to right then left
        flatten(root -> right);
        flatten(root -> left);
        
        root -> right = p;
        root -> left = NULL;
        p = root ;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    p = NULL;
    flatten(root);
    return root;
}



 

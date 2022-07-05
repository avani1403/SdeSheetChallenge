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

int lowestCommonAncestor(TreeNode<int> *root, int p, int q)
{
	//    Write your code here
     //base case
    
        if(root == NULL ) return -1;
    
         if(  root->data == p || root->data == q)
            return root->data;
        
        int left =  lowestCommonAncestor(root -> left, p, q);
        int right = lowestCommonAncestor(root -> right, p, q);
        
        if(left == -1) return right;
        if(right == -1) return left;
        
        //it means left and right got returned with some value - we found the answer
        else return root -> data;
}

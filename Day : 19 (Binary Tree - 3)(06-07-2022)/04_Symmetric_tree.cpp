/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool checkSymmetric(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right)
{
        if(left == NULL)
            return left == right;
        if(right == NULL)
            return left == right;
        
        if(left -> data != right -> data) return false;
        
        bool check1 = checkSymmetric(left -> left, right -> right);
        bool check2 = checkSymmetric(left -> right, right -> left);
        
        return check1 && check2;
}


bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.   
    
    if(root == NULL) return true;
        
    return checkSymmetric( root -> left, root -> right);
}

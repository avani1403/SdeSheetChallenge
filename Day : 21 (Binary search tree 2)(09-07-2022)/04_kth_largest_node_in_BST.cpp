/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void traverse(TreeNode<int>* root, int &n)
{
    if(root)
    {
        traverse(root->left, n);
        n++;
        traverse(root->right, n);
    }
}
void inorder(TreeNode<int>* root, int k, int &cnt, int &ans)
{
    if(root)
    {
        inorder(root->left, k, cnt, ans);
        cnt++;
        if(cnt == k) ans =  root -> data;
        inorder(root->right, k, cnt, ans);
    }
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
     //Using recursion
    if(root == NULL) return -1;
    int cnt = 0;
    int ans;
    int n = 0;
    traverse(root, n);
    if(k > n) return -1;
    inorder(root, n-k+1, cnt, ans);
    return ans;
}

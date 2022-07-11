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
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    //Using recursion
    int cnt = 0;
    int ans;
    inorder(root, k, cnt, ans);
    return ans;
}

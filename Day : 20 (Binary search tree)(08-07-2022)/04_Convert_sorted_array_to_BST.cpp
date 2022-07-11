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

TreeNode<int>* helper(int s,int e,vector<int>&arr){
    if(s>e)return NULL;
    int mid=((e-s)/2)+s;
    TreeNode<int>* root= new TreeNode<int>(arr[mid]);
   root->left= helper(s,mid-1,arr);
    root->right=helper(mid+1,e,arr);
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return helper(0,arr.size()-1,arr);
}

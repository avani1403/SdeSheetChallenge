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
vector<int> getLeftView(TreeNode<int> *root)
{
    //    USING LEVEL ORDER TRAVERSAL
    if(root == NULL) return {};
    vector<int> ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()) {
        int n = q.size();
        for(int i = 1; i<=n; i++) {
            TreeNode<int> *temp = q.front();
            q.pop();
            //it means this is our first node in a level
            if(i == 1) {
                ans.push_back(temp -> data);
            }
            
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
    
    return ans;
    
    
}

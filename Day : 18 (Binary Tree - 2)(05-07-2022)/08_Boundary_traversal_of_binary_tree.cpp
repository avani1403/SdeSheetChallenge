/************************************************************

    Following is the Binary Tree node structure:
    
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
bool isLeaf(TreeNode<int>* root) {
    if(root -> left == NULL and root -> right == NULL) return true;
    return false;
}

void addLeftBoundary(TreeNode<int>* root, vector<int>& res) 
{
    root = root -> left;
    while(root)
    {
        if(!isLeaf(root)) res.push_back(root -> data);
        if(root -> left) root = root -> left;
        else root = root -> right;
    }
}

void addLeaves(TreeNode<int>* root, vector<int> &res) {
    //l n r - inorder traversal
     if(isLeaf(root)) 
    {
        res.push_back(root -> data);
        return;
    }
    if(root -> left) addLeaves(root -> left, res);
    
   
    
    if(root -> right) addLeaves(root -> right, res);
    
}

void addRightBoundary(TreeNode<int>* root, vector<int> &res) {
    vector<int> temp;
    root = root -> right;
    while(root)
    {
        if(!isLeaf(root)) temp.push_back(root -> data);
        if(root -> right) root = root -> right;
        else root = root -> left;
    }
    
    for(int i = temp.size()-1; i>=0; i--)
        res.push_back(temp[i]);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(root == NULL) return res;
    
    //adding root data
    if(!isLeaf(root)) res.push_back(root -> data);
    
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
    
    }

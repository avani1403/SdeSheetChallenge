/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void preOrder(TreeNode* root, vector<int>& values) {
        //N L R
        if(root == NULL) return;
        values.push_back(root -> val);
        preOrder(root->left, values);
        preOrder(root->right, values);
        
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        preOrder(root, values);
        return values;
    }
};

/************************************************************

    Following is the TreeNode class structure:

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
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
        vector<int> res;
        if(root == NULL) return res;
        
        //map to store column value and it's top value
        map<int, int> top;
        
        queue<pair<int, TreeNode<int>*>> q;
        //column and node
        q.push({0, root});
        
        while(!q.empty()) {
            pair<int, TreeNode<int>*> temp = q.front();
            q.pop();
            
            //if we encounter first top value then no need to encounter remaining
         
            int col = temp.first;
            //if not found then 
            if(top.find(col) == top.end()) 
            {
                top[col] = temp.second -> val;
            }
            
            if(temp.second -> left ) {
                q.push({temp.first - 1, temp.second->left });
            }
            if(temp.second -> right) {
                q.push({temp.first + 1, temp.second -> right});
            }
        }
        
        for(auto it: top) {
            res.push_back(it.second);
        }
        return res;
}

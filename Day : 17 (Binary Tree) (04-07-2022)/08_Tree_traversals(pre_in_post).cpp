/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<bits/stdc++.h>

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    //declare a stack which stores node and 1 2 3
    stack<pair<BinaryTreeNode<int>*, int>> st;
    st.push({root, 1});
    if(root == NULL) return {};
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    while(!st.empty()) 
    {
        auto curr = st.top();
        st.pop();
        
        if(curr.second == 1) 
        {
            //it means it's preorder
            pre.push_back(curr.first -> data);
            //then we have to increment
            curr.second++;
            st.push(curr);
            
            //now check if left exists or not
            if(curr.first -> left != NULL)
            {
                st.push({curr.first -> left, 1});
            }
        }
        else if(curr.second == 2)
        {
            //it means inorder
            in.push_back(curr.first -> data);
            //then we have to increment
            curr.second++;
            st.push(curr);
            
            //now check whether right exists or not
            if(curr.first -> right != NULL)
            {
                st.push({curr.first -> right, 1});
            }
        }
        else
        {
            //it means postorder
            post.push_back(curr.first -> data);
        }
    }
    
    vector<vector<int>> ans;
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}

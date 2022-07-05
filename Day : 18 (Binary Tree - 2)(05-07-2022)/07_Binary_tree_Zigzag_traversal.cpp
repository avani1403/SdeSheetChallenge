/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
      
        //using level order traversal
        if(root == NULL) return {};
        vector<int> result;
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            
            for(int i = 0; i<size; i++)
            {
               BinaryTreeNode<int>* temp = q.front();
                q.pop();
                
                //find position to fill node's value
                int index = (leftToRight) ? i : (size - 1 - i);
                
                row[index] = temp -> data;
                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
            }
            
            leftToRight = !leftToRight;
            for(int i = 0; i<size; i++)
            {
                result.push_back(row[i]);
            }
        }
        
        return result;
    
}

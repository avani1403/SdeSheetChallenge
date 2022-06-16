#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
      
        LinkedListNode<int> * temp = node;
        //edge case
        if(temp -> next == NULL) temp = NULL;
        temp -> data = temp -> next -> data;
        
        LinkedListNode<int> * to_delete = temp -> next;
        temp -> next = temp -> next -> next;
        to_delete -> next = NULL;
        delete to_delete;
}

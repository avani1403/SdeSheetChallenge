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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    // Write your code here.
    //using 2 pointers 
    if(head == NULL || k == 0) return head;
       if(k==1 && head -> next == NULL) return NULL;
        LinkedListNode<int>* dummy = new LinkedListNode<int>(-1);
        dummy -> next = head;
        LinkedListNode<int>* slow = dummy;
        LinkedListNode<int>* fast = head;
        for(int i = 0; i<k; i++)
        {
            fast = fast -> next;
        }
    //If fast would have reached NULL this means the node to be deleted 
    //is equal to the number of nodes in the linked list.   
        if(fast==NULL)
        {
            LinkedListNode<int>* node=head;
            head=head->next;
            delete node;
            return head;
        }
        while(fast != NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        LinkedListNode<int>* to_delete = slow -> next;
        slow -> next = slow -> next -> next;
        to_delete -> next = NULL;
        delete to_delete;
        return head;
        
}

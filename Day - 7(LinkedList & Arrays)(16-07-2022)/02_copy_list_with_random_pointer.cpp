#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
      // Write your code here.
    
    if(head==NULL){    
        return head;
    }
   
    // Inserting new nodes(copy nodes) in-between
    LinkedListNode<int> *curr = head;
    while(curr!=NULL){
        LinkedListNode<int> *temp = curr->next;
        curr->next = new LinkedListNode<int>(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
   
 
    curr = head;
    while(curr!=NULL){
        if(curr->next!=NULL){
            curr->next->random = curr->random!=NULL ? curr->random->next : NULL;
        }
         curr = curr->next->next;
    }
   
    // Separating both(original and copied) linked lists
    LinkedListNode<int> *orig = head;
    LinkedListNode<int> *copy = head->next;
    LinkedListNode<int> *ansHead = copy;
    while(orig!=NULL){
        orig->next = copy->next;
        copy->next = (copy->next!=NULL) ? copy->next->next : copy->next;
        orig = orig->next;
        copy = copy->next;
    }
   
    return ansHead;
}

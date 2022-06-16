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
LinkedListNode<int>* reverse(LinkedListNode<int>* head)
  {
      LinkedListNode<int>* prev = NULL;
      LinkedListNode<int>* curr = head;
      LinkedListNode<int>* forward = NULL;
      
      while(curr != NULL)
      {
     
          forward = curr -> next;
          curr -> next = prev;
          prev = curr;
          curr = forward;
      }
      return prev;
  }
bool isPalindrome(LinkedListNode<int> *head) {
    
   if(head == NULL) return true;
    if(head -> next == NULL) return true;
    //finding the middle
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head -> next;
    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    LinkedListNode<int>* toReverse = slow -> next;
    slow -> next = reverse(toReverse);
    LinkedListNode<int>* dummy = head;
    slow = slow -> next;
    
    while(slow != NULL)
    {
        if(slow -> data != dummy -> data) return false;
        slow = slow -> next;
        dummy = dummy -> next;
    }
    return true;
    

}

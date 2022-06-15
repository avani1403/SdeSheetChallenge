#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/

Node *findMiddle(Node *head) {
    if( head -> next == NULL) return head;
    if(head -> next -> next == NULL ) return head -> next;
    
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL)
    {
        slow = slow -> next;
        fast = fast -> next;
        if(fast != NULL) fast = fast -> next;
    }
    return slow;
}

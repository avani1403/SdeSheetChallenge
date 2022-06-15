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
 void insert(int d, Node* &head, Node* &tail)
    {
        Node* temp = new Node(d);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
       else { 
        tail -> next = temp;
        tail = temp;
       }
    }
Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
       Node* ansHead = NULL;
        Node* ansTail = NULL;
        int carry = 0;
        int val1;
        int val2;
        while(head1 != NULL || head2 != NULL || carry != 0)
        {
            val1 = 0;
            if(head1 != NULL) val1 = head1 -> data;
            val2 = 0;
            if(head2 != NULL) val2 = head2 -> data;
            
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum/10;
            
            insert(digit, ansHead, ansTail);
           if(head1 != NULL) head1 = head1 -> next;
           if(head2 != NULL) head2 = head2 -> next;
        }
        
        return ansHead;
}

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

Node *firstNode(Node *head)
{
	//    Write your code here.
     Node *slow = head;
      Node *fast = head;
        
        while(fast != NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
            if(fast != NULL) fast = fast -> next;
            if(slow == fast) break;
        }
        
        if(fast == NULL) return NULL;
        slow = head;
        
        while(slow != fast)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return slow;
}

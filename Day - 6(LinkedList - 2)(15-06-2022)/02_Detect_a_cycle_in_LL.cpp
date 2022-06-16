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

bool detectCycle(Node *head)
{
	   if(head == NULL) return 0;
        if(head -> next == NULL) return 0;
        Node *slow = head;
        Node *fast = head;
        
        //if slow  == fast then cycle is present
        
        while(fast != NULL && slow != NULL) {
            slow = slow -> next;
            fast = fast -> next;
            if(fast != NULL) fast = fast -> next;
            if(slow == fast ) return 1;
        }
        
        return 0;
}

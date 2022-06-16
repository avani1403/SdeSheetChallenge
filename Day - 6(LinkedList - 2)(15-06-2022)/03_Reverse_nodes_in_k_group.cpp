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
Node* reverseKGroup(Node* head, int n, int i, int b[]) {
     //using recursion
      
        //first we will reverse firts b[i] nodes then next nodes will be handled by recursion
     
    //edge case 
     if(i >= n) return head;
     if( b[i] == 0) return reverseKGroup(head , n, i+1, b);
    
    
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;
        int count = 0;
   
        while(curr != NULL && count < b[i])
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        
        if(forward != NULL) head -> next = reverseKGroup(forward, n, i+1, b);
        return  prev;
    }
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    int i = 0;
    return reverseKGroup(head, n, i, b);
}

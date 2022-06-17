#include <bits/stdc++.h> 
/********************************

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

********************************/
 int getLength(Node* head)
    {
        Node* temp = head;
        int count = 0;
        while(temp != NULL)
        {
            count++;
            temp = temp -> next;
        }
        return count;
    }

Node *rotate(Node *head, int k) {
       if(head == NULL ||  head -> next == NULL) return head;
        if(k == 0) return head;
        
        int len = getLength(head); 
        if(k % len == 0) return head;
        
        //for breaking the link
        int traverse = len - (k%len) - 1;
        Node* curr = head;
        
        while(traverse--)
        {
            curr = curr -> next;
        }
        
        Node* start = curr -> next;
        curr -> next = NULL;
        
        Node* temp = start;
        while(temp -> next !=  NULL)
        {
            temp = temp -> next;
        }
        temp -> next = head;
        
        return start;
}

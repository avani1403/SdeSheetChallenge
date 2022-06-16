#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* merge2lists(Node* a, Node* b)
{
    Node* temp = new Node(0);
    Node* rest = temp;
    
    while(a  != NULL && b != NULL)
    {
        if(a->data < b-> data)
        {
            temp -> child = a;
            temp = temp -> child;
            a = a-> child;
        }else {
            temp -> child = b;
            temp = temp -> child;
            b = b -> child;
        }
        
    }
    
    //after this one of the list will be remaining either a or b
    if(a) temp -> child = a;
    else temp -> child = b;
    
    //after that return head of this linked list
    return rest -> child;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head == NULL || head -> next == NULL) return head;
    
    //rec for list from right
    head -> next = flattenLinkedList(head -> next);
    
    //now merge
    
    head = merge2lists(head, head -> next);
    
    return head;
}

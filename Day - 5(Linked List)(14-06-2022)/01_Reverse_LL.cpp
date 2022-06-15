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

// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
// {
//     // Write your code here
// 	//empty list and 1 node case
// 	if(head == NULL || head -> next == NULL)
// 	{
// 		return head;
// 	}
// 	LinkedListNode<int>* prev = NULL;
// 	LinkedListNode<int>* curr = head;

// 	while(curr != NULL)
// 	{
// 		LinkedListNode<int>* forward = curr -> next;
// 	    curr -> next = prev;
// 		prev = curr;
// 		curr = forward;
// 	}
// 	return prev;
// }
void reverse(LinkedListNode<int>* &head,LinkedListNode<int> *curr,LinkedListNode<int> *prev)
{
	//base case - rukhna kab hai
	if(curr == NULL)
	{
		head = prev;
		return;
	}
	LinkedListNode<int> *forward = curr -> next;
	reverse(head, forward, curr);
	curr -> next = prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
 {
	LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    reverse(head,curr,prev);
	return head;
	
}


// Implement class for minStack.
#include<bits/stdc++.h>
class minStack
{
	// Write your code here.
    
	int mini;
	public:
		stack<pair<int, int>> st;
		// Constructor
		minStack() 
		{       
            mini = -1;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
            if(st.empty())
            {
                mini = num;
            }
            if(!st.empty())
            {
              mini = min(st.top().second, num);
            }
            st.push({num,mini});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if(st.empty()) return -1;
            int val = st.top().first;
            st.pop();
			return val;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
            if(!st.empty()) return st.top().first;
            return -1;
			
		}
		

		int getMin()
		{
            if(!st.empty()) return st.top().second;
            return -1;
		}
};

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<bits/stdc++.h>
int findCelebrity(int n) {
    
       //step 1: push all elements into the stack
        stack<int> s;
        for(int i = 0; i<n; i++) {
            s.push(i);
        }
        
        //step - 2: get 2 elements from the stack and compare them
        while(s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(knows(a,b)) s.push(b); //it means a knows b
            else s.push(a);
        }
        int candidate = s.top();
        //step - 3: now stack has single element - verify it
        bool rowCheck = false;
        int zeroCount = 0;
        for(int col = 0; col<n; col++) {
            if(M[candidate][col] == 0) zeroCount++;
        }
        
        if(zeroCount == n) //that means that full row has zeros
        {
            rowCheck = true;
        }
        
        bool colCheck = false;
        int oneCount = 0;
        
        for(int row = 0; row<n; row++) {
            if(M[row][candidate] == 1) oneCount++;
        }
        if(oneCount == n-1) { //because one zero is for diagonal so remaining n-1 1's
            colCheck = true;
        }
        
        if(rowCheck && colCheck) return candidate;
        return -1;
}

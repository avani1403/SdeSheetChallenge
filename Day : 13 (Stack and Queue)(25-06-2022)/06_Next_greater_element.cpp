#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
//     3  10  4  2  1  2  6  1  7
//NGE  10 -1  6  6  2  6  7  7  -1
    vector<int> nge(n , -1);
    stack<int> s;
    
    
    for(int i = n-1; i>=0; i--)
    {
        //removing all smaller elements
        if(s.empty())
        {
            nge[i] = -1;
            s.push(arr[i]);
            continue;
        }
        while(!s.empty() and s.top() <= arr[i])
        {
            s.pop();
        }
         if(s.empty())
        {
            nge[i] = -1;
            s.push(arr[i]);
            continue;
        }
        nge[i] = s.top();
        s.push(arr[i]);
        
    }
    return nge;
}

#include<bits/stdc++.h>
int kthLargest(vector<int>& arr, int n, int k)
{
    // Write your code here.
    priority_queue<int> pq;
    for(int i=0; i<n; i++)
    {
        pq.push(arr[i]);
    }
    for(int i=0; i<k-1; i++)
    {
        pq.pop();
    }
    return pq.top();
}

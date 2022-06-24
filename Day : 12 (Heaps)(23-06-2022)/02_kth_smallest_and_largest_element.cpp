#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{
	// Write your code here.
     priority_queue<int, vector<int>, greater<int>> pq;
     priority_queue<int> max;
        for(int i = 0; i<k; i++)
        {
            pq.push(nums[i]);
            max.push(nums[i]);
        }
        
        for(int i = k; i<n; i++)
        {
            if(nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
            if(nums[i] < max.top())
            {
                max.pop();
                max.push(nums[i]);
            }
        }
        vector<int> ans = {max.top(), pq.top()};
    return ans;
}

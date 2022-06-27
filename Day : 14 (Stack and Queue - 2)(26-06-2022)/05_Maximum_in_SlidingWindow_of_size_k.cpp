#include<bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    
    int n = nums.size();
        //deque stores in decreasing order
        deque<int> dq;
        vector<int> ans;
        //visiting first subarray
        for(int i = 0; i<k; i++)
        {
            while(!dq.empty() and nums[i] > dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        for(int i = k; i<n; i++)
        {
            //here we have to check if prev subarray ele is present in our deque
            if(dq.front() == nums[i-k])
            {
                dq.pop_front();
            }
            while(!dq.empty() and nums[i] > dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            
            ans.push_back(dq.front());
        }
        
        return ans;
        
}

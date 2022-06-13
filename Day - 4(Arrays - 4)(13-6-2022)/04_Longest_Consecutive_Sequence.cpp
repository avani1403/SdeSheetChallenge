#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
        if(n == 0) return 0;
         unordered_set<int> s(arr.begin(), arr.end());
       
        int maxi = 1;
        for(int i = 0; i<n; i++)
        {
            int len = 1;
            if(s.find(arr[i] - 1) == s.end())
            {
                // this is start point;
                //TC of find for unordered set is O(1)
                //now find next elements 
                int curr = arr[i];
   
                while(s.find(curr+1) != s.end())
                {
                    len++;
                    curr++;
                }
                maxi = max(maxi, len);
            }
        }
        return maxi;
}

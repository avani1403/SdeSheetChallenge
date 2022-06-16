#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map <int, int> mp;
    int curr = 0;
    int res = 0;
    int n = arr.size();
    mp[0]++;
    
    for(int i = 0; i<n; i++)
    {
        curr ^= arr[i];
        if(mp.count(curr^x)){
            res += mp[curr^x];
        }
        mp[curr]++;
    }
    return res;
}

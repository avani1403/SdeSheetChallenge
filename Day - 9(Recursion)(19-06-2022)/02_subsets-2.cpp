#include<bits/stdc++.h>

void solve(int i, vector<int> arr, vector<int> &subset, vector<vector<int>> &ans)
{
       ans.push_back(subset);
        for(int j = i; j<arr.size(); j++ )
        {
            if(j > i && arr[j] == arr[j-1]) continue;
            subset.push_back(arr[j]);
            solve( j+1, arr, subset, ans);
            subset.pop_back();                                                                
        }
}


vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> subset;
    sort(arr.begin(), arr.end());
    solve(0, arr, subset, ans);
    return ans;
    
}

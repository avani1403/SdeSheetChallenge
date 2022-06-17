#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
    if(n<3) return {};
    sort(arr.begin(), arr.end());
    for(int i = 0; i<n; i++)
    {
        if(i>0 and arr[i] == arr[i-1]) continue;
        int target = K - arr[i];
        int s = i+1;
        int e = n-1;
        while(s < e)
        {
            int sum = arr[s] + arr[e];
            if(sum == target)
            {
                ans.push_back({arr[i], arr[s], arr[e]});
                s++;
                e--;
                while(s<e and arr[s] == arr[s-1]) s++;
                while(s<e and arr[e] == arr[e+1]) e--;
            }
            else if(sum < target) s++;
            else e--;
        }
        
    }
    return ans;
    
}

#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
//         string ans = "No";
//         set<vector<int>> store; //to store and remove duplicates
//         sort(nums.begin(), nums.end());
//         for(int i = 0; i<n; i++)
//         {
//             for(int j = i+1; j<n; j++)
//             {
//                 int new_target = target - nums[i] - nums[j];
                
//                 int low = j+1;
//                 int high = n-1;
//                 while(low < high)
//                 {
//                     if(nums[low] + nums[high ] == new_target)
//                     {
//                         ans = "Yes";
//                         break;
//                     }
//                     else if(nums[low] + nums[high] < new_target)
//                     {
//                         low++;
//                     }
//                     else high--;
//                 }
//             }
//         }
        
  
        
//         return ans;
    
    unordered_map<int, pair<int, int>> mpp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            mpp[sum] = {i, j};
        }
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int new_target = target - (arr[i] + arr[j]);
            
            if(mpp.find(new_target) != mpp.end())
            {
                pair<int, int> it = mpp[new_target];
                    int k = it.first;
                    int l = it.second;
                    
                    if(i != k && i != l && j != k && j != l)
                        return "Yes";
            }
        }
    }
    
    return "No";
    
    

}

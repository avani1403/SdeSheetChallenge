// #include<bits/stdc++.h>
// void solve(int i, int k, vector<int>& arr, vector<int> temp, vector<vector<int>> &ans, int sum )
// {
//     //base condition

//       if(i <= arr.size())
//       {
//           if(sum == k)
//           {
           
//               ans.push_back(temp);
//               return;
//           }
//       }
//     if(i > arr.size()) return;
    
//     sum += arr[i];
//     temp.push_back(arr[i]);
//     solve(i+1, k, arr, temp, ans, sum);
    
//     sum -= arr[i];
//     temp.pop_back();
//     solve(i+1, k, arr, temp, ans, sum);
    
// }

// vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
// {
//     vector<vector<int>> ans;
//         vector<int> temp;
//         int i = 0;
//        int sum = 0;
     
//         solve(i, k, arr, temp, ans, sum);
     
//         return ans;
// }




#include <bits/stdc++.h>

void helper(int i,int k,int sum,vector<int> a,vector<vector<int>> &ans,vector<int> &v){
    if(i<0){
        if(sum==k)
            ans.push_back(v);
        return;
    }
    helper(i-1,k,sum,a,ans,v);
    
    vector<int> temp(v);
    temp.push_back(a[i]);
    helper(i-1,k,sum+a[i],a,ans,temp);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> v;
    helper(n-1,k,0,arr,ans,v);
    
    for(auto &x:ans){
        reverse(x.begin(),x.end());
    }
    
    return ans;
}

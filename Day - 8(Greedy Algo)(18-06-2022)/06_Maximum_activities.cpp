#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &end) {
    // Write your code here.
    
        int n = start.size();
       
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({end[i],start[i]});
        }
        sort(arr.begin(),arr.end());
        int prev = arr[0].first;
         int count = 1;
        for(int i=1;i<n;i++){
            if(arr[i].second >= prev){
                count++;
                prev = arr[i].first;
            }
        }
        return count;
}

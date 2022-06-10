#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
     int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> temp = {
            intervals[0][0], intervals[0][1]
        };
        for(int i = 1; i<n; i++)
        {
            if(intervals[i][0] <= temp[1]) {
                temp[1] = max(temp[1], intervals[i][1]);
            }
            else{
                //i need to push this into answer and update the temp
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        
        //we need to push the last temp
        ans.push_back(temp);
        return ans;
}

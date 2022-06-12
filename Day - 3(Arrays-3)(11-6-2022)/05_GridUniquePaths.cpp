#include <bits/stdc++.h> 
 int solve(int currRow, int currCol, int m, int n, vector<vector<int>>& dp)
    {
      
       if(currRow == m-1 && currCol == n-1) return 1;
        if(currRow > m || currCol > n) return 0;
        
        if(dp[currRow][currCol] != -1) return dp[currRow][currCol];
        
        int ans1 = solve(currRow+1, currCol, m, n, dp);
        int ans2 = solve(currRow, currCol+1, m, n, dp);
        
        return dp[currRow][currCol] = ans1+ans2;
    }
    
    
    int uniquePaths(int m, int n) {
        
         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
         return solve(0, 0, m, n, dp);
    }


#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
   //using brute force TC: O(m*n)
    
 /* for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(mat[i][j] == target)
                return true;
        }
    }
    return false;
    */
    //using Binary Search
    
    int low = 0;
    int high = m*n-1;
    int col = n;
    while(low <= high)
    {
        int mid = low+(high-low)/2;
        int elem =mat[mid/col][mid%col];
        if(elem == target) return true;
        else if(elem < target) low = mid+1;
        else high = mid-1;
    }
    return false;
}

#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &A, int n)
{
    //using sum of elements and sorting
//TC: O(nlogn) SC: O(1)
   /*  n = A.size();
    sort(A.begin(), A.end());
    pair<int, int> ans;
    for(int i = 0; i<n-1; i++)
    {
        if(A[i] == A[i+1]) ans.second = A[i];
    
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i<n; i++)
    {
            sum1 += A[i];
            sum2 += (i+1);
    }
    ans.first = sum2 - sum1 + ans.second;
    return ans; 
*/	
    
    //2nd Approach: using freq array TC: O(N) SC:O(N)
/*   pair<int, int> ans;
    vector<int> freq(n,0);
    for(int i = 0; i<n; i++)
    {
        freq[A[i] - 1]++;
    }
    
    for(int i = 0; i<n; i++)
    {
        //missing element
        if(freq[i] == 0) ans.first = i+1;
        else if(freq[i] > 1) ans.second = i+1;
    }
    return ans;
   
 */   
    //3rd approach: Sign Trick
   pair<int, int> ans;
    for(int i = 0; i<n; i++)
    {
        int x = abs(A[i]) - 1;
        if(A[x] < 0){
            //repeating number
            ans.second  = x+1;
        }
        else{
            //make it negative
            A[x] = -1*A[x];
        }
    }
    
    for(int i = 0; i<n; i++)
    {
        if(A[i] > 0) ans.first = i+1;
    }
    return ans;
}

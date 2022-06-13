#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
  int store[256] = {0};
        int n = input.size();
        if( n == 1) return 1;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r<n)
        {
            store[input[r]]++;
            while(store[input[r]] > 1)
            {
                store[input[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
}

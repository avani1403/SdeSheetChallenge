#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    sort(arr.begin(), arr.end());
    string s1 = arr[0];
    string s2 = arr[n-1];
    string ans = "";
    for(int i = 0; i<s2.size(); i++)
    {
        if(s1[i] == s2[i])
        {
            ans += s1[i];
        }else break;
    }

return ans;
    }

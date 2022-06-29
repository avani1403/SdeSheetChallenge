#include<bits/stdc++.h>
vector<int> stringMatch(string &str, string &pat) {
    
    int n = str.size();
    int m = pat.size();
   int x = n-m+1;
    vector<int> ans;
    for(int i = 0; i<=x; i++)
    {
        if(str.substr(i, m) == pat)
            ans.push_back(i);
    }
    return ans;
}

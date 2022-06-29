#include<bits/stdc++.h> 

int next(int price, stack<pair<int, int>> &s) {
        int res = 1;
        
        while(!s.empty() and s.top().first <= price) 
        {
            res += s.top().second;
            s.pop();
        }
        
        s.push({price, res});
        return res;
    }

vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    vector<int> ans;
    stack<pair<int, int>> s;
    for(int i = 0; i<n; i++)
    {
        int span = next(price[i], s);
        ans.push_back(span);
    }
    return ans;
}

#include <bits/stdc++.h>
bool  comp(pair<int,int> a , pair<int, int> b)
{
    //profit / weight
    
    double first = (double)a.second/(double)a.first;
    double second = (double)b.second/(double)b.first;
    
    return first > second;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    //first we are sorting on the basis of maximum p / w value
    
    sort(items.begin(), items.end(), comp);
    int maxweight = 0;
    double ans = 0;
    for(int i = 0; i<n; i++)
    {
        // weight, value
        if(maxweight +  items[i].first <= w)
        {
            maxweight += items[i].first;
            ans += items[i].second;
        }else 
        {
            int remain = w - maxweight;
            ans += 
                ((double)items[i].second / (double)items[i].first)
                * (double)remain;
            break;
        }
        
    }
    
    return ans;
}

#include<bits/stdc++.h>

struct meeting
{
    int start;
    int finish;
    int pos;
};
bool comp(struct meeting arr1, struct meeting arr2)
{
    if(arr1.finish < arr2.finish) return true;
    else if(arr1.finish > arr2.finish) return false;
    else if(arr1.pos < arr2.pos) return true;
    return false;
}
vector<int> maximumMeetings(vector<int> &first, vector<int> &end) {
    // Write your code here.
    int n = first.size();
    //first we will store it in a datastructure
    struct meeting meet[n];
    
    for(int i = 0; i<n; i++)
    {
        meet[i].start = first[i];
        meet[i].finish = end[i];
        meet[i].pos = i+1;
    }
    
    //now we need to sort
    sort(meet, meet+n, comp);
    //to store answer
    
    vector<int> ans;
    //first meeting happens for sure
    ans.push_back(meet[0].pos);
    int endlimit = meet[0].finish;
    
    for(int i = 1; i<n; i++)
    {
        if(meet[i].start > endlimit)
        {
            ans.push_back(meet[i].pos);
            endlimit = meet[i].finish;
        }
    }
    return ans;
}

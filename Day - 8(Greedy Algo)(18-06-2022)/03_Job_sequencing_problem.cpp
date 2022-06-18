#include<bits/stdc++.h>
bool comp(vector<int> a, vector<int> b)
{
    return a[1] > b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    //deadline, profit
    //first we need to sort it in descending order of profit
    sort(jobs.begin(), jobs.end(), comp);
    
    int n = jobs.size();
    
    //finding the maxDeadline
    int maxDeadline = 0;
    for(int i = 0; i<n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }
    
    //to store jobs id which ever has done
    vector<int> jobId(maxDeadline+1,-1); //becuase we r taking 1 based indexing
    int maxProfit = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = jobs[i][0]; j>0; j--) 
            //we will go till 1st deadline and check
        {
            if(jobId[j] == -1)
            {
                jobId[j] = jobs[i][0];
                maxProfit += jobs[i][1];
                break;
            }
        }
    }
    
    return maxProfit;
    
}

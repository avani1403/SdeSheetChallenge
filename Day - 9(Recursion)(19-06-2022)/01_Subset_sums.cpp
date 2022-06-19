void solve(int i,int sum, vector<int> arr, vector<int> &ans)
{
    if(i >= arr.size())
    {
        ans.push_back(sum);
        return;
    }
    
    sum += arr[i];
    solve(i+1, sum, arr, ans);
    
    sum -= arr[i];
    solve(i+1, sum, arr, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    solve(0, 0, num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

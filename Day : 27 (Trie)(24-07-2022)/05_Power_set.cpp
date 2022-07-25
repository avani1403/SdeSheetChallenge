void solve(vector<int>&v, vector<vector<int>>& ans,vector<int>& temp, int ind, int n){
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        solve(v, ans, temp, ind+1, n);

        int ele = v[ind];
        temp.push_back(ele);
        solve(v, ans, temp, ind+1, n);
        temp.pop_back();
    }
    vector<vector<int>> pwset(vector<int>v)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = v.size();
        solve(v, ans, temp, 0, n);
        return ans;
    }

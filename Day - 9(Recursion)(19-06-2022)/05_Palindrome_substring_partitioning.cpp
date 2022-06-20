 bool isPalindrome(int i, int j, string s)
    {
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

void solve(int ind, string s, vector<vector<string>> &ans, vector<string> substring)
    {
        if(ind >= s.size())
        {
           ans.push_back(substring);
            return;
        }
        
        for(int i = ind; i<s.size(); i++)
        {
            if(isPalindrome(ind, i, s))
            {
                substring.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, ans, substring);
                substring.pop_back();
            }
        }
        
    }
    
   

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
      vector<vector<string>> ans;
        vector<string> substring;
        string str = "";
        solve(0, s, ans, substring);
        return ans;
}

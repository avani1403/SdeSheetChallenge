#include<bits/stdc++.h>
string reverseString(string str)
{
    stack<string> st;
    int n = str.size();
    string word = "";
    for(int i = 0; i<n; i++)
    {
        if(str[i] == ' ') continue;
        while(i < n and str[i] != ' ')
        {
            word += str[i];
            i++;
        }
        st.push(word);
        word = ""; 
    }
    
    string ans;
    
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
        if(!st.empty()) ans += " ";
    }
    return ans;
}

string longestPalinSubstring(string str)
{
     int n = str.size();
        string res = "";
        int reslen = 0;
        
        for(int i = 0; i<n; i++)
        {
            //checking for oddlength
            int l = i;
            int r = i;
            while(l >= 0 and r < n and str[l] == str[r])
            {
                if(r-l+1 > reslen)
                {
                    reslen = r - l + 1;
                    res = str.substr(l, reslen);
                }
                
                l--;
                r++;
            }
            
    
            //for even length palindrome
            l = i;
            r = i+1;
            
            while(l >= 0 and r < n and str[l] == str[r])
            {
                if(r-l+1 > reslen)
                {
                    reslen = r - l + 1;
                    res = str.substr(l, reslen);
                }
                
                l--;
                r++;
            }
            cout<<endl;
            
        }
        return res;
}

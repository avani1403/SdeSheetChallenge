string writeAsYouSpeak(int n) 
{
	// Write your code here.	
    
     if(n == 1) return "1";
        if(n == 2) return "11";
        
        string ans = "11";
        
        
        for(int i = 3; i <= n; i++)
        {
            ans += '$';  //just to check last character
            string temp = ""; //to store ans given n
            int count = 1;
            
            //now finding counts for ans string and storing in temp varibale
            for(int j = 1; j<ans.size(); j++)
            {
                if(ans[j] == ans[j-1]) count++;
                else
                {
                    //first we have to add the count then add character
                    
                    temp += to_string(count);
                    temp += ans[j-1];
                    count = 1;
                }
            }
            
            ans = temp;
        }
        
        return ans;
}

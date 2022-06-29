int atoi(string str) {
      // Write your code here.
   
    int i = 0;
    int ans = 0;
    int sign = 1;
  
    if(str[i]=='-'){
        sign = -1;
        i++;
    }

    for(;i<str.length();i++)
    {
        if(str[i]-'0'>=0 && str[i]-'0'<=9)
        {
            ans=ans*10+str[i]-'0';
        }
    }
    return ans*sign;
}

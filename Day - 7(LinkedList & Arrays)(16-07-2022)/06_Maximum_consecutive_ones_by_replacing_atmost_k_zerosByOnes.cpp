int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
// 1 0 0 1 1 0 1
        int maxi = 0;
        int power = k;
        int count = 0;
        int s = 0;
        int e = 0;
    
       while(e < n  && s < n )
        {
            if(arr[e] == 1){
                //count++;
                 maxi = max(e-s+1, maxi);
                e++;
               
            }
            else if(arr[e] == 0 && power > 0)
            {
              // count++;
                  maxi = max(e-s+1, maxi);
                e++;
                power--;
              
            }
           else 
           {
              if(arr[s] == 0)
              {
                if(power < k)  power++;
               
              }
              s++; 
           }
                
            
        }
     
        return maxi;
}

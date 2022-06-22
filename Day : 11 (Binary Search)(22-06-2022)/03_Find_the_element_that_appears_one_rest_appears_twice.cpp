int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    
     //using map we can do
        //using iteration 
        //using BINARY SEARCH
        
  
        if(n == 1) return arr[0];
        //boundary checks
        if(arr[0] != arr[1]) return arr[0];
        else if (arr[n-1] != arr[n-2]) return arr[n-1];
        else 
        {
            //pair always starts at even index and end at odd index
            int low = 0;
            int high = n-1;
            
            while(low <= high) {
                
                int mid = low + (high - low)/2;
                
                //checking if it's unique element
                if(arr[mid] != arr[mid-1]  &&  arr[mid] != arr[mid+1])
                {
                    return arr[mid];
                }
                    
                if(mid&1) //odd index 
                {
                    if(arr[mid] == arr[mid-1]) low = mid + 1;
                    else high = mid - 1;
                }
                
                else //even index
                {
                    if(arr[mid] == arr[mid+1]) low = mid + 1;
                    else high = mid - 1;
                }
                
            }
            
        }
        return 0;
}

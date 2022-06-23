
#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // 1 3 4 7 10 12
    // 2 3 6 15
    
    //after merging - 1 2 3 3 4 | 6 7 10 12 15
    //now we know that first 5 are 1 3 4 from l1  and 2 3 from l2
    
    //max(l1, l2) is 4 
   // l1 <= r2   and l2 <= r1  should be
    /*  now let's check by picking  5 elements
    1st assumption :   1           |   3 4 7 10 12
                       2 3 6 15    |    ---
                       but we know that left half should be less than right half
    2nd assumption :  1 3         |    4 7 10 12
                      2 3 6       |    15  
                      this is also not correct
    3rd assumption : 1 3 4        |   7 10 12
                     2 3          |   6 15
    */   
    
    if(m > n)
    {
        return ninjaAndLadoos(row2, row1, n, m, k);
    }
    int low = max(0, k - n) , high = min(k, m);
    while(low <= high)
    {
        int cut1 = low + (high - low)/2;
        int cut2 = k - cut1;
        
        int l1 = cut1 == 0 ? INT_MIN : row1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : row2[cut2 - 1];
        int r1 = cut1 == m ? INT_MAX : row1[cut1];
        int r2 = cut2 == n ? INT_MAX : row2[cut2];
        
        if(l1 <= r2 && l2 <= r1)
        {
            return  max(l1, l2);
        }
        else if(l1 > l2)
        {
            high = cut1 - 1;
        }
        else low = cut1 + 1;
    }
    return 1;
}

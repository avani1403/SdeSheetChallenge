#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //edge cases
    if(n == 0 || n == 1) return permutation;
    //linearly traversing from back 
    int ind1;
    for( ind1 = n-2; ind1 >= 0; ind1--)
    {
        //whenever we find index which is p[ind1] < p[ind+1] break
        if(permutation[ind1] < permutation[ind1 + 1]) break;
    }
    
    //if there is no breakpoint 
    if(ind1 < 0) reverse(permutation.begin(), permutation.end());
    else{
        
        for(int ind2 = n-1; ind2 >= 0; ind2--)
        {
            if(permutation[ind2] > permutation[ind1]){
                swap(permutation[ind2], permutation[ind1]);
                break;
            }
        }
        
        //last step:
        reverse(permutation.begin()+ ind1+ 1, permutation.end());
        
    }
    return permutation;
}

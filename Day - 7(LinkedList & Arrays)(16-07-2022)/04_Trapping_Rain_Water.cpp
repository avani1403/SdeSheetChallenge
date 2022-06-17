#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long l = 0;
    long r = n-1;
    long maxL = arr[0];
    long maxR = arr[n-1];
    long units = 0;
    long unit;
    while(l < r)
    {
        if(maxL < maxR)
        {
            l++;
            unit = maxL - arr[l];
            if(unit <= 0) units += 0;
            else units += unit;
            maxL = max(maxL, arr[l]);
        }else
        {
            r--;
            unit = maxR - arr[r];
            if(unit <= 0) units += 0;
            else units += unit;
            maxR = max(maxR, arr[r]);
        }
        
    }
    return units;
    
    
}

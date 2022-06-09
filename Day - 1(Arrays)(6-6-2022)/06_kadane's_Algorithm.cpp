#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    //empty array
    if(n == 0) return 0;
    long long currSum = 0;
    long long  maxSum = arr[0];
    
    for(int i = 0; i<n; i++)
    {
        if(currSum < 0) currSum = 0;
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
    }
    if(maxSum < 0) return 0;
    return maxSum;
}

#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    int candidate = 0;
    int count = 0;
    
    for(int i = 0; i<n; i++)
    {
        if(count == 0) candidate = arr[i];
        if(arr[i] == candidate ) count++;
        else count--;
    }
    count = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == candidate) count++;
    }
    if(count <= n/2) return -1;
    return candidate;
}

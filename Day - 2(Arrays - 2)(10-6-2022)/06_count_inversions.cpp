#include <bits/stdc++.h> 
long long merge(long long *arr, long long temp[], 
               int left, int mid, int right)
{
    int i = left, j = mid, k = left;
    long long inv_count = 0;
    
    while((i <= mid - 1) && (j <= right))
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
            
            inv_count += (mid - i);
        }
    }
    
    while(i <= mid - 1)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    
    while(j <= right)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    
    for(int l = left; l <= right; l++)
    {
        arr[l] = temp[l];
    }
    
    return inv_count;
}

long long merge_sort(long long *arr, long long temp[], 
                     int left, int right)
{
    long long inv_count = 0;
    if(left < right)
    {
        long long mid = left + (right - left) / 2;
        
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid + 1, right);
        
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    
    return inv_count;
}
long long getInversions(long long *arr, int n){
 
    //bruteforce - TC: O(n^2)
    /*int count = 0;
    for(int i = 0; i<n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[i] > arr[j]) count++;
        }
    }
    return count;
    */
    
  //2nd aprroach : Using merge sort
    //sorted array - o inversions
    //reverse sorted array - max inversions
    /*
    6 3 5 4 1 2
     break into 2 parts
     635    412
     63  5   41 2
    6  3  5   4   1  2
    now check 6>3 yes and return them in sorted order  (6,3)
    36 5
    check 3>5 no, move the pointer 6>5 yes (6,5)
    again sort the array and return
    356  now go to the right part and apply the same
   
   356 124 and check 3>1 it means it has 3 inversions because as they are sorted 
   if 3>1 ultimately 5>1 6>1
   now change the pointer to 2

    */
    long long temp[n] = {0};
    
    return merge_sort(arr, temp, 0, n - 1);

}


#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    //we have to make the partitions for maxheap and minheap then solve it
    //1 2 3 | 4 5 6 - for even
    // 1 2 3 | 4 5 - for odd
    //top of the max heap should always be less than top of the min heap
    
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    if(n == 0) return;
    
    maxheap.push(arr[0]);
    cout<<arr[0]<<" ";
    
    for(int i = 1; i<n; i++)
    {
        int elem = arr[i];
        if(maxheap.size() > minheap.size()) //it means it's already odd 
            //so we either need make even(means we have to add in minheap) or replace the data
        {
            if(maxheap.top() >= elem)  //replace //length is odd
                //and length becomes even
            {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(elem);
            }
            else{ 
                minheap.push(elem); //length becomes even  
            }
             cout<<(minheap.top() + maxheap.top())/2<<" ";
        }
        else //it means both partitions have same length and becomes odd
        {
            if(maxheap.top() >= elem)
            {
                maxheap.push(elem);
            }
            else
            {
                minheap.push(elem);
                maxheap.push(minheap.top());
                minheap.pop();
                
            }
             cout<<maxheap.top()<<" ";
         
        }
        
    }
    
    
    
}

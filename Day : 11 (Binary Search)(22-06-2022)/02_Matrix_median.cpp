// #include<bits/stdc++.h>
// int getMedian(vector<vector<int>> &matrix)
// {
//     // Write your code here.
//     vector<int> elem;
//     for(int i = 0; i<matrix.size(); i++) {
//         for(int j = 0; j<matrix[0].size(); j++) {
//             elem.push_back(matrix[i][j]);
//         }
//     }
//     sort(elem.begin(), elem.end());
//     int n = elem.size();
    
//     return elem[n/2];
    
// }



//2nd approcah : Using binary search

int LessThanOrEqualToMidInRow(vector<int>& row, int number)
{
    int low = 0;
    int high = row.size() - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(row[mid] <= number)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return low;
}
int getMedian(vector<vector<int>> &arr)
{
    // Write your code here.
    int row = arr.size();
    int col = arr[0].size();
    
    int low = 0;
    int high = 100001;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        int count = 0;
        for(int i = 0; i < row; i++)
        {
            count += LessThanOrEqualToMidInRow(arr[i], mid);
        }
        
        if(count <= (row * col) / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return low;
}

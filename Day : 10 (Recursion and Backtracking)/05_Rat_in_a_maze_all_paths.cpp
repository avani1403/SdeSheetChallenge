
// void solve(int i, int j , vector<vector<int> > &m, int n,  vector<vector<int>> &ans,  vector<vector<int>> &visited, int k)
// {
//     if(i == n-1 && j == n-1 ) {
//        visited[n-1][n-1] == 6;
//         vector<int> temp;
//         for(int i = 0; i<n; i++)
//             for(int j = 0; j<n; j++) {
//                 if(visited[i][j] == 6) visited[i][j] = 1;
//                 else visited[i][j] = 0;
//                 temp.push_back(visited[i][j]);
//             }
//         ans.push_back(temp);
//         return;
//       }
    
//     //3 conditions should be true 
//     // in this case 
//     // value 1, visited 1, inside the matrix
//     //downward
//     if(i+1 < n && visited[i+1][j] == 1 && m[i+1][j] == 1) {
//         visited[i][j] = 6;
        
//         solve(i+1, j, m, n, ans,  visited, k);
       
//         visited[i][j] = 1;
//     }
    
//     //left
//     if(j-1 >= 0 && visited[i][j-1] == 1 && m[i][j-1] == 1) {
//         visited[i][j] = 6;
      
//         solve(i, j-1, m, n, ans,  visited, k);
      
//         visited[i][j] = 1;
//     }
    
//     //right
//      if(j+1 < n && visited[i][j+1] == 1 && m[i][j+1] == 1) {
//         visited[i][j] = 6;
     
//         solve(i, j+1, m, n, ans, visited, k);
 
//         visited[i][j] = 1;
//     }
//     //upwards
//    if(i-1 >= 0 && visited[i-1][j] == 1 && m[i-1][j] == 1) {
//         visited[i][j] = 6;

//         solve(i-1, j, m, n, ans, visited, k);
    
//         visited[i][j] = 1;
//     }
// }

// vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
//     if(n == 1) return {{1}};
//     vector<vector<int>> ans;
//     vector<vector<int>> visited(maze.begin(), maze.end());
//     int k = 0;
//     if(maze[0][0] == 1) solve(0,0, maze, n, ans,  visited, k);
//     return ans;
      
// }


vector<vector<int>> ans;

void solve(int i, int j, vector<vector<int>>& temp, 
          vector<vector<int>>&arr)
{
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr.size()
      || arr[i][j] == 0 || temp[i][j] == 1)
    {
        return;
    }
    
    if(i == arr.size() - 1 && j == arr.size() - 1 && arr[i][j] == 1)
    {
        vector<int> ForPush;
        temp[i][j] = 1;
        
        for(int i = 0; i < temp.size(); i++)
        {
            for(int j = 0; j < temp.size(); j++)
            {
                ForPush.push_back(temp[i][j]);
            }
        }
        
        if(!ForPush.empty())
            ans.push_back(ForPush);
        
        //return;
    }
    
    temp[i][j] = 1;
    solve(i, j + 1, temp, arr);
    solve(i, j - 1, temp, arr);
    solve(i - 1, j, temp, arr);
    solve(i + 1, j, temp, arr);
    temp[i][j] = 0;
        
}
vector<vector<int> > ratInAMaze(vector<vector<int>>&arr, int n){
  // Write your code here.
    vector<vector<int>> temp;
    for(int i = 0; i < n; i++)
    {
        vector<int> ant;
        for(int j = 0; j < n; j++)
        {
            ant.push_back(0);
        }
        temp.push_back(ant);
    }
    
    solve(0, 0, temp, arr);
    
    return ans;
    
}



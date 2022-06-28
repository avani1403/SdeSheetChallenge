#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    if(grid.empty()) return 0;
    
        int oranges = 0;
        int minutes = 0;
        int rotten_by_me = 0;
        
        queue<pair<int, int>> rotten;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] != 0) oranges++;
                if(grid[i][j] == 2) rotten.push({i,j});
            }
        }
        
        //Right Left Upward Downward
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty())
        {
            int k = rotten.size();
            rotten_by_me += k;
            
            while(k--)
            {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i<4; i++) {
                    int nx  = x + dx[i];
                    int ny = y + dy[i];
                    
                    //if it's a rotten orange or empty cell then continue
                    
                    if(nx<0 || ny<0 || ny>=m || nx >= n || grid[nx][ny] != 1)  continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            
            if(!rotten.empty()) minutes ++;
        }
        
        return oranges == rotten_by_me ? minutes : -1;
}

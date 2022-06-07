#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	//optimal one 
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 1;
        int y = 1;
        
        for(int i = 0; i<n; i++)
        {
            //checking 0 is present in 1st row
            if(matrix[0][i] == 0) x=0;
        }
        for(int i = 0; i<m; i++)
        {
            if(matrix[i][0] == 0) y=0;
        }
        
        //inner matrix 
        for(int i = 1; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //now if we found any col = 0 make whole col as 0
        for(int j = 1; j<n; j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i = 1; i<m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        //now if we found any row = 0 make whole row as 0
        for(int i = 1; i<m; i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 1; j<n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(y == 0){
            //make 1st col as 0
            for(int i = 0; i<m; i++)
            {
                matrix[i][0] = 0;
            }
        }
        
        if(x == 0)
        {
            for(int j = 0; j<n; j++)
            {
                matrix[0][j] = 0;
            }
        }
}

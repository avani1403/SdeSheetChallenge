#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
     vector<vector<long long int>> p(n);
        for(int i = 0; i<n; i++)
        {
            p[i].resize(i+1);
            //we know that 1st and last col of a row is 1
            p[i][0] = 1;
            p[i][i] = 1;
            for(int j = 1; j<i; j++)
            {
                p[i][j] = p[i-1][j-1] + p[i-1][j];
            }
        }
        return p;
}

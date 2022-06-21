#include<bits/stdc++.h>

vector<vector<int>> ret;
    bool is_valid(vector<vector<int>> &board, int row, int col, int n){
        
        int duprow = row;
        int dupcol = col;
        
        //checking diagonal
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 1) return false;
            row--;
            col--;
         }
        
        col = dupcol;
        row = duprow;
        
        //checking on row - left side
        while(col >= 0) {
            if(board[row][col] == 1) return false;
            col --;
        }
        
        
        col = dupcol;
        row = duprow;
        
        //checking down diagonal
        while(row < n && col >= 0 ) {
            if(board[row][col] == 1) return false;
            col --;
            row ++;
        }
        
        return true;
        
    }
    void solve(vector<vector<int>> &board, int col, int n){
        // exit condition
        if(col == board.size()){
            vector<int> temp;
            for(int i = 0; i<n; i++)
                for(int j = 0; j<n; j++) temp.push_back(board[i][j]);
            ret.push_back(temp);
            return;
        }
        
        // iterate every possible position
        for(int row=0; row < n; ++row){
            
            if(is_valid(board, row, col, n)){
                // make decision
                board[row][col] = 1;
                // next iteration
                solve(board,col+1,n);
                // back-tracking
                board[row][col] = 0;
            }
        }
    }

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    // return empty if n <= 0
        if(n <= 0) return {{}};
        vector<vector<int>> board(n,vector<int>(n,0));
        solve(board,0,n);
        return ret;
}

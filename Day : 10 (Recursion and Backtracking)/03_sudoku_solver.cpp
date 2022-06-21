 bool isValid(int board[9][9], int row, int col, int k)
    {
        //checking in row, col, in 3*3 grid
        
        for(int i = 0; i<9; i++)
        {
            if(board[i][col] == k) return false;
            if(board[row][i] == k) return false;
            
            if(board[ 3*(row/3) + i/3 ][ 3*(col/3) + i%3 ] == k) return false;
        }
        return true;
    }


  bool solve(int board[9][9])
    {
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                
                if(board[i][j] == 0)
                {
                    for(int ch = 1; ch <= 9; ch++)
                    {
                        if(isValid(board, i, j, ch))
                        {
                            board[i][j] = ch;
                            if(solve(board) == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = 0;
                            }
                        }
                    }
                    
                    //means we have checked all digits 1 - 9 ..so no one is valid that's why false
                    
                    return false;
                }              
                
            }
        }
        return true;
    }
    
    

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solve(matrix);
}

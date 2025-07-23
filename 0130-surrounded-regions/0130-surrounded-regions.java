class Solution {
    
    // DFS function to mark safe 'O's connected to border
    public void dfs(char board[][], int r[], int c[], int x, int y){
        board[x][y] = 'N'; // Temporarily mark as 'N' (Not to be flipped)

        for(int i = 0; i < 4; i++){
            int nx = x + r[i]; // Next x-coordinate
            int ny = y + c[i]; // Next y-coordinate

            // Check bounds and only call DFS if cell is 'O'
            if(nx >= 0 && nx < board.length && ny >= 0 && ny < board[0].length && board[nx][ny] == 'O'){    
                dfs(board, r, c, nx, ny);
            }
        }
    }

    public void solve(char[][] board) {
        int n = board.length;
        int m = board[0].length;

        // Direction vectors: up, right, down, left
        int r[] = {-1, 0, 1, 0};
        int c[] = {0, 1, 0, -1};

        int sr = 0;       // start row
        int sc = 0;       // start col
        int er = n - 1;   // end row
        int ec = m - 1;   // end col

        // Step 1: Start DFS from border cells (top and bottom row)
        for(int i = sc; i <= ec; i++){
            if(board[sr][i] == 'O'){
                dfs(board, r, c, sr, i);
            }
            if(board[er][i] == 'O'){
                dfs(board, r, c, er, i);
            }
        }

        // Step 2: Start DFS from left and right column
        for(int i = sr; i <= er; i++){
            if(board[i][sc] == 'O'){
                dfs(board, r, c, i, sc);
            }
            if(board[i][ec] == 'O'){
                dfs(board, r, c, i, ec);
            }
        }

        // Step 3: Flip the board
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'N'){
                    board[i][j] = 'O'; // Restore safe region
                } else if(board[i][j] == 'O'){
                    board[i][j] = 'X'; // Flip surrounded 'O' to 'X'
                }
            }
        }

        return;
    }
}

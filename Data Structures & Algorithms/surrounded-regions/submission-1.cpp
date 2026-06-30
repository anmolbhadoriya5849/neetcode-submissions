class Solution {
public:

    void dfs(vector<vector<char>>& board, vector<vector<char>>& ans, int i, int j){
        if(board[i][j] == 'X' || ans[i][j]=='O'){
            return;
        }

        ans[i][j] = 'O';

        int del_row[] = {1,0,-1,0};
        int del_col[] = {0,-1,0,1};

        for(int d=0;d<4;d++){
            int nr = i + del_row[d];
            int nc = j + del_col[d];

            if(nr < board.size() && nr>=0 && nc < board[0].size() && nc>=0){
                if(board[nr][nc] == 'O'){
                    dfs(board,ans, nr, nc);
                }
            }

        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<char>> ans(n, vector<char>(m, 'X'));

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(board, ans, i, 0);
            }
            if (board[i][m - 1] == 'O') { 
                dfs(board, ans, i, m-1);
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                dfs(board, ans, 0, j);
            }
            if (board[n - 1][j] == 'O') {
                dfs(board, ans, n-1, j);
            }
        }

        board = ans;

    }
};

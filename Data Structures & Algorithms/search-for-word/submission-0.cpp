class Solution {
public:

    bool solve(vector<vector<char>>& board, int i, int j, int n, int m, string& word, int w){
        if(word.size() == w) return true;

        if(i>=n || i<0 || j>=m || j<0 || board[i][j] != word[w]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        int del_row[] = {-1,0,1,0};
        int del_col[] = {0,1,0,-1};

        for(int d=0;d<4;d++){
            int nr = i + del_row[d];
            int nc = j + del_col[d];

            if(solve(board,nr,nc,n,m,word,w+1)){
                return true;
            }
        }

        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    bool ans = solve(board,i,j,n,m,word, 0);
                    if(ans == true) return true;
                }
            }
        }

        return false;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, unordered_set<int>> mp;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                string key_for_row = "row" + to_string(i);
                string key_for_col = "col" + to_string(j);
                string key_for_box = "box" + to_string(i/3) + '-' + to_string(j/3);

                if(board[i][j] == '.') continue;

                if(!mp[key_for_row].count(board[i][j])){
                    mp[key_for_row].insert(board[i][j]);
                }
                else return false;

                if(!mp[key_for_col].count(board[i][j])){
                    mp[key_for_col].insert(board[i][j]);
                }
                else return false;

                if(!mp[key_for_box].count(board[i][j])){
                    mp[key_for_box].insert(board[i][j]);
                }
                else return false;
            }
        }

        return true;
    }
};

class Solution {
public:

    void dfs(vector<vector<bool>>& visited, vector<vector<char>>& grid, int row, int col){
        if(visited[row][col] || grid[row][col] == '0') return;

        visited[row][col] = true;

        if(row+1 < grid.size()){
            dfs(visited, grid, row+1, col);
        }
        if(row-1 >= 0){
            dfs(visited, grid, row-1, col);
        }
        if(col+1 < grid[0].size()){
            dfs(visited, grid, row, col+1);
        }
        if(col-1 >= 0){
            dfs(visited, grid, row, col-1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    dfs(visited, grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

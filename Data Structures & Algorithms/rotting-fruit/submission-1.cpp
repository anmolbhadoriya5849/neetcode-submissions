class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int notRO = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    notRO += 1;
                }
            }
        }

        int del_row[] = {1,0,-1,0};
        int del_col[] = {0,1,0,-1};
        int time = 0;

        while(!q.empty() && notRO!=0){
            int size = q.size();

            for(int i=0;i<size;i++){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                for(int d=0;d<4;d++){
                    int nr = row + del_row[d];
                    int nc = col + del_col[d];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        if(grid[nr][nc]==1){
                            notRO--;
                            grid[nr][nc]=2;
                            q.push({nr,nc});
                        }
                    }
                }
            }

            time++;
        }

        return notRO == 0 ? time : -1;
    }
};

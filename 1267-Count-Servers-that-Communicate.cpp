class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> count_row(m,0);
        vector<int> count_col(n,0);     

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    count_row[i]++;
                    count_col[j]++;
                }
            }
        }

        int count = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1 && (count_row[i]>1 || count_col[j]>1)) count++;
            }
        }
        return count;
    }
};
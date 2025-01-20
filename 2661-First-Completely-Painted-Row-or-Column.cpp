class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> map;
        int m = mat.size(); // Number of rows 
        int n = mat[0].size(); // Number of columns
        
        for(int i=0 ; i<m ;i++){
            for(int j=0 ; j<n ; j++){
                int key = mat[i][j];
                pair<int, int> p;
                p.first = i;
                p.second = j;
                map[key] = p;
            }
        }

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i=0 ; i<arr.size() ; i++){ 
            pair t = map[arr[i]];
            int x = t.first;
            int y = t.second;
            row[x]+=1;
            if(row[x]==n) return i;
            col[y]+=1;
            if(col[y]==m) return i;
        }
        return -1;
    }
};
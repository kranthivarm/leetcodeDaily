class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>ump;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)ump[mat[i][j]]={i,j};
        }
        vector<int>row(n),col(m);
        for(int i=0;i<arr.size();i++){
            row[ump[arr[i]].first]++;
            if(row[ump[arr[i]].first]==m)return i;
            col[ump[arr[i]].second]++;
            if(col[ump[arr[i]].second]==n)return i;                                
        }
        return 0;
    }
};
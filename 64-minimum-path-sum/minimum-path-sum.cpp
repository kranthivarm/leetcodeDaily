class Solution {
public:
    int minSum(vector<vector<int>>& grid,vector<vector<int>>& con,int i,int j){
        if(con[i][j]!=-1)return con[i][j];
        if(i==grid.size()-1 and j==grid[0].size()-1)return con[i][j]=grid[i][j];
        //boundary conditions;
        if(i==grid.size()-1){
            return con[i][j]=grid[i][j]+minSum(grid,con,i,j+1);
        }
        if(j==grid[0].size()-1){
            return con[i][j]=grid[i][j]+minSum(grid,con,i+1,j);
        }
         return con[i][j]=grid[i][j]+min(minSum(grid,con,i+1,j),minSum(grid,con,i,j+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>con(grid.size(),vector<int>(grid[0].size(),-1));
        return minSum(grid,con,0,0);
    }
};
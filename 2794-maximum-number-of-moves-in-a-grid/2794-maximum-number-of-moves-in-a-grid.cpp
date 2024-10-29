class Solution {
public:
    int recursion(vector<vector<int>>& grid,vector<vector<int>>&con,int i,int j){
        if(i>=grid.size() and j>=grid[0].size())return 0;
        if(con[i][j]!=-1)return con[i][j];
        int ma=-1;
        if(i+1<grid.size() and j+1<grid[0].size()){
            if(grid[i+1][j+1]>grid[i][j])
                ma=max(ma,recursion(grid,con,i+1,j+1))  ;
        }                
        if(j+1<grid[0].size()){
            if(grid[i][j+1]>grid[i][j])
                ma=max(ma,recursion(grid,con,i,j+1))  ;
        }                
        if(i-1<grid.size() and j+1<grid[0].size()){
            if(grid[i-1][j+1]>grid[i][j])
                ma=max(ma,recursion(grid,con,i-1,j+1))  ;
        }
        return ma==-1 ? 1 :con[i][j]=ma+1;
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),res=0;
        vector<vector<int>>con(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
            res=max(res,recursion(grid,con,i,0));
        return (res==0)?0:res-1;
    }
};
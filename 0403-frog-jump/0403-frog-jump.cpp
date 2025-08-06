class Solution {
public:
    bool canCross(vector<int>& stones) {        
        int n=stones.size();
        unordered_map<long long,int>ump;
        for(int i=0;i<n;i++)ump[(long long)(stones[i])]=i;
        vector<vector<bool>>con(n+1,vector<bool>(n+2));
        
        for(int i=n-1;i>-1;i--){           
            for(int j=n;j>-1;j--){//j is k;
                // if(i==)
                if(i==n-1)con[i][j]=true;
                else{
                    // bool x=false;
                    long long t=(long long)(stones[i]+j);                    
                    // if(ump.find(t)!=ump.end())x=x or con[ump[t]][j+1];
                    
                    // if(ump.find(t)!=ump.end())x=x or con[ump[t]][j];
                    
                    // if(ump.find(t)!=ump.end())x=x or con[ump[t]][j-1];
                    if(ump.find(t)!=ump.end()){
                        con[i][j]=con[ump[t]][j+1];
                        con[i][j]=con[i][j] or con[ump[t]][j];
                        if(j-1>=0)con[i][j]=con[i][j] or con[ump[t]][j-1];
                    }                    
                }
            }
        }
        return con[0][1];
    }
};
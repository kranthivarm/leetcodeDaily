class Solution {
public:
    vector<int>parent,rank;
    void intialise(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    void unionByRank(int a,int b){        
        int ap=findParent(a);int bp=findParent(b);          
        if(ap==bp)return ;
        if(rank[ap]<rank[bp]){
            parent[ap]=bp;//  assigning smaller to bigger ;            
        }
        else if(rank[bp]<rank[ap])parent[bp]=ap;
        else {
            parent[ap]=bp;
            rank[bp]++;
        }        
    }
    int findParent(int a){
        if(parent[a]==a)return a;
        return parent[a]=findParent(parent[a]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        intialise(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    unionByRank(i,j);
                }
            }
            //this is not part of union. to find result i need space iam just using 1st column
            isConnected[0][i]=0;
        }
        for(int i=0;i<n;i++)unionByRank(i,parent[i]);
        int res=0;
        for(int i=0;i<n;i++){
            cout<<i<<" "<<parent[i]<<"  -  ";
            if(isConnected[0][parent[i]]==0){
                res++;
                isConnected[0][parent[i]]=1;
            }
        }
        return res;
    }
};
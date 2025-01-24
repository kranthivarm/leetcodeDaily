class Solution {
public:
    vector<int>res;    
    bool recuu(vector<vector<int>>& g,int i,vector<int>&isTermAndVisit){
        //2 is for visited , 0 not terminal reachable 
        if(isTermAndVisit[i]==0 || isTermAndVisit[i]==2)return false;
        if(isTermAndVisit[i]==1)return true;
        isTermAndVisit[i]=2;
        for(int j=0;j<g[i].size();j++){
            if(!(recuu(g,g[i][j],isTermAndVisit))){
                isTermAndVisit[i]=0;
                return false;
            }
        }
        isTermAndVisit[i]=1;
        res.push_back(i);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {        
        res={};
        // return res;
        int n=g.size();        
        vector<int>isTermAndVisit(n,-1);
        for(int i=0;i<n;i++)
            bool x=recuu(g,i,isTermAndVisit);
        sort(res.begin(),res.end());
        return res;
    }
};
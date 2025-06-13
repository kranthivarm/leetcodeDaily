class Solution {
public:
    static bool comp(vector<int>&i,vector<int>&j){
        if(i[0]<j[0])return true;
        if(j[0]<i[0])return false;
        return (i[1]>=j[1]);
    }
    int maxEnvelopes(vector<vector<int>>& en) {
        sort(en.begin(),en.end(),comp);
        vector<int>lis;
        lis.push_back(0);        
        for(int i=1;i<en.size();i++){
            int lisN=lis.size();
            if(en[lis[lisN-1]][1]<en[i][1]){
                lis.push_back(i);
                continue;
            }
            int l=0,r=lisN-1,mi;
            while(l<=r){
                mi=(l+r)/2;
                if(en[lis[mi]][1]<en[i][1])l=mi+1;                
                else r=mi-1;
            }
            lis[l]=i;
        }
        return lis.size();
    }
};
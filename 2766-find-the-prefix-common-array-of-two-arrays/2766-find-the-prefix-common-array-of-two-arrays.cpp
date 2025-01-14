class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n=a.size();
        unordered_map<int,bool>one,two,common;
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            if(i-1>=0)res[i]=res[i-1];
            one[a[i]]=true;
            two[b[i]]=true;
            if(a[i]==b[i]){
                if(common[a[i]])continue;
                common[a[i]]=true;
                if(i-1>=0)res[i]++;
                else res[i]=1;
            }
            else{
                if(one[b[i]]){
                    if(common[b[i]])continue;
                    common[b[i]]=true;
                    if(i-1>=0)res[i]++;
                    else res[i]=1;
                    cout<<res[i];
                }
                if(two[a[i]]){
                    if(common[a[i]])continue;
                    common[a[i]]=true;
                    // if(res[i]>0)res[i]=1;
                    if(i-1>=0)res[i]+=1;
                    else res[i]=1;
                }
            }
        }
        return res;
    }
};
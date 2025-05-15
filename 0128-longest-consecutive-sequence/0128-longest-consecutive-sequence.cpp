class Solution {    
public:
    //// disjoint set 
    // vector<int>union,rank;    
    // void initialisation(int n){
    //     union.resize(n);
    //     rank.resize(n,1);
    // }
    int parentFind(int val,unordered_map<int,int>&parent){
        if(parent.find(val-1)==parent.end())return val;
        // parent[val-1]=parentFind(parent[val-1],parent);
        // return parent[val]=parent[val-1];  
        if(parent[val-1]!=val-1){
            parent[val-1]=parentFind(parent[val-1],parent);
            return parent[val]=parent[val-1];
        }
        return parent[val]=parentFind(val-1,parent);
    }
    // void union(){}
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        // intialisation(n);
        unordered_map<int,int>parent;
        for(int i=0;i<n;i++)parent[nums[i]]=nums[i];
        for(int i=0;i<n;i++){
            int x=parentFind(nums[i],parent);
        }
        int ma=0;
        // for(auto i:parent)
        // cout<<(i.first)<<" "<<(i.second)<<endl;
        for(int i:nums){
            int x;
            if(i<=0)x=abs(parent[i])-abs(i)+1;                        
            else{
                if(parent[i]<=0)x=abs(parent[i])+i+1;
                else x=i-parent[i]+1;
            }            
            ma=max(ma,x);
        }
        return ma;
    }
};
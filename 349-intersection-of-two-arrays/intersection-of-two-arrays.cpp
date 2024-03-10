class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>con;
        for(int i:nums1)mp[i]=-1;
        for(int i:nums2){
            if(mp[i]==-1){
                con.push_back(i);
                mp[i]=0;
            }
        }
        return con;
    }
};
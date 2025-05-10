class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s=0,s2=0;
        int n=nums1.size(),m=nums2.size(),cnt=0,cnt2=0;
        for(int i=0;i<min(n,m);i++){
            s+=nums1[i];
            s2+=nums2[i];
            if(nums1[i]==0)cnt++;
            if(nums2[i]==0) cnt2++;
        }
        for(int i=min(n,m);i<max(n,m);i++){
            if(nums1.size()>=nums2.size()){
                s+=nums1[i];
                if(nums1[i]==0)cnt++;
            }
            else {
                s2+=nums2[i];
                if(nums2[i]==0)cnt2++;
            }
        }
        // if(s==s2 and cnt==cnt2)return (s1+cnt);
        s+=cnt;
        s2+=cnt2;        
        if(s<s2 and cnt)return s2;
        else if(s2<s && cnt2)return s;
        else if(s==s2)return s;
        return -1;
    }
};
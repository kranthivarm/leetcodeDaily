class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i]==nums2[j])return nums1[i];

            if(nums1[i]<nums2[j]){
                // i++;
                int pre=nums1[i];                    
                while(i<nums1.size() and pre==nums1[i])i++;
            }
            else if(nums1[i]>nums2[j]){
                // j++;
                int pre=nums2[j];
                while(j<nums2.size() and pre==nums2[j])j++;
            }
        }
        return -1;
    }
};
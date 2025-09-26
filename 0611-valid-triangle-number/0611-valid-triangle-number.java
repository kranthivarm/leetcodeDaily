class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int res=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0)continue;
            for(int j=i+1;j<nums.length;j++){
                int l=i+2,h=nums.length-1,mi;                
                while(l<=h){
                    mi=(l+h)/2;
                    if(nums[mi]<(nums[i]+nums[j]))l=mi+1;
                    else h=mi-1;
                }
                res+=(l-j-1);
            }
        }   
        return res;     
    }
}
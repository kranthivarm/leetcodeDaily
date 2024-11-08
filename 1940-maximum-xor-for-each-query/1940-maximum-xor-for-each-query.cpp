class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x=0,ma=(1<<maximumBit)-1,t,n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]^x;
            x=nums[i];
        }//reversing nums;
        for(int i=0;i<n/2;i++)   {
            int t=nums[i];
            nums[i]=nums[n-i-1];
            nums[n-i-1]=t;
        }
        for(int i=0;i<nums.size();i++){
            x=nums[i],t=ma;
            int pow2=1,res=0;
            while(t){
                if(t%2!=x%2)res+=pow2;
                pow2*=2;
                x/=2;
                t/=2;
            }
            nums[i]=res;
        }
        return nums;
    }
};
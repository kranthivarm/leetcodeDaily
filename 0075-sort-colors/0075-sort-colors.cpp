class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int z=0,o=0,t=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         nums[z++]=0;
        //         o++;
        //         t++;
        //     }
        //     else if(nums[i]==1){
        //         nums[o++]=1;
        //         t++;                
        //     }
        //     else nums[t++]=2;
        // }
        int red=0,blue=0,white=0,i;
        for(i=0;i<nums.size();i++){
            if(nums[i]==0)red++;
            else if(nums[i]==1)white++;
            else if(nums[i]==2)blue++;
        }i=0;
        while(red) {
            nums[i++]=0;
            red--;
        }
        while(white){
            nums[i++]=1;
            white--;
        }
        while(blue){
            nums[i++]=2;
            blue--;
        }
    }
};
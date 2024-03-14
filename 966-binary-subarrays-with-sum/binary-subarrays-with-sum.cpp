class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {        
        unordered_map<int,int>mp;
        int preSum=0,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i])preSum++;
            mp[preSum]++;
            if(preSum==goal)res++;
        }        
        unordered_map<int,int>::iterator it;        
        for(it=mp.begin();it!=mp.end();it++){
            if(mp.find((it->first)+goal)!=mp.end()){
                if (goal==0)res+=(it->second)*(it->second -1)/2;
                else res+=(it->second)*(mp[it->first +goal]);
            }
        }
        return res;

        // vector<int>onesInd;        
        // int res=0,st=-1,end=-1,oneCnt=0,vectorINd=0;
        // if(goal==0){

        // }
        // //subarray start is st and end i;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]){
        //         oneCnt++;
        //         onesInd.push_back(i);
        //         if(oneCnt<goal)continue;
        //         if(st==-1){
        //             st=i;
        //             end=i;
        //         }
        //         else end=i;
        //         while(i<nums.size() and nums[i]==0)i++;
        //     }
        // }
    }
};
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)nums[i]=nums[i]*nums[i];
        sort(nums.begin(),nums.end());
        return nums;
        // int negEnd=-1,poSt=-1,zero=0,i=0;
        // while(i<nums.size() and nums[i]<0){
        //     negEnd=i;
        //     i++;
        // }
        // while(i<nums.size() and nums[i]==0){
        //     zero++;
        //     i++;
        // }
        // if(i<nums.size() and nums[i]>0)poSt=i;
        // vector<int>res;
        // for(i=0;i<zero;i++)res.push_back(0);
        
        // if(poSt==-1)poSt=nums.size()+1;
                
        // while(negEnd>-1 and poSt<nums.size()){    
        //     if(negEnd>-1 and poSt<nums.size()){
        //         if(nums[negEnd]*nums[negEnd]<=nums[poSt]*nums[poSt])res.push_back(nums[negEnd]*nums[negEnd--]);
        //         else res.push_back(nums[poSt]*nums[poSt++]);
        //     }
        //     else if(negEnd>-1)res.push_back(nums[negEnd]*nums[negEnd--]);
        //     else if(poSt<=nums.size()-1)res.push_back(nums[poSt]*nums[poSt++]);
        // }
        // return res;
    }
};
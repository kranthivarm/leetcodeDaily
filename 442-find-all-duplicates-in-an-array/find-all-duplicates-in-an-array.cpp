class Solution {
public:
    const int x=1000000;
    vector<int> findDuplicates(vector<int>& nums) {
        // int n=nums.size(),i;
        // vector<int>con(n,0),res;
        // for(i=0;i<n;i++){
        //     con[nums[i]-1]+=1;
        // }
        // for(i=0;i<n;i++){
        //     if(con[i]>1)res.push_back(i+1);
        // }
        // return res;



        //
        int i,n=nums.size();        
        vector<int>res;
        for(i=0;i<n;i++){
            //iam adding 10^6 to index of every duplicate of an element 
            nums[(nums[i]%x)-1] +=x;
        }
        for(i=0;i<n;i++){
            if(nums[i]/x>1)res.push_back(i+1);
        }
        return res;
    }
};
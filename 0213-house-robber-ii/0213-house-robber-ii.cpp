class Solution {    
public:
    int res(vector<int>& nums,vector<int>& con,int i,bool ptr){
        if(i>=nums.size() || (i==nums.size()-1 && ptr))return 0;
        if(con[i]!=-1)return con[i];
        return con[i]=nums[i]+max(res(nums,con,i+2,ptr),res(nums,con,i+3,ptr));
    }
    int rob(vector<int>& nums) {
        //tabulation below works
        if(nums.size()<4)return *max_element(nums.begin(),nums.end());       
        int n=nums.size();
        vector<int>con1(n,0),con2(n,0);
        con1[0]=nums[0],con1[1]=max(nums[1],nums[0]);
        con2[1]=nums[1],con2[2]=max(nums[1],nums[2]);
        for(int i=2;i<n-1;i++){
            con1[i]=max(con1[i-1],con1[i-2]+nums[i]);
        }
        for(int i=3;i<n;i++){
            con2[i]=max(con2[i-1],con2[i-2]+nums[i]);
        }        
        return max(con1[n-2],con2[n-1]);


        // //memozation
        // if(nums.size()<4)return *max_element(nums.begin(),nums.end());
        // vector<int>con(nums.size(),-1);
        // int x=res(nums,con,0,true);                
        // // fill(con.begin(),con,end,-1);
        // con.assign(nums.size(),-1);
        // return max(x,res(nums,con,1,false));
    }
};
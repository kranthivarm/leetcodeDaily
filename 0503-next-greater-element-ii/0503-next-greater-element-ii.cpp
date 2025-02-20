class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){                     
            while(st.size()>0 && nums[st.top()]<nums[i]){
                if(res[st.top()]==-1)res[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){           
            while(st.size()>0 && nums[st.top()]<nums[i]){
                if(res[st.top()]==-1)res[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
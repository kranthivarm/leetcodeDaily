class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,h=nums[n-1]-nums[0],mi;        
        while(l<h){  
            mi=(h+l)/2;            
            int cnt=0;
            for(int i=1;i<n;i++){
                if((nums[i]-nums[i-1])<=mi){
                    cnt++;
                    ++i;
                }
            }
            if(cnt>=p)h=mi;
            else l=mi+1;
        }
        return l;
    }
};
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // if(k==1){        
        // }
        multiset<long long>l,h;
        int kceil=(int)ceil(k/2);
        auto balance=[&](){
            int xl,xh;
            if((int)l.size()>kceil){
                xl=*prev(l.end());
                l.erase(prev(l.end()));
                h.insert(xl);
            }
            if((int)h.size()>k/2){
                xh=*h.begin();
                h.erase(h.begin());
                l.insert(xh);
            }
            if(l.empty() or h.empty())return;
            xl=*prev(l.end());
            xh=*h.begin();
            if(xl>xh){                
                h.erase(h.begin());
                h.insert(xl);
                l.erase(prev(l.end()));
                l.insert(xh);
            }
        };
        // sort(nums.begin(),nums.begin()+k);
        for(int i=0;i<k;i++){
            // if(l.size()<(int)(ceil(k/2)))l.insert(nums[i]);
            // else h.insert(nums[i]);
            if(l.empty())l.insert(nums[i]);
            else {
                if(*prev(l.end())>nums[i])l.insert(nums[i]);
                else h.insert(nums[i]);
            }
            // //balance
            balance();
           
        }
        vector<double>res;
        if(k%2)res.push_back((double)(*prev(l.end())));
        else res.push_back((((double)(*prev(l.end()))+(double)(*h.begin())))/2.0);

        for(int i=k;i<nums.size();i++){
            
            auto it = l.find(nums[i-k]);
            if(it!=l.end()){
                l.erase(it);
                l.insert(nums[i]);
            }
            else {
                it=h.find(nums[i-k]);
                if(it!=h.end()){
                    h.erase(it);
                    h.insert(nums[i]);
                }
            }
            //balance;
            balance();
            if(k%2)res.push_back((double)(*prev(l.end())));
            else res.push_back((((double)(*prev(l.end()))+(double)(*h.begin())))/2.0);
            
            balance();
        }
        return res;
    }
};


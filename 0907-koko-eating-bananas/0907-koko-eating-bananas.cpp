class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        long long  l=p[0],r=0,mi,res=0;
        for(int i:p)r=max(r,(long long)i);
        l=min(r/h,r);
        r=max(r/h,r);
        if(!l)l=1;        
        if(!r)r=1;        
        while(l<=r){
            mi=l+((r-l)/2);
            long long cnt=0;
            for(int i:p){
                cnt+=(i/mi);
                if(i%mi)cnt++;
            }          
            if(cnt<=h)r=mi-1;
            else l=mi+1;
        }
        return l;
    }
};
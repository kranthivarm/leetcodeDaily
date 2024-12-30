class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        if((long long)m*(long long)k>(long long )b.size())return -1;
        int h=b[0],l=b[0],mi;
        for(int i:b){
            h=max(i,h);
            l=min(i,l);
        }
        while(l<=h){
            mi=l+((h-l)/2);
            int cnt=0,res=0;
            bool ptr=false;
            for(int i:b){
                if(i<=mi)cnt++;
                else cnt=0;
                if(cnt==k){
                    res++;
                    if(res==m){
                        ptr=true;
                        break;
                    }
                    cnt=0;
                }
            }
            if(ptr)h=mi-1;
            else l=mi+1;
        }
        return l;
    }
};
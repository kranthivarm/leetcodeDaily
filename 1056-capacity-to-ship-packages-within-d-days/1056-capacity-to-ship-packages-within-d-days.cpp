class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int h=0,l,mi,ma=0;
        for(int i:w){
            h+=i;
            // minimum=min(i,minimum);
            ma=max(i,ma);
        }
        l=max(ma,h/d);
        // l=ma;
        while(l<=h){
            mi=l+((h-l)/2);
            // if(mi<ma){
            //     l=mi+1;
            //     continue;
            // }
            int cnt=1,s=0;
            for(int i:w){
                s += i;
                if(s > mi){
                    cnt++;
                    s = i;
                }
            }
            // cnt++;
            if(cnt>d){
                l=mi+1;
            }
            else h=mi-1;
        }
        return l;
    }
};
class Solution {
public:
    int splitArray(vector<int>& a, int k) {
        int h=0,br=0,l=0,mi;
        for(int i:a){
            h+=i;
            l=max(l,i);
        }
        while(l<=h  && br<=1000){
            br++;
            mi=l+((h-l)/2);
            int cnt=1,s=0;
            for(int i:a){
                if(s+i>mi){
                    s=i;
                    cnt++;
                }
                else s+=i;
            }
            if(cnt<=k)//mi big so cnt less than k            
                h=mi-1;
            else l=mi+1;
        }
        return l;
    }
};
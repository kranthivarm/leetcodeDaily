class Solution {
public:
    int elementSearch(int mi,vector<int>& c){
        for(int i=0;i<c.size();i++){
            if(c[i]>=mi)return c.size()-i;
        }
        return 0;
    }
    int hIndex(vector<int>& c) {
        
        //[100] answer 1 not 0 so below doesn't work

        // int mi,l=0,h=c.size()-1,pre=-1,n=c.size();
        // while(l<=h){
        //     // mi=l+(h-l)/2;
        //     mi=(l+h)/2;
        //     cout<<mi<<" ";
        //     if(c[mi]<=n-mi){
        //         // cout<<"-";
        //         pre=c[mi];
        //         l=mi+1;
        //     }
        //     else h=mi-1;            
        // }
        // return pre;
        int ma=0;
        for(int i:c)ma=max(i,ma);
        int l=0,h=ma,res=0,mi;        
        while(l<=h){
            mi=l+((h-l)/2);
            cout<<mi;
            int x=elementSearch(mi,c);
            if(mi<=x){
                res=max(res,mi);
                l=mi+1;                
            }
            else h=mi-1;
        }
        return res;
    }
};
/*
class Solution {
public:
int leftBinarySearch(vector<int>&c,int target,int i){
    int l=0,h=i,mi=i,mid;
    while(l<=h){
        mid=(l+h)/2;
        if(c[mid]==target){
            mi=min(mi,mid);
            h=mid-1;
        }
        else l=mid+1;//else will always c[mid]<target
    }
    return mi;
}
    int hIndex(vector<int>& c) {
        int l=0,h=c.size()-1,ma=-1,mid;
        while(l<=h){
            mid=(l+h)/2;
            if(c[mid]<=c.size()-mid-1){
                ma=max(ma,c[mid]);
                l=mid+1;
            }
            else{
                int x=leftBinarySearch(c,c[mid],mid);
                if(c[mid]<=c.size()-x-1){
                    ma=max(ma,c[mid]);
                    l=mid+1;
                }
                else {//to be done;

                }
            }
        }
        return ma;
    }
};
*/
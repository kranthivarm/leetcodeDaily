class Solution {
public:
    // void binary_search(vector<vector<int>>&res,int st,int end){
    //     int l=0,h=res.size()-1,mid;
    //     while(l<=h){
    //         mid=(l+h)/2;
    //         if(st>=res[mid][0] && st<=res[mid][1]){
    //             //..
    //         }
    //         else if(st<res[mid][0]) h=mid-1;
    //         else l=mid+1;
    //     }
    // }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>>res;
        res.push_back(points[0]);
        res[0].push_back(points[0][0]);
        res[0].push_back(points[0][1]);
        for(int i=1;i<points.size();i++){
            // binary_search(res,points[i][0],points[i][1]);            
            int j=res.size()-1,x=1;
            while(j>-1){
                if(points[i][0]>=res[j][0] and points[i][0]<=res[j][1]){
                    if(points[i][0]>=res[j][2] and points[i][0]<=res[j][3]){
                        res[j][2]=max(points[i][0],res[j][2]);
                        res[j][3]=min(points[i][1],res[j][3]);

                        res[j][0] = min(points[i][0],res[j][0]);
                        res[j][1] = max(points[i][1],res[j][1]);
                        // res[j][1]=points[i][1];
                        x=0;
                        break;
                    }
                    else j--;
                }
                else{
                    res.push_back(points[i]);
                    res[res.size()-1].push_back(points[i][0]);
                    res[res.size()-1].push_back(points[i][1]);
                    x=0;
                    break;
                }
                j--;
            }
            if(x){
                res.push_back(points[i]);
                res[res.size()-1].push_back(points[i][0]);
                res[res.size()-1].push_back(points[i][1]);
            }
        }
        for(int i=0;i<res.size();i++)cout<<res[i][0]<<' '<<res[i][1]<<endl;
        return res.size();
    }
};
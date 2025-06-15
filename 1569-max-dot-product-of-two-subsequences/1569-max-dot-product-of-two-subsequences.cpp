#define ll long long 
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<ll>>con(n+1,vector<ll>(m+1,INT_MIN));
        long long ma=INT_MIN;
        // for(int i=0;i<=n;i++)con[i][m]=0;
        // for(int i=0;i<=m;i++)con[n][i]=0;
        for(int i=n-1;i>-1;i--){
            for(int j=m-1;j>-1;j--){ 
                vector<ll>temp;               
                temp={con[i][j],((ll)nums1[i])*((ll)nums2[j]),con[i+1][j+1],con[i+1][j],con[i][j+1],((ll)nums1[i])*((ll)nums2[j])+con[i+1][j+1]};
                con[i][j]=*max_element(temp.begin(),temp.end());
                 // vector<int>temp;               
                // for(int k=j;k<m;k++){
                //     vector<int>temp={nums1[i]*nums2[k] ,con[i][j],con[i+1][k+1] , nums1[i]*nums2[k]+con[i+1][k+1]};
                //     con[i][j]=*max_element(temp.begin(),temp.end());                
                // }                
                // for(int k=i;k<n;k++){
                //     temp={con[i][j], nums1[k]*nums2[j], nums1[k]*nums2[j]+con[k+1][j+1], con[k+1][j+1]};                
                //     con[i][j]=*max_element(temp.begin(),temp.end());
                // }
                ma=max(ma,con[i][j]);
            }
        }
        return ma;
    }
};
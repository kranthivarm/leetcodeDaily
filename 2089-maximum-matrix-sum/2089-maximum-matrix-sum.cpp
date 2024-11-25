class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int mi=abs(matrix[0][0]),cnt=0;
        for(auto i:matrix){
            for(int j:i){
                // cout<<j;
                if(j<=0)cnt++;
                mi=min(mi,abs(j));                    
                sum+=abs(j);
            }
        }
        cout<<mi<<" cnt:"<<cnt<<" sum:"<<sum;
        return (cnt%2)?sum-(2*mi):sum;
    }
};
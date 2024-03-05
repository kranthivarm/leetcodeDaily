class Solution {
public:
    int recursion(int n,unordered_map<int,int>&con){
        // cout<<n<<" ";
        if(con[n]>0)return con[n];
        if(n%2)con[n]=recursion((3*n)+1,con)+1;
        else con[n]=recursion(n/2,con)+1;
        return con[n];
    }

    int getKth(int lo, int hi, int k) {  
        unordered_map<int,int>mp;
        mp[1]=0;
        mp[2]=1;
        priority_queue<pair<int,int>>pq;    
                        //power,integer
        for(int i=lo;i<=hi;i++){
            int x=recursion(i,mp);
            // cout<<i<<" "<<x<<" ";
            pq.push({-1*x,i});
        }
        int i=0,pre=-1,x=0;
        vector<int>samePower;
        while(!(pq.empty())){
            ++i;            
            if(pre==-1){
                x=0;
                pre=-1*pq.top().first;                
                samePower.push_back(pq.top().second);
            }
            else if(pre==-1*pq.top().first){
                x++;
                samePower.push_back(pq.top().second);
            }
            else {
                // samePower.erase(samePower.begin(),samePower.end());
                samePower.clear();
                x=0;
                pre=-1*pq.top().first;
                samePower.push_back(pq.top().second);
            }
            // cout<<pq.top().first<<" "<<pq.top().second;
            pq.pop();
            if(i==k){                
                while(!pq.empty() and -1*pq.top().first==pre){
                    samePower.push_back(pq.top().second);
                    pq.pop();
                }
                sort(samePower.begin(),samePower.end());
                //here x is the no of same power elements
                // cout<<x<<endl;
                // for(int i: samePower)cout<<i<<" ";
                return samePower[x];
            }
        }
        return 0;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //djkstra algo
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto i:times)mp[i[0]].push_back({i[1],i[2]});
        // for(auto i:mp[k])pq.push({i.second,i.first});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>con(n+1,INT_MAX);
        // vector<bool>visit(n+1);
        con[k]=0;
        con[0]=0;
        while(!pq.empty()){
            auto tp=pq.top();     
            // auto [curTime, node] = pq.top();       
            pq.pop();
            // if(visit[tp.second])continue;
            // visit[tp.second]=true;
            if(tp.first>con[tp.second])continue;
            for(auto i:mp[tp.second]){
                if(((tp.first)+i.second)<con[i.first]){
                    con[i.first]=(tp.first)+(i.second);
                    pq.push({con[i.first],i.first});
                }
            }            
        }
        int res=0;
        for(auto i:con){
            if(i==INT_MAX)return -1;
            res=max(res,i);
        }
        return res;
    }
};
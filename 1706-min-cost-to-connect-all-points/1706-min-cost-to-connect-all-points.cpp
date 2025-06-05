class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //primes algorithm
        int n=points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({0,0});
        vector<int>mstdis(n,INT_MAX);
        vector<bool>isVisit(n);
        int res=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int vert=pq.top().second;
            pq.pop();            
            if(isVisit[vert])continue;
            res+=dis;
            isVisit[vert]=true;
            for(int i=0;i<n;i++){
                if(isVisit[i])continue;
                int manhan=abs(points[vert][0]-points[i][0])+abs(points[vert][1]-points[i][1]);
                if(manhan<mstdis[i]){
                    mstdis[i]=manhan;
                    pq.push({manhan,i});
                }
            }
        }
        return res;
    }
};
// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         int min_cost = 0;
//         std::vector<bool> visited(n, false);
//         std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;  // {cost, vertex}
//         std::unordered_map<int, int> cache;
//         pq.push({0, 0});

//         while (!pq.empty()) {
//             auto edge = pq.top();
//             pq.pop();
//             int cost = edge.first;
//             int u = edge.second;

//             if (visited[u]) {
//                 continue;
//             }

//             visited[u] = true;
//             min_cost += cost;

//             for (int v = 0; v < n; v++) {
//                 if (!visited[v]) {
//                     int dist = std::abs(points[u][0] - points[v][0]) + std::abs(points[u][1] - points[v][1]);
//                     if (cache.find(v) == cache.end() || dist < cache[v]) {
//                         cache[v] = dist;
//                         pq.push({dist, v});
//                     }
//                 }
//             }
//         }

//         return min_cost;
//     }
// };
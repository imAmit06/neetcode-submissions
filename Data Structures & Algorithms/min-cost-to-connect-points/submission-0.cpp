class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> mst(points.size(), false);

        pq.push(make_pair(0, 0));
        int minCost = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if(!mst[u]) {
                mst[u] = true;
                minCost += cost;

                for(int v = 0; v<points.size(); v++) {
                    if(u != v) {
                        int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                        pq.push(make_pair(wt, v));
                    }
                }
            }
        }

        return minCost;
    }
};

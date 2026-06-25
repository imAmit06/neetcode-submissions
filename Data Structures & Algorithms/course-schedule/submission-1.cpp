class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &graph) {
        vis[src] = true;
        recPath[src] = true;

        for(int i=0; i<graph.size(); i++) {
            int u = graph[i][1];
            int v = graph[i][0];

            if(u == src) {
                if(!vis[v]) {
                    if (isCycle(v, vis, recPath, graph)) {
                        return true;
                    }
                } else {
                    if(recPath[v]) {
                        return true;
                    }
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for(int i=0; i<numCourses; i++) {
            if(!vis[i]) {
                if(isCycle(i, vis, recPath, prerequisites)) {
                    return false;
                }
            }
        }
        return true;
    }
};

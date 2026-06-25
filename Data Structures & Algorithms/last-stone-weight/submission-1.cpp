class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        pq.push(0);

        for(int i=0; i<stones.size(); i++) {
            pq.push(stones[i]);
        }

        while(pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x == y) continue;

            if(x < y) {
                pq.push(y-x);
            }
        }

        return pq.top();
    }
};

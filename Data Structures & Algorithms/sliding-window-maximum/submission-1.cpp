class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int K) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for(int i=0; i<K; i++) {
            pq.push(make_pair(nums[i], i));
        }

        ans.push_back(pq.top().first);

        for(int i=K; i<nums.size(); i++) {
            while(!pq.empty() && pq.top().second <= (i-K)) {
                pq.pop();
            }   

            pq.push(make_pair(nums[i], i));

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

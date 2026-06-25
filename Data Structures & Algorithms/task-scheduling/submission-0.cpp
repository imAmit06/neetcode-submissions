class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int maxFreq = 0;

        for(auto e : tasks) {
            mp[e]++;
            maxFreq = max(maxFreq, mp[e]);
        }

        int ans = (maxFreq-1)*(n+1);
        for(auto e : mp) {
            if(e.second == maxFreq)
                ans++;
        }
        int size=tasks.size();
        return max(ans, size);
    }
};

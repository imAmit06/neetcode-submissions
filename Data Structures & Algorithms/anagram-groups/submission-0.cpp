class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(int i=0; i<strs.size(); i++) {
            vector<int> freq(26, 0);
            for(char ch : strs[i]) {
                freq[ch - 'a']++;
            }

            string key = "";
            for(int x : freq) {
                key += to_string(x) + "#";
            }

            mp[key].push_back(strs[i]);
        }

        for(auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

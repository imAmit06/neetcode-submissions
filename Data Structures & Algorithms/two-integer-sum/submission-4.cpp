class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ans;
       unordered_map<int, int> m;

       for(int i=0; i<nums.size(); i++) {
        int comp = target - nums[i];

        if(m.count(comp)) {
            ans.push_back(m[comp]);
            ans.push_back(i);
            break;
        }

        m[nums[i]] = i;
       }

       return ans;
    }
};

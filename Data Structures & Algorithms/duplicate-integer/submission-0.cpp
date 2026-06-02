class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> m;   
        for(int i=0; i<nums.size(); i++) {
            if(m.contains(nums[i])) {
                return true;
            } else {
                m.insert(nums[i]);
            }
        }
        return false;
    }
};
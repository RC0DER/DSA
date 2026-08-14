class Solution {
public:
vector<vector<int>> res;
    void permutation(vector<int>& nums, int idx){
        if(idx >= nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i=idx; i<nums.size(); i++){
            if(used.find(nums[i]) != used.end()) continue;
            used.insert(nums[i]);
            swap(nums[i], nums[idx]);
            permutation(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int idx = 0;
        permutation(nums, idx);
        return res;
    }
};
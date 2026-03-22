class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int idx, vector<int>& nums, vector<int>& curr){
        res.push_back(curr);

        for(int i=idx; i<nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(i+1, nums, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        int idx = 0;
        backtrack(idx, nums, curr);
        return res;
    }
};
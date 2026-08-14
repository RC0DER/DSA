class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int idx, vector<int>& nums, vector<int>& curr){
        if(idx == nums.size()){
            res.push_back(curr);
            return;
        }
        // include
        curr.push_back(nums[idx]);
        backtrack(idx+1, nums, curr);
        curr.pop_back(); //backtrack
        // exclude
        int i = idx+1;
        while(i < nums.size() && nums[i] == nums[i-1]) i++;
        backtrack(i, nums, curr);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        int idx = 0;
        backtrack(idx, nums, curr);
        return res;
    }
};